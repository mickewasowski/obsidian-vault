---
aliases:
context:
- "[[CSS]]"
---

# Fade mask CSS

---

```scss
@mixin edgeFadeMask($left-fade, $right-fade) {
    481 +  -webkit-mask-image: linear-gradient(
    482 +    to right,
    483 +    $transparent 0,
    484 +    #000 $left-fade,
    485 +    #000 calc(100% - #{$right-fade}),
    486 +    $transparent 100%
    487 +  );
    488 +  mask-image: linear-gradient(
    489 +    to right,
    490 +    $transparent 0,
    491 +    #000 $left-fade,
    492 +    #000 calc(100% - #{$right-fade}),
    493 +    $transparent 100%
    494 +  );
    495 +  -webkit-mask-size: 100% 100%;
    496 +  mask-size: 100% 100%;
    497 +  -webkit-mask-repeat: no-repeat;
    498 +  mask-repeat: no-repeat;
    499 +}
```
