#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ADJUST 3
#define _EMACS  4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))

// Emacs shortcut
// C-a
#define CA LCTL(KC_A)
// C-z
#define CZ LCTL(KC_Z)
// C-g
#define CG LCTL(KC_G)
// C-x
#define CX LCTL(KC_X)
// C-s
#define CS LCTL(KC_S)
// C-c
#define CC LCTL(KC_C)
// C-:
#define CCOLN LCTL(JP_COLN)
// C-;
#define CSCLN LCTL(JP_SCLN)
// C-<
#define C_LT LCTL(JP_LT)
// C->
#define C_GT LCTL(JP_GT)
// A-<
#define A_LT LALT(JP_LT)
// A->
#define A_GT LALT(JP_GT)

// highlight symbol mode
// C-M-n
#define CMN LCTL(LALT(KC_N))
// C-M-s
#define CMP LCTL(LALT(KC_P))

// M-.
#define MDOT  LALT(KC_DOT)
// C-M-.
#define CMDOT LCTL(LALT(KC_DOT))


#define TAP(code)  \
  register_code (code); \
  unregister_code (code)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  EMACS,
};

enum double_taps {
  RL = 0,
  LR,
  AD,
  HE,
  GF,
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
    if (layer_tgl) {
      layer_tgl = !layer_tgl;
    } else {
      TAP(KC_F12);
    }
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
  /* [LR] = ACTION_TAP_DANCE_FN_ADVANCED (lr_each, lr_finished, lr_reset), */
  /* [RL] = ACTION_TAP_DANCE_FN_ADVANCED (rl_each, rl_finished, rl_reset), */
  /* [AD] = ACTION_TAP_DANCE_FN_ADVANCED (ad_each, ad_finished, ad_reset), */
  /* [HE] = ACTION_TAP_DANCE_DOUBLE (JP_MHEN, JP_HENK), */
  [GF] = ACTION_TAP_DANCE_DOUBLE (KC_LGUI, KC_F12),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  | A/AD |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  | @/EM |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |-=/Ctl|  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,<  |  .>  |  /?  |  \   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  ^   |RAISE |  Alt | GUI  |Del/L |SP/SFT| |EN/SFT| BS/R | GUI  | Alt  |LOWER |  |   |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_QWERTY] = KEYMAP( \
    KC_ESC,         KC_Q,             KC_W,    KC_E,    KC_R,              KC_T,          KC_Y,           KC_U,               KC_I,    KC_O,    KC_P,             JP_SCLN,        \
    KC_TAB,         LT(_ADJUST,KC_A), KC_S,    KC_D,    KC_F,              KC_G,          KC_H,           KC_J,               KC_K,    KC_L,    LT(_EMACS,JP_AT), JP_COLN,        \
    CTL_T(JP_MINS), KC_Z,             KC_X,    KC_C,    KC_V,              KC_B,          KC_N,           KC_M,               KC_COMM, KC_DOT,  JP_SLSH,          JP_BSLS, \
    JP_CIRC,        MO(_RAISE),       KC_LALT, TD(GF),  LT(_LOWER,KC_DEL), SFT_T(KC_SPC), SFT_T(KC_ENT),  LT(_RAISE,KC_BSPC), TD(GF),  KC_RALT, MO(_LOWER),       JP_PIPE \
 ),

  /* Lower
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Zen  |   !  |   "  |   #  |   $  |   %  | |   &  |  '   |  -   |   (  |   )  |  |   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  | |      |  ^   |  =   |   ;  |   :  |  yen |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  | |      |  ~   |      |   +  |   *  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      | MHEN |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_LOWER] = KEYMAP( \
    JP_ZHTG, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_PERC, JP_AMPR, JP_QUOT, JP_MINS, JP_LPRN, JP_RPRN, JP_PIPE,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, JP_CIRC, JP_EQL,  JP_SCLN, JP_COLN, JP_YEN,  \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, JP_TILD, _______, JP_PLUS, JP_ASTR, _______, \
    _______, _______, _______, _______, _______, _______, _______, JP_MHEN, _______, _______, _______, _______  \
  ),

  /* Raise
   * ,-----------------------------------------, ,-----------------------------------------.
   * | Zen  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |  |   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   (  |   )  |   [  |   ]  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |      |      |   {  |   }  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | HENK |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_RAISE] = KEYMAP( \
    JP_ZHTG, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_PIPE, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_LPRN, JP_RPRN, JP_LBRC, JP_RBRC, JP_YEN,  \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, JP_LCBR, JP_RCBR, _______, \
    _______, _______, _______, _______, JP_HENK, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Adjust
   * ,-----------------------------------------, ,-----------------------------------------.
   * |      |      | WhDn | MsUp | WhUp |WRKSP1| |UWRKSP|      |  Up  |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |      | MsLf | MsDn | MsRg |WRKSP2| |DWRKSP| Left | Down | Right|      |RESET |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | Copy |Paste | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_ADJUST] = KEYMAP( \
    _______, _______, KC_WH_D, KC_MS_U, KC_WH_U,    WRKSP1,     UWRKSP,  _______, KC_UP,   _______,  _______, _______, \
    RESET,   _______, KC_MS_L, KC_MS_D, KC_MS_R,    WRKSP2,     DWRKSP,  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, RESET,   \
    _______, _______, _______, _______, LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______,  _______, _______, \
    _______, _______, _______, _______, KC_BTN2,    KC_BTN1,    _______, _______, _______, _______,  _______, _______  \
  ),

  /* Emacs
   * ,-----------------------------------------, ,-----------------------------------------.
   * |      |      |      |      |      |      | |      | PgDN |  Up  | PgUp |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  CA  |  CS  |      |      |      | |      | Left | Down |Right |      | CTRL |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  CZ  |  CX  |  CC  |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |      |      |      |DE/ALT|SP/CTL| |EN/CTL|BS/ALT|      |      |      |RESET |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_EMACS] = KEYMAP( \
    _______, _______, _______, _______, _______,       _______,       _______,       KC_PGDN,        KC_UP,   KC_PGUP,  _______, _______, \
    _______, CA,      CS,      _______, _______,       _______,       _______,       KC_LEFT,        KC_DOWN, KC_RIGHT, _______, KC_LCTL, \
    _______, CZ,      CX,      CC,      _______,       _______,       _______,       _______,        _______, _______,  _______, _______, \
    RESET,   _______, _______, _______, ALT_T(KC_DEL), CTL_T(KC_SPC), CTL_T(KC_ENT), ALT_T(KC_BSPC), _______, _______,  _______, RESET    \
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
