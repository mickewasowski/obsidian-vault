---
aliases:
context:
  - "[[Work stuff]]"
---

# crypto vs non-crypto adv. chart issue

---

### What was the issue?

The crypto advanced chart was not loading, it was crashing.
We were not subscribing for the correct data, we were not providing the proper data to the subscription, the mapping of the data was wrong, the rendering logic was also wrong.

### What changes did we have to make and why?

The same ticker (e.g. BTC, ETH) can exist as both a stock/ETF and a crypto, and crypto data flows through a different pipeline than stocks. Nearly every issue below stems from one of those two facts.

#### Issue 1 — The chart loaded the wrong instrument (ETF data), and for dual‑ticker symbols it crashed

Symptom: opening the crypto advanced chart showed ETF data; for ETH (ETF and crypto) it crashed.
Cause: TVChartContainer resolved the company by bare ticker. Companies are stored keyed by ticker only, so a bare lookup returned companies[0] — often the wrong one. A non‑crypto chart holding a crypto company (no stockExchangeCode, countryDesignation: "CRYPTO ASSET") then blew up.
Fix: symbology‑aware resolution in TVChartContainer — detect crypto from the ?currency= param, then always pass an options object to the selector so it disambiguates: { symbology: CRYPTO } → the crypto company, { symbology: undefined } → the stock/ETF. Same for the getCompany fetch.
Why: without the symbology the lookup is ambiguous and order‑dependent; passing it makes the resolved company match how the chart is being rendered.

#### Issue 2 — Crypto never loaded any data (blank chart)

Symptom: perpetual loader / no data.
Cause: the advanced chart reads history from gateway.ohlcvData, populated by the MarketDataQuery endpoint — which serves stocks. Crypto history arrives via a different message type (CryptoQuoteDataSummary) into BigChartCache. So gateway.ohlcvData stayed empty for crypto.
Fix (several parts):

- subscriptionHelpers.ts — route crypto through a no‑exchange query (getCryptoMdsSymbol), and tag the crypto summary subscription with countryDesignation = CRYPTO PAIR (it was defaulting to US).
- types.ts — make stockExchangeCode optional (crypto has none).
- CryptoHelpers.getCryptoMdsSymbol — don't re‑pair a symbol that already carries its currency (no BTCEURUSD).
- TVChartContainer + helpers.mapSummaryRowsToOhlcvDataRows — read crypto history from BigChartCache and seed the datafeed's arrays from it.
  Why: crypto uses a separate data pipeline; the chart had to actually consume that pipeline instead of the stock one.

#### Issue 3 — Chart mounted but showed "No data here"

Symptom: widget rendered, no candles.
Cause: the datafeed's backfill did minuteData = [...gatewayState.minuteData.data], overwriting the seeded crypto bars with the empty crypto gateway array.
Fix: datafeed.getUpdatedHistoryData guard — only replace an array with gateway data when the gateway actually has data; otherwise keep the seeded bars.
Why: for crypto the gateway is empty, so the unconditional overwrite erased the real data.

#### Issue 4 — Intraday timeframes (1D/1W/1M) blank while 3M/1Y/5Y worked ← the key one

Symptom: daily‑resolution views showed data; intraday views were empty (confirmed by TradingView logs: 103 bars delivered but not plotted).
Cause: resolveSymbol gave crypto a stock trading session (0930-1600, America/New_York). TradingView hides bars outside the session — and 24/7 crypto bars are almost all outside 9:30–16:00 ET. Daily views aren't session‑gated the same way, so they showed.
Fix: datafeed.resolveSymbol — for crypto force session: '24x7' and timezone: 'Etc/UTC' (via an isCrypto flag).
Why: crypto trades 24/7 and must not inherit stock market hours, or the library refuses to plot the bars.

#### Issue 5 — 1M (hourly) timeframe still empty after the session fix

Symptom: everything rendered except the 1M/hourly view.
Cause: the widget captures the data arrays once at mount and is never rebuilt. With a relaxed gate it mounted on minute+day, often before the 1M (hourly) summary seeded chartHourData → the datafeed held an empty hourly array.
Fix: subscribe crypto to the OneMonth (1M1h) summary bucket, seed chartHourData from it, and require all three arrays (minute+hour+day) before mounting.
Why: since the datafeed can't be refreshed after mount, all the data it needs must be present at mount time.

#### Issue 6 — Failing market‑hours request for crypto

Symptom: non-working-days/with-market-hours?country=CRYPTO ASSET → 400.
Cause: the details page requested market hours for any company's countryDesignation; for crypto that's "CRYPTO ASSET", which the backend rejects.
Fix: SymbolDetails.tsx — skip the request when isCrypto.
Why: crypto has no market hours; the call is meaningless and errors.

#### Issue 7 — The currency feature (view vs USD/EUR, and remember it)

Need: some crypto have a USD/EUR switcher; that selection must reach the advanced chart and survive the round trip back.
Fix: TradeViewChartButton appends ?currency=; Overview passes selectedCurrency for crypto; TVChartContainer pairs the symbol with it; CryptoDisplayCurrencyCache + DisplayCurrencyContext remember the last currency per symbol; handleGoBack uses navigate(-1).
Why: the advanced chart is a separate route with no access to the details‑page state, so the currency must be transported (URL) and remembered (in‑memory cache).

Per‑file summary

| File | What changed | Fixes |
|---|---|---|
| `containers/TradingViewChart/TVChartContainer.tsx` | Detect crypto from the `?currency=` param; resolve/fetch the company with the matching symbology (crypto vs non‑crypto); pair the symbol with the selected currency; seed chart data from `BigChartCache` (1D/1M/3M ranges); require minute+hour+day before mounting; pass `isCrypto` to the datafeed; `navigate(-1)` on Go Back | Wrong instrument (ETF) / dual‑ticker crash; blank chart; blank intraday & 1M timeframes; currency carry‑over |
| `containers/TradingViewChart/datafeed.ts` | Guard so an empty gateway response can't wipe seeded bars; force `24x7` session + `Etc/UTC` timezone for crypto | "No data here"; blank intraday timeframes |
| `lib/store/market-data/subscriptionHelpers.ts` | Route crypto out of `advancedChartSubscription` (query by pair, no exchange code); tag the crypto summary subscription with `CRYPTO PAIR` (was defaulting to US) | Blank chart (crypto data mis‑routed/mis‑tagged) |
| `lib/util/CryptoHelpers.ts` | `getCryptoMdsSymbol` keeps an already‑paired symbol as‑is (no `BTCEURUSD`) | Blank chart (wrong pair symbol) |
| `lib/services/market-data-query/types.ts` | `stockExchangeCode` made optional | Blank chart (crypto has no exchange) |
| `containers/TradingViewChart/helpers.ts` | New `mapSummaryRowsToOhlcvDataRows` — maps summary‑cache rows into datafeed rows | Blank chart (consume `BigChartCache`) |
| `lib/store-util/CryptoDisplayCurrencyCache.ts` | New in‑memory per‑symbol currency cache | Selected currency remembered on return |
| `containers/SymbolDetails/DisplayCurrencyContext.tsx` | Read/write the currency cache | Selected currency remembered on return |
| `containers/SymbolDetails/Tabs/Overview/Overview.tsx` | Pass the selected currency to the chart button (crypto only) | Currency carry‑over |
| `components/Chart/TradingViewChartButton/TradeViewChartButton.tsx` | Append `?currency=` to the advanced‑chart link | Currency carry‑over |
| `containers/SymbolDetails/SymbolDetails.tsx` | Skip the market‑hours request for crypto | `country=CRYPTO ASSET` → 400 |
| `__tests__/` (4 files) | Tests for the mapper, `getCryptoMdsSymbol`, the crypto `advancedChartSubscription` path, and the currency cache | — |

Notable for the reviewer: datafeed.ts (the "don't touch" file) was changed minimally — only the empty‑gateway guard and the isCrypto 24×7 session. For non‑crypto everything is unchanged (no ?currency= → identical old code paths), and the existing datafeed tests still pass.

Known limitation (out of scope, per your call): the realtime last‑price label can show the wrong instrument's price for dual‑ticker symbols because TradePriceCache is keyed by bare ticker — a separate ticket.




##### Short summary

1. Reading from the wrong place — ✅ correct.
Crypto history is delivered via CryptoQuoteDataSummary → BigChartCache, but the advanced chart was reading gateway.ohlcvData (populated by MarketDataQuery, which serves stocks). So it was looking where crypto data never lands. Fix: seed the chart from BigChartCache.

2. Not identifying it as crypto — ✅ correct, but it's two distinct fixes at two layers:
- symbology: CRYPTO → used for company resolution (getCompany/selector). Without it, the same‑ticker ETF was resolved instead of the crypto (wrong data, and the dual‑ticker crash on ETH).
- countryDesignation on the summary subscription → so the CryptoQuoteDataSummary request is tagged as crypto instead of defaulting to a US market. One nuance: the value we send there is CRYPTO PAIR, not CRYPTO ASSET. (CRYPTO ASSET is the company's designation for the base asset like BTC; the summary subscription is tagged CRYPTO PAIR.)

3. Forcing stock market hours — ✅ correct.
resolveSymbol gave crypto a stock session (0930‑1600, America/New_York). TradingView received the bars but hid every one outside 9:30–16:00 ET — i.e. all of them for 24/7 crypto — so intraday views were blank. Fix: 24x7 + Etc/UTC for crypto.

4. Overwriting seeded data with empty gateway arrays — ✅ correct.
The datafeed's backfill did minuteData = [...gatewayState.minuteData.data]; for crypto the gateway is empty, so it wiped the bars we'd seeded → "No data here." Fix: the getUpdatedHistoryData guard (keep current data when the gateway is empty).

5. Not waiting for minute + hour + day — ✅ correct.
The gate was relaxed (minute+day), so the widget mounted before the hourly (1M) data seeded — and the datafeed captures its arrays once at mount and is never rebuilt — leaving the 1M/60 timeframe permanently empty. Fix: require all three before mounting (and seed the hourly range).






### Additional issue:

When you open the BTC ETF at the right where the price header is there is a live data (last price in pink rectangle) that is showing the price for the Crypto symbol.

**Why this happens?** -> because the TradePriceCache is keyed by bare ticker and the etf and crypto clobber each other.

**Solution** -> two approaches - one would only show the crypto data chart and hide it/stop painting it the etf data chart

    - seconde one would require the change of about 11 files: TradePriceCache is keyed by bare ticker, so crypto BTC and the BTC ETF overwrite each other's price everywhere, not just the chart (watchlists, tickers, order flow all read the same 'BTC' entry). Fixing it means re-keying the cache by ticker + exchange (crypto has none) and updating every reader to pass that key:

- TradePriceCache.ts — the keying + get/set/updateNewState/generateEmptyTradePrice.
- 10 files / 14 call sites that call TradePriceCache.get(...) — each must pass the exchange/symbology.
