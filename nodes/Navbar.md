---
aliases:
context:
- "[[CSS]]"
- "[[JavaScript]]"
---

#wip

# Navbar

Useful functions related to Navbar behavior.

---
### Show/hide functionality on scroll
``` js
    useEffect(() => {
        const appContainer = document.querySelector('#root .App');
        if (search.open) {
            appContainer.style.overflow = 'hidden';
        } else {
            appContainer.style.overflow = 'auto';
        }

        if (!navRef.current || layout === 'desktop') return;

        let navBarOffsetTop = navRef.current.offsetTop;
        let lastScrollTop = appContainer.scrollTop;

        let visible = true;
        let offsetTop = 0;

        const handleTouchEnd = () => {
            if (appContainer.scrollTop + appContainer.clientHeight > appContainer.scrollHeight) return;
            const buttonsContainer = document.querySelector('.ActivePlayersFilterSlider__games-filter-wrapper__outer');
            const buttonsContainerRect = buttonsContainer.getBoundingClientRect();
            const navBarHeight = buttonsContainer.style.position === 'absolute' ? navRef.current.offsetHeight + buttonsContainerRect.height : navRef.current.offsetHeight;
            const scrollTop: number = appContainer.scrollTop;

            if (scrollTop < navBarOffsetTop + navBarHeight) return;

            if (offsetTop / navBarHeight > -0.5) {
                visible = true;
                offsetTop = 0;
            } else {
                visible = false;
                offsetTop = -navBarHeight;
            }

            navRef.current.style.transform = `translateY(${offsetTop}px)`;
        };

        /**
         * This function is intended to handle the ActivePlayersFilterSlider component's positioning when it becomes absolute.
         * The function is defined and used here because when there are two separate scroll event handlers the positioning is not always accurate
         * and causes a few pixels miscalculation when scrolling fast.
         * */
        const handleScrollCategoriesSlider = () => {
            if (appContainer.scrollTop + appContainer.clientHeight > appContainer.scrollHeight) return;
            const container = document.querySelector('.ActivePlayersFilterSlider__games-filter-wrapper__outer');

            if (container.style.position !== 'absolute') return;

            // Get current navbar transform offset
            const navTransform = navRef.current.style.transform;
            const offsetYMatch = navTransform.match(/translateY\((-?\d+\.?\d*)px\)/);
            const navOffsetY = offsetYMatch ? parseFloat(offsetYMatch[1]) : 0;

            // Place this container directly below the navbar, accounting for its transform
            const navHeight = navRef.current.offsetHeight;
            const containerTopPosition = navOffsetY + navHeight;

            container.style.top = `${containerTopPosition}px`;

            if (container.style.position === 'absolute') {
                const originalParent = document.querySelector('.ActivePlayersFilterSlider');
                const parentRect = originalParent.getBoundingClientRect();

                const androidFullscreen = document.querySelector('.android-fullscreen');
                const containerOffsetTop = (layout === Layout.MobilePortrait && androidFullscreen) ? container.offsetTop + 40 : container.offsetTop; // do i add the 40px top to this one?
                const parentTop = parentRect.top;

                if (containerOffsetTop > 0 && containerOffsetTop <= parentTop) {
                    container.style.position = 'static';
                }
            }
        };


        const handleScroll = () => {
            if (appContainer.scrollTop + appContainer.clientHeight > appContainer.scrollHeight) return;
            navRef.current.style.transition = '0s';

            const buttonsContainer = document.querySelector('.ActivePlayersFilterSlider__games-filter-wrapper__outer');
            const buttonsContainerRect = buttonsContainer.getBoundingClientRect();
            const navBarHeight = buttonsContainer.style.position === 'absolute' ? navRef.current.offsetHeight + buttonsContainerRect.height : navRef.current.offsetHeight;

            const scrollTop: number = appContainer.scrollTop;
            const delta = scrollTop - lastScrollTop;

            if (scrollTop > lastScrollTop) {
                // Scroll down

                if (scrollTop >= navBarOffsetTop) {
                    offsetTop -= delta;

                    if (visible && offsetTop < -navBarHeight) {
                        visible = false;
                    }
                }
            } else {
                // Scroll up

                if (!visible) {
                    visible = true;
                    offsetTop = -navBarHeight;
                } else {
                    offsetTop -= delta;
                    if (offsetTop > 0) offsetTop = 0;
                }
            }

            lastScrollTop = scrollTop;
            navRef.current.style.transform = `translateY(${offsetTop}px)`;
            handleScrollCategoriesSlider(); // this handles the top position of the categories slider component
        };

        const timeout = setTimeout(() => {
            navBarOffsetTop = navRef.current.offsetTop;
            appContainer.addEventListener('touchend', handleTouchEnd);
            appContainer.addEventListener('mouseup', handleTouchEnd);
            appContainer.addEventListener('scroll', handleScroll);
        }, 50);

        return () => {
            clearTimeout(timeout);
            appContainer.removeEventListener('touchend', handleTouchEnd);
            appContainer.removeEventListener('mouseup', handleTouchEnd);
            appContainer.removeEventListener('scroll', handleScroll);
        };
    }, [location, search.open, search.text, navRef.current, gamesPageFilter]);

    useEffect(() => {
        if (!navRef.current) return;
        setTimeout(() => {
            navRef.current.style.transform = 'translateY(0)';
        }, 60);
    }, [location]);
```


``` js
// this is intended to monitor the component that needs to be taken out of it's original place
    useEffect(() => {
        const container = containerRef.current;
        const navbar = document.querySelector('.NavBar');

        if (!container || !navbar) return;

        const originalParent = document.querySelector('.ActivePlayersFilterSlider');
        if (!originalParent) return;

        const hiding = new IntersectionObserver(
            ([entry]) => {
                if (!entry.isIntersecting) {
                    parentRef.current.style.height = container.offsetHeight + 'px';
                    container.style.position = 'absolute';
                    container.style.top = `-${container.offsetHeight}px`;
                    container.style.left = '0';
                    container.style.transition = '0s';
                    container.style.zIndex = '11';
                    container.style.width = '100%';
                }
            },
            {
                root: null,
                threshold: 0.1,
            },
        );

		hiding.observe(originalParent);

        return () => {
            hiding.unobserve(originalParent);
        };
    }, []);
```