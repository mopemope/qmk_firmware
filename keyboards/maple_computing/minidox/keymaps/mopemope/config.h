/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
/* #ifndef CONFIG_USER_H */
/* #define CONFIG_USER_H */

/* #include "../../config.h" */

//#define USE_SERIAL
#define EE_HANDS

#define FORCE_NKRO
#define DEBOUNCE 10
#define NO_ACTION_ONESHOT
#define LAYER_STATE_16BIT
#define TAP_CODE_DELAY 1
#define NO_MUSIC_MODE

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* #define PREVENT_STUCK_MODIFIERS */
/* #define PERMISSIVE_HOLD */
/* #define TAPPING_FORCE_HOLD */
//#define TAPPING_TERM 160

/* #define RGB_DI_PIN D7 */
/* #define RGBLIGHT_TIMER */
/* #undef RGBLED_NUM */
/* #define RGBLED_NUM 8 */
/* #define RGBLIGHT_ANIMATIONS */
/* #define RGBLIGHT_HUE_STEP 10 */
/* #define RGBLIGHT_SAT_STEP 17 */
/* #define RGBLIGHT_VAL_STEP 17 */
#define USB_POLLING_INTERVAL_MS 1
#define GPIO_INPUT_PIN_DELAY 0

//#endif
