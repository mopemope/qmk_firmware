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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define SSD1306OLED

#define USE_SERIAL_PD2

#define DEBOUNCE 3
#define NO_ACTION_ONESHOT
#define LAYER_STATE_16BIT
#define TAP_CODE_DELAY 1
#define NO_MUSIC_MODE
#define FORCE_NKRO

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

#define USB_POLLING_INTERVAL_MS 1
#define GPIO_INPUT_PIN_DELAY 0


// Use the lily version to get the uzu42 logo instead of the qmk logo
//#define OLED_FONT_H "keymaps/default/glcdfont_uzu42.c"
