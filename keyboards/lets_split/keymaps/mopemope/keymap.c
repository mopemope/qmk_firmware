#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define COLEMAK 0
#define EMACS   1
#define EMACS2  2
#define LOWER   3
#define RAISE   4
#define MISC    5
#define NONE    6

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
// C-SPC
#define C_SPC  LCTL(KC_SPC)

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
#define BSPC  LT(LOWER,KC_BSPC)
#define ABSPC ALT_T(KC_BSPC)
#define GUI   LT(MISC,KC_LGUI)
#define A_M   LT(MISC,KC_A)
#define A_C   CTL_T(KC_A)
#define O_M   LT(MISC,KC_O)
#define O_C   CTL_T(KC_O)
#define AT_M  LT(MISC,JP_AT)
#define AT_A  ALT_T(JP_AT)
#define AT_C  CTL_T(JP_AT)

#define TAP(code)  \
  register_code (code); \
  unregister_code (code)

enum double_taps {
  E_LT = 0,
  E_GT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [E_LT] = ACTION_TAP_DANCE_DOUBLE (M_V, C_LT),
  [E_GT] = ACTION_TAP_DANCE_DOUBLE (C_V, C_GT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* COLEMAK
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  Q   |  W   |  F   |  P   |  G   |  -   | |  _   |  J   |  L   |  U   |  Y   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  A   |  R   |  S   |  T   |  D   | TAB  | |  @   |  H   |  N   |  E   |  I   |  O   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  Z   |  X   |  C   |  V   |  B   | GUI  | | F12  |  K   |  M   |  ,   |  .   |  /   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |EMACS |      |      | CTRL |DEL/R |SP/SFT| |EN/SFT| BS/L | ALT  |      |      |EMACS |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [COLEMAK] = KEYMAP( \
    KC_Q,      KC_W,    KC_F,    KC_P,    KC_G, JP_MINS, JP_UNDS, KC_J, KC_L,    KC_U,    KC_Y,    JP_COLN,  \
    A_M,       KC_R,    KC_S,    KC_T,    KC_D, KC_TAB,  JP_AT,   KC_H, KC_N,    KC_E,    KC_I,    O_M,      \
    KC_Z,      KC_X,    KC_C,    KC_V,    KC_B, KC_LGUI, KC_F12,  KC_K, KC_M,    KC_COMM, KC_DOT,  JP_SLSH,  \
    DF(EMACS), XXXXXXX, XXXXXXX, KC_LCTL, DEL,  SPC,     ENT,     BSPC, KC_RALT, XXXXXXX, XXXXXXX, DF(EMACS) \
  ),

  /* EMACS(COLEMAK)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  Q   |  W   |  F   |  P   |  G   |  -   | |  _   |  J   |  L   |  U   |  Y   |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  A   |  R   |  S   |  T   |  D   | TAB  | |  @   |  H   |  N   |  E   |  I   |  O   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  Z   |  X   |  C   |  V   |  B   | C-M  | | C-Z  |  K   |  M   |  ,   |  .   |  /   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |COLEMA|      |      | CTRL |DEL/R |SP/SFT| |EN/EM2| BS/L | ALT  |      |      |COLEMA|
   * `-----------------------------------------' `-----------------------------------------'
   */

  [EMACS] = KEYMAP( \
    KC_Q,        KC_W,    KC_F,    KC_P,    KC_G, JP_MINS, JP_UNDS, KC_J, KC_L,    KC_U,    KC_Y,    JP_COLN,    \
    A_M,         KC_R,    KC_S,    KC_T,    KC_D, KC_TAB,  JP_AT,   KC_H, KC_N,    KC_E,    KC_I,    O_M,        \
    KC_Z,        KC_X,    KC_C,    KC_V,    KC_B, C_M,     C_Z,     KC_K, KC_M,    KC_COMM, KC_DOT,  JP_SLSH,    \
    DF(COLEMAK), XXXXXXX, XXXXXXX, KC_LCTL, DEL,  SPC,     EENT,    BSPC, KC_RALT, XXXXXXX, XXXXXXX, DF(COLEMAK) \
  ),

  /* EMACS2(COLEMAK Shortcut Layer)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |RESET | M-W  | C-F  | C-Y  | C-G  |      | |      |      | E-LT |  UP  | E-GT |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | C-A  | C-R  | C-S  | C-T  |      |      | | M-.  |      | LEFT |DOWN  |RIGHT |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | C-Z  | C-X  | C-C  |      | C-B  |      | | M-%  | M-x  | C-;  | C-:  | C-|  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      | C-SL | M-D  |C-SPC | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [EMACS2] = KEYMAP( \
    RESET,   M_W,     C_F,     C_Y,     C_G,     XXXXXXX, XXXXXXX, XXXXXXX, TD(E_LT), KC_UP,   TD(E_GT), XXXXXXX, \
    C_A,     C_R,     C_S,     C_T,     XXXXXXX, XXXXXXX, M_DOT,   XXXXXXX, C_LE,     KC_DOWN, C_RI,     XXXXXXX, \
    C_Z,     C_X,     C_C,     XXXXXXX, C_B,     XXXXXXX, M_PER,   M_X,     C_SCLN,   C_COLN,  C_PIPE,   XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, C_SL,    M_D,     C_SPC,   _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX  \
  ),

  /* LOWER
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  !   |   "  |   #  |   $  |   %  | Esc  | | Esc  |   &  |  '   |  `   |   |  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  1   |   2  |   3  |   4  |   5  |      | |  _   |   ~  |  =   |  :   |   /  |   *  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  6   |   7  |   8  |   9  |   0  |      | |  \   |   ^  |  -   |  ;   |   .  |   +  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      | HENK |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [LOWER] = KEYMAP( \
    JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,  JP_PERC, KC_ESC,  KC_ESC,  JP_AMPR, JP_QUOT, JP_GRV,  JP_PIPE, JP_YEN,  \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, JP_UNDS, JP_TILD, JP_EQL,  JP_COLN, JP_SLSH, JP_ASTR, \
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, JP_BSLS, JP_CIRC, JP_MINS, JP_SCLN, JP_DOT,  JP_PLUS, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, JP_HENK, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  /* RAISE
   * ,-----------------------------------------, ,-----------------------------------------.
   * |  1   |  2   |   3  |  4   |  5   | Esc  | | Esc  |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | TAB  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   (  |   )  |   [  |   ]  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  _   |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |   {  |   }  |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      | MHEN |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = KEYMAP( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,  KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_LPRN, JP_RPRN, JP_LBRC, JP_RBRC, JP_YEN,  \
    JP_UNDS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  JP_LCBR, JP_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, JP_MHEN, _______, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  /* MISC
   * ,-----------------------------------------, ,-----------------------------------------.
   * |RESET | WhDn | MsUp | WhUp |WRKSP1|      | |      |UWRKSP| PgDn |  Up  | PgUp |RESET |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | MsLf | MsDn | MsRg |WRKSP2|      | |      |DWRKSP| Left | Down |Right |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      | Copy |Paste |EMACS |      | |      |COLEMA|      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |LClick|RClick|      | |      |EN/CTL|BS/ALT|      |      | NONE |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC] = KEYMAP( \
    RESET,   KC_WH_D, KC_MS_U,    KC_WH_U,    WRKSP1,    XXXXXXX, XXXXXXX, UWRKSP,      KC_PGDN, KC_UP,   KC_PGUP,  RESET,   \
    _______, KC_MS_L, KC_MS_D,    KC_MS_R,    WRKSP2,    XXXXXXX, XXXXXXX, DWRKSP,      KC_LEFT, KC_DOWN, KC_RIGHT, _______, \
    XXXXXXX, XXXXXXX, LCTL(KC_C), LCTL(KC_V), DF(EMACS), XXXXXXX, XXXXXXX, DF(COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN2,    KC_BTN1,   XXXXXXX, XXXXXXX, CENT,        ABSPC,   XXXXXXX, XXXXXXX,  DF(NONE) \
  ),

  /* NONE
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |COLEMA|
   * `-----------------------------------------' `-----------------------------------------'
   */

  [NONE] = KEYMAP( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(COLEMAK) \
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
