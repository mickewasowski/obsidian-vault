---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Font resizing

Function for dynamic font size resizing.

---

> Function for jackpot pools font size resizing. 
``` js
const handleTextSize = () => {
        const container = amountContainerRef.current;
        const textEl = amountRef.current;

        if (!container || !textEl) return;
        textEl.style.overflow = 'hidden';

        const actualAvailableWidth =
            container.clientWidth - imageRef.current.clientWidth - currencyRef.current.clientWidth;
        textEl.style.width = actualAvailableWidth + 'px';

        const containerWidth = textEl.clientWidth;
        const containerHeight = textEl.clientHeight;
        const amountLength = textEl.innerText.length;
        const sizePerLetter = containerWidth / amountLength;
        const customScaler = 0.57;
        const maxWidth = sizePerLetter / customScaler;
        const fontSize = Math.min(maxWidth, containerHeight);

        textEl.style.fontSize = fontSize + 'px';
    };
}
```

> React component for a text in a container.
``` js
import {useEffect, useRef} from 'react';

interface IProps {
    /*In pixels*/
    maxFontSize: number;
    content: string;
}

export const FitContent = ({maxFontSize, content}: IProps) => {
    const contentRef = useRef(null);

    const handleTextSize = () => {
        const textEl = contentRef.current;

        if (!textEl) return;

        const container = contentRef.current;
        const sizePerLetter = container.clientWidth / content.length;
        const customScaler = 0.6;
        // const minimumFontSize = sizePerLetter * customScaler;
        const maxWidth = Math.min(sizePerLetter / customScaler, maxFontSize);
        const fontSize = Math.min(maxWidth, textEl.clientHeight);
        textEl.style.fontSize = fontSize + 'px';
    };

    useEffect(() => {
        let resizeObserver;
        if (contentRef.current && contentRef.current.parentElement) {
            resizeObserver = new ResizeObserver(() => {
                handleTextSize();
            });

            resizeObserver.observe(contentRef.current.parentElement);
        }

        return () => {
            if (contentRef.current) {
                resizeObserver.unobserve(contentRef.current.parentElement);
            }
        };
    }, [content]);

    return (
        <span style={{overflow: 'hidden'}} ref={contentRef}>
            {content}
        </span>
    );
};
```