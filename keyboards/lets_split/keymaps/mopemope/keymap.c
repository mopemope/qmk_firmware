#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ADJUST 3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))

#define TAP(code)  \
  register_code (code); \
  unregister_code (code)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum double_taps {
    CA = 0,
    RL,
    LR,
    AD,
    HE,
};

bool layer_tgl = false;
bool long_tap = false;

void ca_each(qk_tap_dance_state_t *state, void *user_data) {
}

void ca_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            register_code(KC_LALT);
        } else {
            unregister_code(KC_LALT);
        }
    } else if (state->count == 2) {
        if (state->pressed) {
            register_code(KC_LCTL);
        } else {
            unregister_code(KC_LCTL);
        }
    }
}

void ca_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && !state->pressed) {
        unregister_code(KC_LALT);
    } else if (state->count == 2 && !state->pressed) {
        unregister_code(KC_LCTL);
    }
}

void lr_each(qk_tap_dance_state_t *state, void *user_data) {
}

void lr_finished(qk_tap_dance_state_t *state, void *user_data) {
    long_tap = false;
    if (state->count == 1) {
        if (!state->pressed) {
            layer_tgl = !layer_tgl;
            layer_off(_ADJUST);
            layer_off(_RAISE);
            layer_on(_LOWER);
        } else {
            long_tap = true;
            layer_off(_ADJUST);
            layer_off(_RAISE);
            layer_on(_LOWER);
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            layer_tgl = !layer_tgl;
            layer_off(_ADJUST);
            layer_off(_LOWER);
            layer_on(_RAISE);
        } else {
            long_tap = true;
            layer_off(_ADJUST);
            layer_off(_LOWER);
            layer_on(_RAISE);
        }
    }
}

void lr_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (long_tap && !state->pressed) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
        return;
    }
    if (!layer_tgl) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
    if (state->count > 2) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
}

void rl_each(qk_tap_dance_state_t *state, void *user_data) {
}

void rl_finished(qk_tap_dance_state_t *state, void *user_data) {
    long_tap = false;
    if (state->count == 1) {
        if (!state->pressed) {
            layer_tgl = !layer_tgl;
            layer_off(_ADJUST);
            layer_off(_LOWER);
            layer_on(_RAISE);
        } else {
            long_tap = true;
            layer_off(_ADJUST);
            layer_off(_LOWER);
            layer_on(_RAISE);
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            layer_tgl = !layer_tgl;
            layer_off(_ADJUST);
            layer_off(_RAISE);
            layer_on(_LOWER);
        } else {
            long_tap = true;
            layer_off(_ADJUST);
            layer_off(_RAISE);
            layer_on(_LOWER);
        }
    }
}

void rl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (long_tap && !state->pressed) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
        return;
    }
    if (!layer_tgl) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
    if (state->count > 2) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
}

void ad_each(qk_tap_dance_state_t *state, void *user_data) {
}

void ad_finished(qk_tap_dance_state_t *state, void *user_data) {
    long_tap = false;
    if (state->count == 1) {
        layer_off(_LOWER);
        layer_off(_RAISE);
        layer_off(_ADJUST);
        register_code(KC_F12);
        unregister_code(KC_F12);
    } else if (state->count == 2) {
        if (!state->pressed) {
            layer_tgl = !layer_tgl;
            layer_off(_LOWER);
            layer_off(_RAISE);
            layer_on(_ADJUST);
        } else {
            long_tap = true;
            layer_off(_LOWER);
            layer_off(_RAISE);
            layer_on(_ADJUST);
        }
    }
}

void ad_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (long_tap && !state->pressed) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
        return;
    }
    if (!layer_tgl) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
    if (state->count > 2) {
        layer_off(_ADJUST);
        layer_off(_LOWER);
        layer_off(_RAISE);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA] = ACTION_TAP_DANCE_FN_ADVANCED (ca_each, ca_finished, ca_reset),
    [LR] = ACTION_TAP_DANCE_FN_ADVANCED (lr_each, lr_finished, lr_reset),
    [RL] = ACTION_TAP_DANCE_FN_ADVANCED (rl_each, rl_finished, rl_reset),
    [AD] = ACTION_TAP_DANCE_FN_ADVANCED (ad_each, ad_finished, ad_reset),
    [HE] = ACTION_TAP_DANCE_DOUBLE (JP_MHEN, JP_HENK),
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_SPC){
            register_code(KC_LCTL);
            TAP(KC_SPC);
            unregister_code(KC_LCTL);
        }
        SEQ_ONE_KEY(KC_Z){
            register_code(KC_LCTL);
            TAP(KC_Z);
            unregister_code(KC_LCTL);
        }

    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   | ;/+  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Esc/Ct| A/AD |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  | @/AD |:/Ctl |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |-/Sft |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,<  |  .>  |  /?  |\/Sft |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  AD  | GUI  | LEAD |  HE  |Del/L |Sp/Ctl| |En/Alt|Bksp/R| Left | Down |  Up  |Right |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_QWERTY] = KEYMAP( \
    KC_TAB,         KC_Q,             KC_W,    KC_E,    KC_R,              KC_T,          KC_Y,           KC_U,               KC_I,    KC_O,    KC_P,              JP_SCLN,         \
    CTL_T(KC_ESC),  LT(_ADJUST,KC_A), KC_S,    KC_D,    KC_F,              KC_G,          KC_H,           KC_J,               KC_K,    KC_L,    LT(_ADJUST,JP_AT), CTL_T(JP_COLN), \
    SFT_T(KC_MINS), KC_Z,             KC_X,    KC_C,    KC_V,              KC_B,          KC_N,           KC_M,               KC_COMM, KC_DOT,  JP_SLSH,           SFT_T(JP_BSLS), \
    TD(AD),         KC_LGUI,          KC_LEAD, TD(HE),  LT(_LOWER,KC_DEL), CTL_T(KC_SPC), ALT_T(KC_ENT), LT(_RAISE,KC_BSPC), KC_LEFT, KC_DOWN, KC_UP,             KC_RIGHT \
 ),

  /* Lower
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Zen  |   !  |   "  |   #  |   $  |   %  | |   &  |  '   |  -   |   (  |   )  | Del  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  | |      |  ^   |  =   |   ;  |   :  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  | |      |  ~   |      |   +  |   *  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_LOWER] = KEYMAP( \
    JP_ZHTG, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_PERC, JP_AMPR, JP_QUOT, JP_MINS, JP_LPRN, JP_RPRN, KC_DEL,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, JP_CIRC, JP_EQL,  JP_SCLN, JP_COLN, JP_BSLS, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, JP_TILD, _______, JP_PLUS, JP_ASTR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Raise
   * ,-----------------------------------------, ,-----------------------------------------.
   * | Zen  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   (  |   )  |   [  |   ]  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |      |      |   {  |   }  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_RAISE] = KEYMAP( \
    JP_ZHTG, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_LPRN, JP_RPRN, JP_LBRC, JP_RBRC, JP_YEN,  \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , _______, _______, JP_LCBR, JP_RCBR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Adjust
   * ,-----------------------------------------, ,-----------------------------------------.
   * | Esc  | PgDN | WhDn | MsUp | WhUp |WRKSP1| |WRKSP1| WhDn | MsUp | WhUp | PgUP | Del  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Reset |      | MsLf | MsDn | MsRg |WRKSP2| |WRKSP2| MsLf | MsDn | MsRg |      |Reset |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | Copy |Paste | |Paste | Copy |      | Mute |VolDn |VolUp |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |Click1|Click2|      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_ADJUST] = KEYMAP( \
    KC_ESC,  KC_PGDN, KC_WH_D, KC_MS_U, KC_WH_U,    WRKSP1,     WRKSP1,     KC_WH_D,    KC_MS_U, KC_WH_U, KC_PGUP, KC_DEL,  \
    RESET,   _______, KC_MS_L, KC_MS_D, KC_MS_R,    WRKSP2,     WRKSP2,     KC_MS_L,    KC_MS_D, KC_MS_R, _______, RESET,   \
    _______, _______, _______, _______, LCTL(KC_C), LCTL(KC_V), LCTL(KC_V), LCTL(KC_C), _______, KC_MUTE, KC_VOLD, KC_VOLU, \
    _______, _______, _______, _______, KC_BTN2,    KC_BTN1,    KC_BTN1,    KC_BTN2,    _______, _______, _______, _______  \
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
