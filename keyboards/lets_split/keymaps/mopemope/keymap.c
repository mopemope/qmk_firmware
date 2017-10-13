#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _EMACS  1
#define _EMACS2 2
#define _LOWER  3
#define _RAISE  4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EMACS,
  EMACS2,
  LOWER,
  RAISE,
  ADJUST,
};

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
// C-f
#define CF LCTL(KC_F)
// C-/
#define C_SL LCTL(JP_SLSH)

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

// C-M
#define C_M LCTL(KC_LALT)

// C-RIGHT
#define C_R LCTL(KC_RIGHT)
// C-LEFT
#define C_L LCTL(KC_LEFT)
// C-N
#define C_N LCTL(KC_N)
// C-P
#define C_P LCTL(KC_P)
// M-D
#define M_D LALT(KC_D)

#define TAP(code)  \
  register_code (code); \
  unregister_code (code)


enum double_taps {
  GF = 0,
  E_LT,
  E_GT,
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [GF] = ACTION_TAP_DANCE_DOUBLE (KC_LGUI, KC_F12),
  [E_LT] = ACTION_TAP_DANCE_DOUBLE (A_LT, C_LT),
  [E_GT] = ACTION_TAP_DANCE_DOUBLE (A_GT, C_GT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  | A/AD |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  | @/AD |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |-/CTL |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,<  |  .>  |  /?  |\/ALT |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  ^   |RESET |  ALT | GUI  |DEL/L |SP/SFT| |EN/CTL| BS/R | GUI  | ALT  |EMACS |  |   |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_QWERTY] = KEYMAP( \
    KC_ESC,         KC_Q,             KC_W,    KC_E,    KC_R,              KC_T,          KC_Y,           KC_U,               KC_I,    KC_O,    KC_P,              JP_SCLN,        \
    KC_TAB,         LT(_ADJUST,KC_A), KC_S,    KC_D,    KC_F,              KC_G,          KC_H,           KC_J,               KC_K,    KC_L,    LT(_ADJUST,JP_AT), JP_COLN,        \
    CTL_T(JP_MINS), KC_Z,             KC_X,    KC_C,    KC_V,              KC_B,          KC_N,           KC_M,               KC_COMM, KC_DOT,  JP_SLSH,           ALT_T(JP_BSLS), \
    JP_CIRC,        RESET,            KC_LALT, TD(GF),  LT(_LOWER,KC_DEL), SFT_T(KC_SPC), CTL_T(KC_ENT),  LT(_RAISE,KC_BSPC), TD(GF),  KC_RALT, DF(_EMACS),        JP_PIPE         \
  ),
  /* EMACS
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  | A/AD |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  |@/EM2 |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |-/CTL |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,<  |  .>  |  /?  |\/ALT |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  ^   |RESET |  ALT | GUI  |DEL/L |SP/SFT| |EN/CTL| BS/R | C-M  | ALT  |QWERTY|  |   |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_EMACS] = KEYMAP( \
    KC_ESC,         KC_Q,             KC_W,    KC_E,    KC_R,              KC_T,          KC_Y,           KC_U,               KC_I,    KC_O,    KC_P,              JP_SCLN,        \
    KC_TAB,         LT(_ADJUST,KC_A), KC_S,    KC_D,    KC_F,              KC_G,          KC_H,           KC_J,               KC_K,    KC_L,    LT(_EMACS2,JP_AT), JP_COLN,        \
    CTL_T(JP_MINS), KC_Z,             KC_X,    KC_C,    KC_V,              KC_B,          KC_N,           KC_M,               KC_COMM, KC_DOT,  JP_SLSH,           ALT_T(JP_BSLS), \
    JP_CIRC,        RESET,            KC_LALT, TD(GF),  LT(_LOWER,KC_DEL), SFT_T(KC_SPC), CTL_T(KC_ENT),  LT(_RAISE,KC_BSPC), C_M,     KC_RALT, DF(_QWERTY),             JP_PIPE \
  ),
  /* EMACS2
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      |      |      |      |      | |      | E-LT | UP   | E-GT |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |  CA  |  CS  |      |  CF  |  CG  | |      | RIGHT| DOWN | LEFT |      |RESET |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  CZ  |  CX  |  CC  |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      | C_SL |MD/ALT|SP/CTL| |EN/CTL|BS/ALT|      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [_EMACS2] = KEYMAP( \
    _______, _______, _______, _______, _______,    _______,       _______,       TD(E_LT),       C_P,     TD(E_GT), _______, _______, \
    RESET,   CA,      CS,      _______, CF,         CG,            _______,       C_L,            C_N,     C_R,      _______, RESET,   \
    _______, CZ,      CX,      CC,      _______,    _______,       _______,       _______,        _______, _______,  _______, _______, \
    _______, _______, _______, C_SL,    ALT_T(M_D), CTL_T(KC_SPC), CTL_T(KC_ENT), ALT_T(KC_BSPC), _______, _______,  _______, _______  \
  ),

  /* LOWER
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
    JP_ZHTG, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_PERC, JP_AMPR, JP_QUOT, JP_MINS, JP_LPRN, JP_RPRN, JP_PIPE, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, JP_CIRC, JP_EQL,  JP_SCLN, JP_COLN, JP_YEN,  \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, JP_TILD, _______, JP_PLUS, JP_ASTR, _______, \
    _______, _______, _______, _______, _______, _______, _______, JP_MHEN, _______, _______, _______, _______  \
  ),

  /* RAISE
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

  /* ADJUST
   * ,-----------------------------------------, ,-----------------------------------------.
   * |      |      | WhDn | MsUp | WhUp |WRKSP1| |UWRKSP| PgDn |  Up  | PgUP |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |      | MsLf | MsDn | MsRg |WRKSP2| |DWRKSP| Left | Down | Right|      |RESET |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  CZ  |      |      | Copy |Paste | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |QWERTY|EMACS |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [_ADJUST] = KEYMAP( \
    _______, _______, KC_WH_D, KC_MS_U, KC_WH_U,    WRKSP1,     UWRKSP,      KC_PGDN,    KC_UP,   KC_PGUP,  _______, _______, \
    RESET,   _______, KC_MS_L, KC_MS_D, KC_MS_R,    WRKSP2,     DWRKSP,      KC_LEFT,    KC_DOWN, KC_RIGHT, _______, RESET,   \
    _______, CZ,      _______, _______, LCTL(KC_C), LCTL(KC_V), _______,     _______,    _______, _______,  _______, _______, \
    _______, _______, _______, _______, KC_BTN2,    KC_BTN1,    DF(_QWERTY), DF(_EMACS), _______, _______,  _______, _______ \
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
