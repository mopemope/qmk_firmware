#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define FORCE_NKRO
// #define DEBOUNCE 10
// #define LAYER_STATE_16BIT
#define TAP_CODE_DELAY 1
#define TAP_HOLD_CAPS_DELAY 0
#define USB_POLLING_INTERVAL_MS 1
#define GPIO_INPUT_PIN_DELAY 0
#define NO_MUSIC_MODE

/* #define PREVENT_STUCK_MODIFIERS */
/* #define PERMISSIVE_HOLD */
/* #define TAPPING_FORCE_HOLD */
/* #define TAPPING_TERM 150 */
