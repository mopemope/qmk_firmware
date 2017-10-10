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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL

/* Select hand configuration */

#define MASTER_LEFT

#define PREVENT_STUCK_MODIFIERS

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 50

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 2

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 5

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0

#undef TAPPING_TERM
#define TAPPING_TERM 150

#define LEADER_TIMEOUT 400

#endif
