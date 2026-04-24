---
aliases:
context:
  - "[[CSS]]"
---

# Marquee animation

---

1. Duplicating the content

In MarketIndexes.tsx we render the 5 cards twice — once in a real .track div, and once in an identical .track with aria-hidden. This doubles the DOM content so the total width of
.wrapper is always exactly 2 × one-track-width, regardless of how many items there are or how wide the container is.

---

2. The animation math

@keyframes marquee {
from { transform: translateX(0); }
to { transform: translateX(-50%); }
}

translateX is relative to the element's own width. Since .wrapper contains two identical tracks, its width = 2 × track. Moving by -50% moves it left by exactly 1 × track. At that point
the second track occupies the exact screen position where the first track started. The browser then loops the animation back to translateX(0) — and because the first and second tracks
are identical, there is no visible jump.

---

3. Why overflow doesn't matter

The parent .indexes has overflow: hidden. The browser clips anything outside its bounds. So even though .wrapper is double the container width and is being translated left
continuously, the user only ever sees the visible window. The illusion of infinite scrolling comes entirely from the loop being seamless — not from the content actually being infinite.

---

4. Why the tracks have no padding

Each .track has padding: 0. If they had horizontal padding, the gap at the track boundary (where track 1 ends and track 2 begins) would be bullet-margin-right + track1-padding-right +
track2-padding-left — wider than the gap between any two adjacent cards. Removing the padding makes every gap identical, including the loop point.

---

5. The separator on every card

.card::after {
content: "•";  
 margin: 0px 16px;
}

By applying this to all cards (not &:not(:last-child)), the last card of each track also gets a bullet. This means the junction between track 1 and track 2 has the same visual weight  
 as any other adjacent pair, keeping the loop visually seamless.

---

6. Gradient overlays

The ::before and ::after on .indexes are position: absolute with z-index: 1, fading the edges to the background colour. This hides the hard start and end of the scrolling content,
reinforcing the illusion that the ticker has no beginning or end.

``` html

<!DOCTYPE html>
  <html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Infinite Marquee Loop</title>
    <style>
      /* The clipping container — hides anything outside its bounds */
      .indexes {
        position: relative;
        width: 600px;
        overflow: hidden;
        background: #0d1b2a;
      }

      /* Fade the left and right edges to create the illusion of infinity */
      .indexes::before,
      .indexes::after {
        content: "";
        width: 60px;
        position: absolute;
        inset: 0;
        z-index: 1;
        pointer-events: none;
      }
      .indexes::before {
        background: linear-gradient(to right, #0d1b2a, transparent);
      }
      .indexes::after {
        left: calc(100% - 60px);
        background: linear-gradient(to left, #0d1b2a, transparent);
      }

      /*
        The animated element.
        Its total width = 2 × one track, so translateX(-50%)
        moves it left by exactly one track — landing the duplicate
        in the same position the original started from.
      */
      .wrapper {
        display: flex;
        align-items: center;
        animation: marquee 6s linear infinite;
      }
      .wrapper:hover {
        animation-play-state: paused;
      }

      /*
        Each track is one full copy of the content.
        No horizontal padding — keeps spacing uniform at the boundary.
      */
      .track {
        display: flex;
        align-items: center;
        flex-shrink: 0;
      }

      .card {
        display: flex;
        align-items: center;
        white-space: nowrap;
        color: #fff;
        font-family: sans-serif;
        font-size: 14px;
      }

      /* Bullet separator after every card, including the last */
      .card::after {
        content: "•";
        color: #666;
        margin: 0 16px;
      }

      @keyframes marquee {
        from { transform: translateX(0); }
        to   { transform: translateX(-50%); }
      }
    </style>
  </head>
  <body>
    <div class="indexes">
      <div class="wrapper">

        <!-- First copy (real content) -->
        <div class="track">
          <div class="card">S&amp;P 500 · 5,312.00 <span style="color:#4caf50">+0.82%</span></div>
          <div class="card">NASDAQ · 18,441.23 <span style="color:#f44336">-0.31%</span></div>
          <div class="card">DOW · 39,112.00 <span style="color:#4caf50">+0.54%</span></div>
        </div>

        <!-- Second copy (duplicate, purely visual) -->
        <div class="track" aria-hidden="true">
          <div class="card">S&amp;P 500 · 5,312.00 <span style="color:#4caf50">+0.82%</span></div>
          <div class="card">NASDAQ · 18,441.23 <span style="color:#f44336">-0.31%</span></div>
          <div class="card">DOW · 39,112.00 <span style="color:#4caf50">+0.54%</span></div>
        </div>

      </div>
    </div>
  </body>
  </html>
```
