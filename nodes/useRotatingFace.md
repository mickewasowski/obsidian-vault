---
aliases:
context:
- "[[Hirarchical state machine]]"
---

# useRotatingFace

This is the main state machine logic.

---
This hook is designed to handle which "face" (screen/state/view) is currently shown in a rotating manner, depending on which faces are available ('Bonus', 'Reward', 'Tournament'). It rotates through the available faces on a timer interval, with customizable timing per face.


### How it works

1. `items` is the array of main faces to rotate. It is filled based on the `hasBonus`, `hasReward` and `tournament` props.

2. `const current = items[index % items.length];` this would take an element from the array, and no matter the actual `index` value because it wraps the array. So even if with this `setIndex((i) => (i + 1) % items.length);` the `index` had become *22* it would wrap the array and always return an actual element.



``` js
// useRotatingFace.tsx 

import {useEffect, useMemo, useState} from 'react';

export enum MainFace {
    Bonus,
    Reward,
    Tournament,
}

export type MainStates = MainFace.Bonus | MainFace.Reward | MainFace.Tournament;

interface IProps {
    hasBonus: boolean;
    hasReward: boolean;
    tournament: boolean;
    tournamentNearEnd: boolean;
    constants: {[key: string]: number};
}

function useRotatingFace({hasBonus, hasReward, tournament, tournamentNearEnd, constants}: IProps) {
    const [index, setIndex] = useState(0);

    const items = useMemo(() => {
        const arr: Array<MainStates> = [];
        if (hasBonus) arr.push(MainFace.Bonus);
        if (hasReward) arr.push(MainFace.Reward);
        if (tournament) arr.push(MainFace.Tournament);
        return arr;
    }, [hasBonus, hasReward, tournament]);

    const current = items[index % items.length];

    useEffect(() => {
        setIndex(0);
    }, [items]);

    useEffect(() => {
        if (items.length === 0) return;

        let duration = 0;
        if (current === MainFace.Bonus) duration = constants.ROTATE_WIDGET_BONUS_TIME;
        else if (current === MainFace.Reward) duration = constants.ROTATE_WIDGET_REWARD_TIME;
        else if (current === MainFace.Tournament) {
            //TODO: what if it's ended ? it should be 50_000
            if (tournamentNearEnd) {
                duration = constants.ROTATE_TWICE_A_MINUTE + constants.SHOW_ENDS_IN_TIME;
            } else {
                duration = constants.ROTATE_ONCE_A_MINUTE + constants.SHOW_ENDS_IN_TIME;
            }
        }

        const timer = setTimeout(() => {
            setIndex((i) => (i + 1) % items.length);
        }, duration);

        return () => clearTimeout(timer);
    }, [current, items]);

    return current;
}

export default useRotatingFace;
```
