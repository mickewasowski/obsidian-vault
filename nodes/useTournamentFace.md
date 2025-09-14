---
aliases:
context:
- "[[Hirarchical state machine]]"
---


# useTournamentFace

This is the hook I used for the sub state machine.

---

```js
// useTournamentFace.tsx 

import {useEffect, useState} from 'react';

interface IProps {
    hasEnded: boolean;
    inactive: boolean;
    tournamentEndNearing: boolean;
    constants: {[key: string]: number};
}

export enum Faces {
    Ended,
    Inactive,
    UserPosition,
    EndsIn,
}

export type FaceState = Faces.Ended | Faces.Inactive | Faces.UserPosition | Faces.EndsIn;

function useTournamentFace({hasEnded, inactive, tournamentEndNearing, constants}: IProps) {
    const [sub, setSub] = useState<FaceState>(() => {
        if (hasEnded) return Faces.Ended;
        if (inactive) return Faces.Inactive;
        return Faces.UserPosition;
    });

    let timer: NodeJS.Timeout;
    useEffect(() => {
        if (hasEnded) return setSub(Faces.Ended);
        if (inactive) return setSub(Faces.Inactive);

        switch (sub) {
            case Faces.UserPosition: {
                const timeoutValue = tournamentEndNearing
                    ? constants.ROTATE_TWICE_A_MINUTE
                    : constants.ROTATE_ONCE_A_MINUTE;
                timer = setTimeout(() => setSub(Faces.EndsIn), timeoutValue);
                break;
            }
            case Faces.EndsIn: {
                timer = setTimeout(() => setSub(Faces.UserPosition), constants.SHOW_ENDS_IN_TIME);
                break;
            }
            default: {
                if (timer) clearTimeout(timer);
                break;
            }
        }

        return () => clearTimeout(timer);
    }, [sub, hasEnded, inactive, tournamentEndNearing]);

    return sub;
}

export default useTournamentFace;
```
