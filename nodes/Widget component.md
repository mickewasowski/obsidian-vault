---
aliases:
context:
- "[[Hirarchical state machine]]"
---


# Widget component

This is the component in which I used the [[Hirarchical state machine]] implementation.

---

``` js
// Widget.tsx

import React, {memo, useEffect, useMemo, useState} from 'react';

import {Reward, Tournament} from '@pp-apps-libs/relay-types';
import {useTranslate} from '@pp-libs/i18n-react';

import {useTournamentsController} from '../../controllers/TournamentsController';
import {ModalTypes} from '../../controllers/TournamentsState';
import {useSelector} from '../../Store';
import {Layout} from '../../Types';

import './Widget.scss';

import {TrophyIcon} from '../Icons';
import useRotatingFace, {MainFace} from './hooks/useRotatingFace';
import useTournamentFace, {Faces} from './hooks/useTournamentFace';
import CupWidgetFace from './widget-faces/CupWidgetFace';
import EndsInContent from './widget-faces/EndsInContent';
import UserPosition from './widget-faces/UserPosition';

const WIDGET_CONSTANTS = {
    ROTATE_ONCE_A_MINUTE: 50_000,
    ROTATE_TWICE_A_MINUTE: 30_000,
    ROTATE_WIDGET_BONUS_TIME: 10_000,
    ROTATE_WIDGET_REWARD_TIME: 10_000,
    SHOW_ENDS_IN_TIME: 5_000,
    BLINK_ANIMATION_START_TIME: 15_000, // 15sec prior to ending
    ELAPSED_TIME_PERCENTAGE: 0.93,
} as const;

interface IWidgetProps {
    tournament?: Tournament;
    reward?: Reward;
}

export const Widget = memo(function Widget({tournament, reward}: IWidgetProps) {
    const {ROTATE_ONCE_A_MINUTE, ROTATE_TWICE_A_MINUTE, ELAPSED_TIME_PERCENTAGE, BLINK_ANIMATION_START_TIME} =
        WIDGET_CONSTANTS;
    const t = useTranslate();
    const layout = useSelector((state) => state.app.window.layout);
    const frame = useSelector((state) => state.slot.size.frame);

    const bonuses = useSelector((state) => state.bonuses);
    const currentGame = useSelector((state) => state.slot.name);
    const isGameInTournament = useMemo(() => {
        if (!tournament) return null;

        if (tournament.games.length > 0) {
            return tournament.games.includes(currentGame);
        }

        return true; //empty games array means all games are eligible
    }, [tournament]);
    const hasBonuses = Object.keys(bonuses.data).length > 0;
    const hasReward = Boolean(reward);
    const [userPositionDuration, setUserPositionDuration] = useState<number>(ROTATE_ONCE_A_MINUTE);
    const tournamentNearEnd = userPositionDuration === ROTATE_TWICE_A_MINUTE;
    const isTournamentEnded = useMemo(() => {
        if (!tournament) return null;

        const dateNow = Date.now();
        const tournamentEndTime = tournament.endDateTimestamp * 1_000;

        return dateNow > tournamentEndTime;
    }, [tournament]);

    const currentMainFace = useRotatingFace({
        hasBonus: hasBonuses,
        hasReward: hasReward,
        tournament: Boolean(tournament),
        tournamentNearEnd: tournamentNearEnd,
        constants: WIDGET_CONSTANTS,
    });
    const tournamentSubstate = useTournamentFace({
        hasEnded: isTournamentEnded,
        inactive: !isGameInTournament,
        tournamentEndNearing: tournamentNearEnd,
        constants: WIDGET_CONSTANTS,
    });
    const [startBlinkAnimation, setStartBlinkAnimation] = useState(false);

    const {updateTournamentModal} = useTournamentsController();

    useEffect(() => {
        if (!tournament) return;

        const now = Date.now();
        const endDateInMs = tournament.endDateTimestamp * 1_000;
        const totalDuration = endDateInMs - tournament.startDateTimestamp;
        const switchAt = tournament.startDateTimestamp + totalDuration * ELAPSED_TIME_PERCENTAGE;

        // Set a one-time timeout to switch the frequency at which we rotate position and ends in
        const msUntilSwitch = switchAt - now;
        if (msUntilSwitch > 0) {
            const switchTimeout = setTimeout(() => {
                setUserPositionDuration(ROTATE_TWICE_A_MINUTE); // change to 30s
            }, msUntilSwitch);

            return () => clearTimeout(switchTimeout);
        }
    }, [tournament]);

    useEffect(() => {
        if (!tournament || isTournamentEnded) return;

        const checkTime = () => {
            const now = Date.now();
            const endDateInMs = tournament.endDateTimestamp * 1_000; // endDateTimestamp is in secs and I need it in ms
            const remaining = endDateInMs - now;

            if (remaining <= BLINK_ANIMATION_START_TIME) {
                setStartBlinkAnimation(true);
            }
        };

        const interval = setInterval(() => {
            checkTime();
        }, 1_000);

        return () => clearInterval(interval);
    }, [tournament?.endDateTimestamp]);

    const top = layout === Layout.Landscape ? 0 : frame.y;

    // if (!tournament || !reward) return;

    const renderWidgetFace = () => {
        switch (currentMainFace) {
            case MainFace.Reward:
                return <CupWidgetFace text={t('Reward')} />;
            case MainFace.Tournament:
                if (tournamentSubstate === Faces.UserPosition) return <UserPosition tournament={tournament} />;
                if (tournamentSubstate === Faces.EndsIn)
                    return (
                        <EndsInContent endsIn={tournament.endDateTimestamp} startBlinkAnimation={startBlinkAnimation} />
                    );
                if (tournamentSubstate === Faces.Inactive) return <CupWidgetFace text={t('Tournament')} />;
                if (tournamentSubstate === Faces.Ended) return <CupWidgetFace text={t('Ended')} />;
                return null;
            default:
                return null;
        }
    };

    const clickHandler = () => {
        switch (currentMainFace) {
            case MainFace.Reward:
                updateTournamentModal(tournament.id, ModalTypes.Reward, tournament);
                return;
            case MainFace.Tournament: {
                if ([Faces.Ended, Faces.UserPosition, Faces.EndsIn].includes(tournamentSubstate)) {
                    updateTournamentModal(tournament.id, ModalTypes.Tournament, tournament);
                    return;
                }
                if (tournamentSubstate === Faces.Inactive) {
                    updateTournamentModal(tournament.id, ModalTypes.InactiveTournament, tournament);
                    return;
                }
                return;
            }
            default:
                return null;
        }
    };

    return (
        <div
            className='TournamentsWidget'
            style={{
                top: top + 'px',
                transform: 'translateY(-100%)',
                visibility: currentMainFace === MainFace.Bonus ? 'hidden' : 'visible',
            }}
        >
            <div className='TournamentsWidget__default' onClick={clickHandler}>
                {[Faces.UserPosition, Faces.EndsIn].includes(tournamentSubstate) && <TrophyIcon />}
                {renderWidgetFace()}
            </div>
        </div>
    );
});
```
