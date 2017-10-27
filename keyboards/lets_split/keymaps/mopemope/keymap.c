#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QWERTY  3
#define EMACS   1
#define EMACS2  2
#define COLEMAK 0
#define CEMACS  4
#define CEMACS2 5
#define LOWER   6
#define RAISE   7
#define MISC    8
#define NONE    9

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))

// Emacs shortcut
// C-a
#define C_A LCTL(KC_A)
// C-z
#define C_Z LCTL(KC_Z)
// C-g
#define C_G LCTL(KC_G)
// C-x
#define C_X LCTL(KC_X)
// C-s
#define C_S LCTL(KC_S)
// C-c
#define C_C LCTL(KC_C)
// C-f
#define C_F LCTL(KC_F)
// C-e
#define C_E LCTL(KC_E)
// C-b
#define C_B LCTL(KC_B)
// C-o
#define C_O LCTL(KC_O)
// C-r
#define C_R LCTL(KC_R)
// C-t
#define C_T LCTL(KC_T)
// C-y
#define C_Y LCTL(KC_Y)
// C-/
#define C_SL LCTL(JP_SLSH)
// C-BSLS
#define C_BSL LCTL(JP_BSLS)

// C-:
#define C_COLN LCTL(JP_COLN)
// C-;
#define C_SCLN LCTL(JP_SCLN)
// C-|
#define C_PIPE LCTL(JP_PIPE)

// C-V
#define C_V LCTL(KC_V)
// M-V
#define M_V LALT(KC_V)
// C-<
#define C_LT LCTL(JP_LT)
// C->
#define C_GT LCTL(JP_GT)
// M-<
#define M_LT LALT(JP_LT)
// M->
#define M_GT LALT(JP_GT)

// highlight symbol mode
// C-M-n
#define CMN LCTL(LALT(KC_N))
// C-M-s
#define CMP LCTL(LALT(KC_P))

// M-.
#define M_DOT  LALT(KC_DOT)
// C-M-.
#define CM_DOT LCTL(LALT(KC_DOT))
// M-%
#define M_PER  LALT(KC_PERC)
// M-x
#define M_X    LALT(KC_X)
// M-w
#define M_W    LALT(KC_W)

// C-M
#define C_M LCTL(KC_LALT)

// C-RIGHT
#define C_RI LCTL(KC_RIGHT)
// C-LEFT
#define C_LE LCTL(KC_LEFT)
// C-N
#define C_N  LCTL(KC_N)
// C-P
#define C_P  LCTL(KC_P)
// M-D
#define M_D  LALT(KC_D)

// MOD Shortcut

#define COLN  CTL_T(JP_COLN)
#define TAB   CTL_T(KC_TAB)
#define MINS  CTL_T(JP_MINS)
#define SMINS SFT_T(JP_MINS)
#define SBSLS SFT_T(JP_BSLS)
#define DEL   LT(RAISE,KC_DEL)
#define SPC   SFT_T(KC_SPC)
#define CSPC  CTL_T(KC_SPC)
#define ENT   SFT_T(KC_ENT)
#define CENT  CTL_T(KC_ENT)
#define EENT  LT(EMACS2,KC_ENT)
#define CEENT LT(CEMACS2,KC_ENT)
#define BSPC  LT(LOWER,KC_BSPC)
#define ABSPC ALT_T(KC_BSPC)
#define GUI   LT(MISC,KC_LGUI)
#define A_M   LT(MISC,KC_A)
#define O_M   LT(MISC,KC_O)
#define AT_M  LT(MISC,JP_AT)
#define AT_A  ALT_T(JP_AT)
#define AT_C  CTL_T(JP_AT)

#define TAP(code)  \
  register_code (code); \
  unregister_code (code)

enum double_taps {
  GF = 0,
  FF12,
  JF12,
  TF12,
  NF12,
  E_LT,
  E_GT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [GF] = ACTION_TAP_DANCE_DOUBLE (KC_LGUI, KC_F12),
  [FF12] = ACTION_TAP_DANCE_DOUBLE (KC_F, KC_F12),
  [JF12] = ACTION_TAP_DANCE_DOUBLE (KC_J, KC_F12),
  [TF12] = ACTION_TAP_DANCE_DOUBLE (KC_T, KC_F12),
  [NF12] = ACTION_TAP_DANCE_DOUBLE (KC_N, KC_F12),
  [E_LT] = ACTION_TAP_DANCE_DOUBLE (M_V, C_LT),
  [E_GT] = ACTION_TAP_DANCE_DOUBLE (C_V, C_GT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  |  @   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  -   |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |   .  |  /   |  \   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |EMACS |  ^   |  ALT | GUI  |DEL/R |SP/SFT| |EN/SFT| BS/L | LEFT | DOWN |  UP  |RIGHT |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [QWERTY] = KEYMAP( \
    KC_ESC,    KC_Q,    KC_W,    KC_E,   KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    JP_SCLN, \
    TAB,       A_M,     KC_S,    KC_D,   KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    AT_M,    COLN,    \
    SMINS,     KC_Z,    KC_X,    KC_C,   KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  JP_SLSH, SBSLS,   \
    DF(EMACS), JP_CIRC, KC_LALT, TD(GF), DEL,  SPC,  ENT,  BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
  ),

  /* EMACS
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |   L  |  @   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  -   |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |   .  |  /   |  \   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |QWERTY| C-M  |  ALT | GUI  |DEL/R |SP/SFT| |EN/EM2| BS/L | LEFT | DOWN |  UP  |RIGHT |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [EMACS] = KEYMAP( \
    KC_ESC,     KC_Q, KC_W,    KC_E,   KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    JP_SCLN, \
    TAB,        A_M,  KC_S,    KC_D,   KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    AT_M,    COLN,    \
    SMINS,      KC_Z, KC_X,    KC_C,   KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  JP_SLSH, SBSLS,   \
    DF(QWERTY), C_M,  KC_LALT, TD(GF), DEL,  SPC,  EENT, BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
  ),

  /* EMACS2 (Shortcut Layer)
   *
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      | M-W  | C-E  | C-R  | C-T  | | C-Y  | E-LT | UP   | E-GT |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | C-A  | C-S  |      | C-F  | C-G  | |M-DOT | LEFT | DOWN |RIGHT |      | C-E  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | C-Z  | C-X  | C-C  |      | C-B  | | M-%  | M-x  | C-;  | C-:  | C-|  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      | C_SL | M-D  |SP/CTL| |EN/CTL|BS/ALT|      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [EMACS2] = KEYMAP( \
    _______, _______, M_W,     C_E,     C_R,     C_T,  C_Y,   TD(E_LT), KC_UP,   TD(E_GT), _______, _______, \
    _______, C_A,     C_S,     _______, C_F,     C_G,  M_DOT, C_LE,     KC_DOWN, C_RI,     XXXXXXX, C_E,     \
    _______, C_Z,     C_X,     C_C,     _______, C_B,  M_PER, M_X,      C_SCLN,  C_COLN,   C_PIPE,  _______, \
    _______, _______, _______, C_SL,    M_D,     CSPC, CENT,  ABSPC,    _______, _______,  _______, _______  \
  ),

  /* COLEMAK
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  F   |  P   |  G   | |  J   |  L   |  U   |   Y  |  ;   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  |  A   |  R   |  S   |  T   |  D   | |  H   |  N   |  E   |   I  |   O  |  @   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  -   |  Z   |  X   |  C   |  V   |  B   | |  K   |  M   |  ,   |  .   |   /  |  \   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |EMACS |  ^   | ALT  | GUI  |DEL/R |SP/SFT| |EN/SFT| BS/L | LEFT | DOWN |  UP  |RIGHT |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [COLEMAK] = KEYMAP( \
    KC_ESC,     KC_Q,    KC_W,    KC_F,   KC_P, KC_G, KC_J, KC_L, KC_U,    KC_Y,    JP_SCLN, JP_COLN, \
    TAB,        A_M,     KC_R,    KC_S,   KC_T, KC_D, KC_H, KC_N, KC_E,    KC_I,    O_M,     AT_C,    \
    SMINS,      KC_Z,    KC_X,    KC_C,   KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT,  JP_SLSH, SBSLS,   \
    DF(CEMACS), JP_CIRC, KC_LALT, TD(GF), DEL,  SPC,  ENT,  BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
  ),

  /* EMACS(COLEMAK)
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Esc  |  Q   |  W   |  F   |  P   |  G   | |  J   |  L   |  U   |   Y  |  ;   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | Tab  |  A   |  R   |  S   |  T   |  D   | |  H   |  N   |  E   |   I  |  O   |  @   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  -   |  Z   |  X   |  C   |  V   |  B   | |  K   |  M   |  ,   |  .   |  /   |  \   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |COLEMA| C-M  | ALT  | GUI  |DEL/R |SP/SFT| |EN/EM2| BS/L | ALT  | C-M  |EMACS2|COLEMA|
   * `-----------------------------------------' `-----------------------------------------'
   */
  [CEMACS] = KEYMAP( \
    KC_ESC,      KC_Q, KC_W,    KC_F,   KC_P, KC_G, KC_J,  KC_L, KC_U,    KC_Y,   JP_SCLN,    JP_COLN,    \
    TAB,         A_M,  KC_R,    KC_S,   KC_T, KC_D, KC_H,  KC_N, KC_E,    KC_I,   O_M,        AT_C,       \
    SMINS,       KC_Z, KC_X,    KC_C,   KC_V, KC_B, KC_K,  KC_M, KC_COMM, KC_DOT, JP_SLSH,    SBSLS,      \
    DF(COLEMAK), C_M,  KC_LALT, TD(GF), DEL,  SPC,  CEENT, BSPC, KC_RALT, C_M,    MO(EMACS2), DF(COLEMAK) \
  ),

  /* EMACS2(COLEMAK Shortcut Layer)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      | M-W  | C-F  | C-Y  | C-G  | |      | E-LT | UP   | E-GT |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | C-A  | C-R  | C-S  | C-T  |      | |M-DOT | LEFT | DOWN |RIGHT |      | C-E  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | C-Z  | C-X  | C-C  |      | C-B  | | M-%  | M-x  | C-;  | C-:  | C-|  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      | C-SL | M-D  |SP/CTL| |EN/CTL|BS/ALT|      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [CEMACS2] = KEYMAP( \
    _______, _______, M_W,     C_F,  C_Y,     C_G,     _______, TD(E_LT), KC_UP,   TD(E_GT), _______, _______, \
    _______, C_A,     C_R,     C_S,  C_T,     _______, M_DOT,   C_LE,     KC_DOWN, C_RI,     XXXXXXX, C_E,     \
    _______, C_Z,     C_X,     C_C,  _______, C_B,     M_PER,   M_X,      C_SCLN,  C_COLN,   C_PIPE,  _______, \
    _______, _______, _______, C_SL, M_D,     CSPC,    CENT,    ABSPC,    _______, _______,  _______, _______  \
  ),

  /* LOWER
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Zen  |   !  |   "  |   #  |   $  |   %  | |   &  |  '   |  `   |   |  |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |   1  |   2  |   3  |   4  |   5  | |   ~  |  =   |  :   |   /  |   *  |  yen |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  | |   ^  |  -   |  ;   |   .  |   +  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | HENK |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [LOWER] = KEYMAP( \
    JP_ZHTG, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_PERC, JP_AMPR, JP_QUOT, JP_GRV,  JP_PIPE, _______, _______, \
    RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_TILD, JP_EQL,  JP_COLN, JP_SLSH, JP_ASTR, JP_YEN,  \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_CIRC, JP_MINS, JP_SCLN, JP_DOT,  JP_PLUS, _______, \
    _______, _______, _______, _______, JP_HENK, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* RAISE
   * ,-----------------------------------------, ,-----------------------------------------.
   * | Zen  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |  |   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   (  |   )  |   [  |   ]  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |   {  |   }  |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      | MHEN |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = KEYMAP( \
    JP_ZHTG, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_PIPE, \
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_LPRN, JP_RPRN, JP_LBRC, JP_RBRC, JP_YEN,  \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  JP_LCBR, JP_RCBR, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, JP_MHEN, _______, _______, _______, _______  \
  ),

  /* MISC
   * ,-----------------------------------------, ,-----------------------------------------.
   * |      |      | WhDn | MsUp | WhUp |WRKSP1| |UWRKSP| PgDn |  Up  | PgUP |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |RESET | CTRL | MsLf | MsDn | MsRg |WRKSP2| |DWRKSP| Left | Down | Right| CTRL |RESET |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | Copy |Paste | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |EN/CTL|BS/ALT|      |QWERTY|COLEMA| NONE |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC] = KEYMAP( \
    _______, _______, KC_WH_D, KC_MS_U, KC_WH_U,    WRKSP1,     UWRKSP,  KC_PGDN, KC_UP,   KC_PGUP,    _______,     _______, \
    RESET,   KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R,    WRKSP2,     DWRKSP,  KC_LEFT, KC_DOWN, KC_RIGHT,   KC_RCTL,     RESET,   \
    _______, _______, _______, _______, LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______,    _______,     _______, \
    _______, _______, _______, _______, KC_BTN2,    KC_BTN1,    CENT,    ABSPC,   _______, DF(QWERTY), DF(COLEMAK), DF(NONE) \
  ),
  /* NONE
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |QWERTY|      |      |      |      |      | |      |      |      |      |      |COLEMA|
   * `-----------------------------------------' `-----------------------------------------'
   */
  [NONE] = KEYMAP( \
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    DF(QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(COLEMAK) \
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
