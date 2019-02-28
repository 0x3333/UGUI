# Changes

* Fonts, Components, Colors have been externalized to a separated file
* Pseudo Theme created(See `ugui_theme_default.h`)
* Added `flush` function. In case the display driver uses Framebuffer, this function will be called after `UG_Update` is called
* Prefixed all defines with `UGUI_`
* Touch support is optional using `UGUI_USE_TOUCH` define
* Added `UGUI_USE_COLOR_BW` for monochromatic displays, also added theme support

# Commits added from other forks

* https://github.com/stone-payments/UGUI/commit/a8e3da4e0ff2eb1c3c78e0d88a36ae825227726d
    * Add const specifier for not changed variables
