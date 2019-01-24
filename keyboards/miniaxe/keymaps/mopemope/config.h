#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 120
// #define AUTO_SHIFT_TIMEOUT 150

#undef RGBLED_NUM
#define RGBLED_NUM 16
#define RGBLIGHT_TIMER
#define RGBLIGHT_ANIMATIONS

#endif