#include "lets_split.h"
#include "pro_micro.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QGMLWY  0
#define LOWER   3
#define RAISE   4
#define MISC    5
#define MISC2   6
#define GAME1   7
#define GAME2   8
#define GAME3   9
#define NONE   10

#define _____ KC_TRNS
#define XXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))

//#define COLN  CTL_T(JP_COLN)
#define TAB    KC_TAB
#define MINS   ALT_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define BSP    KC_BSPC
#define DEL    KC_DEL
#define SDEL   SFT_T(KC_DEL)
#define RAI    MO(RAISE)
#define RJ     LT(RAISE,KC_J)
#define LK     LT(LOWER,KC_K)
#define SPC    LT(RAISE,KC_SPC)
#define CSPC   CTL_T(KC_SPC)
#define ENT    LT(LOWER,KC_ENT)
#define CENT   CTL_T(KC_ENT)
#define BSPC   CTL_T(KC_BSPC)
#define SBSPC  SFT_T(KC_BSPC)
#define LOW    MO(LOWER)
#define ABSPC  ALT_T(KC_BSPC)
#define CBSPC  CTL_T(KC_BSPC)
#define A_M    LT(MISC,KC_A)
#define D_M    LT(MISC,KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define X_CT   CTL_T(KC_X)
#define P_C    CTL_T(KC_P)
#define A_C    CTL_T(KC_A)
#define H_M    LT(MISC2,KC_H)
#define S_M    LT(MISC2,JP_SLSH)
#define S_C    CTL_T(JP_SLSH)
#define S_A    ALT_T(JP_SLSH)
#define V_A    ALT_T(KC_V)
#define O_C    CTL_T(KC_O)
#define AT_M   LT(MISC,JP_AT)
#define AT_A   ALT_T(JP_AT)
#define AT_C   CTL_T(JP_AT)
#define M2     MO(MISC2)
#define GL     LGUI(KC_LEFT)
#define GU     LGUI(KC_UP)
#define GD     LGUI(KC_DOWN)
#define GR     LGUI(KC_RIGHT)
#define GH     LGUI(KC_H)
#define GTAB   TD(G_TAB)
#define EXLM   JP_EXLM
#define DQT    JP_DQT
#define HASH   JP_HASH
#define DLR    JP_DLR
#define PERC   JP_PERC
#define AMPR   JP_AMPR
#define QUOT   JP_QUOT
#define GRV    JP_GRV
#define PIPE   JP_PIPE
#define YEN    JP_YEN
#define AT     JP_AT
#define LCBR   JP_LCBR
#define RCBR   JP_RCBR
#define UNDS   JP_UNDS
#define TILD   JP_TILD
#define EQL    JP_EQL
#define COLN   JP_COLN
#define SLSH   JP_SLSH
#define ASTR   JP_ASTR
#define LPRN   JP_LPRN
#define RPRN   JP_RPRN
#define BSLS   JP_BSLS
#define CIRC   CTL_T(JP_CIRC)
#define SCLN   JP_SCLN
#define COMM   SFT_T(JP_COMM)
#define DOT    ALT_T(JP_DOT)
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   ALT_T(JP_RBRC)
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define ALT    OSM(MOD_LALT)
#define CTL    OSM(MOD_LCTL)
#define SFT1   SFT_T(JP_MHEN)
#define SFT2   SFT_T(JP_HENK)
#define C_S    SFT_T(KC_C)
#define ESC    KC_ESC
#define DQ     DF(QGMLWY)
#define DG1    DF(GAME1)
#define DG2    DF(GAME2)
#define DG3    DF(GAME3)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define WH_D   KC_WH_D
#define MS_U   KC_MS_U
#define WH_U   KC_WH_U
#define PGDN   KC_PGDN
#define PGUP   KC_PGUP
#define MS_L   KC_MS_L
#define MS_D   KC_MS_D
#define MS_R   KC_MS_R
#define KLEFT  KC_LEFT
#define KUP    KC_UP
#define KDOWN  KC_DOWN
#define KRIGHT KC_RIGHT
#define MUTE   KC_MUTE
#define VOLD   KC_VOLD
#define VOLU   KC_VOLU
#define BTN2   KC_BTN2
#define BTN1   KC_BTN1
#define ASTG   KC_ASTG

#define RTOG  RGB_TOG
#define RMOD  RGB_MOD
#define RRMOD RGB_RMOD
#define RHUI  RGB_HUI
#define RHUD  RGB_HUD
#define RSAI  RGB_SAI
#define RSAD  RGB_SAD
#define RVAI  RGB_VAI
#define RVAD  RGB_VAD

enum double_taps {
  G_TAB    = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [G_TAB] = ACTION_TAP_DANCE_DOUBLE (KC_TAB, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QGMLWY
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  Q   |  G   |  M   |  L   |  W   |      | |      |  Y   |  F   |  U   |  B   |  BSP |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  D   |  S   |  T   |  N   |  R   |      | |      |  I   |  A   |  E   |  O   |  H   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  Z   |  X   |  C   |  V   |  J   |      | |      |  K   |  P   |  ,   |  .   |  /   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [QGMLWY] = LAYOUT( \
    KC_Q,    KC_G,    KC_M,    KC_L,  KC_W,  XXXXX, XXXXX, KC_Y,  KC_F,  KC_U,  KC_B,   BSP,    \
    D_M,     KC_S,    KC_T,    KC_N,  KC_R,  XXXXX, XXXXX, KC_I,  KC_A,  KC_E,  KC_O,   H_M,    \
    Z_A ,    X_CT,    C_S,     V_A,   RJ,    XXXXX, XXXXX, LK,    P_C,   COMM,  DOT,    S_C,    \
    XXXXX,   XXXXX,   XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX   \
  ),

  /* LOWER (Symbol)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  !   |   "  |   #  |   $  |   %  |      | |      |   &  |  '   |  `   |   |  | yen  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | ESC  |   [  |  (   |   {  |  \   |      | |      |   ~  |  =   |  :   |   /  |  *   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  ^   |   ]  |  )   |   }  |  SPC |      | |      |      |  -   |  ;   |   .  |  +   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [LOWER] = LAYOUT( \
    EXLM,    DQT,     HASH,   DLR,    PERC,   XXXXX, XXXXX, AMPR,    QUOT,   GRV,     PIPE,   YEN,   \
    ESC,     LBRC,    LPRN,   LCBR,   BSLS,   XXXXX, XXXXX, TILD,    EQL,    COLN,    SLSH,   ASTR,  \
    CIRC,    RBRC,    RPRN,   RCBR,   SPC,    XXXXX, XXXXX, _____,   MINS,   SCLN,    DOT,    PLUS,  \
    XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX,   XXXXX,  XXXXX,   XXXXX,  XXXXX  \
  ),

  /* RAISE (Num + Fn + Others)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |  1   |  2   |   3  |  4   |  5   |      | |      |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | TAB  |  F1  |  F2  |  F3  |  F4  |      | |      |  SPC |  F12 |  F7  |  F8  |   @  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  _   |  F9  |  F10 |  F11 |      |      | |      |  ENT | BSPC | ZHTG |  F6  |   -  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = LAYOUT( \
    KC_1,    KC_2,   KC_3,    KC_4,   KC_5,   XXXXX,  XXXXX,  KC_6,   KC_7,    KC_8,   KC_9,    KC_0,   \
    TAB,     KC_F1,  KC_F2,   KC_F3,  KC_F4,  XXXXX,  XXXXX,  SPC,    KC_F12,  KC_F7,  KC_F8,   AT,     \
    UNDS,    KC_F9,  KC_F10,  KC_F11, _____,  XXXXX,  XXXXX,  ENT,    BSPC,    ZHTG,   KC_F6,   MINS,   \
    XXXXX,   XXXXX,  XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,  XXXXX,   XXXXX   \
  ),

  /* MISC (GUI)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |RESET | WhDn | MsUp | WhUp |WRKSP1|      | |      |UWRKSP| PgDn |  Up  | PgUp | DEL  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | MsLf | MsDn | MsRg |WRKSP2|      | |      |DWRKSP| Left | Down |Right |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      | Copy |Paste | GUI  |      | |      | BTN1 | BTN2 |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC] = LAYOUT( \
    RESET, WH_D,  MS_U,    WH_U,   WRKSP1, XXXXX,  XXXXX,  UWRKSP, PGDN,   GU,     PGUP,   DEL,    \
    _____, MS_L,  MS_D,    MS_R,   WRKSP2, XXXXX,  XXXXX,  DWRKSP, GL,     GD,     GR,     _____,  \
    XXXXX, XXXXX, COPY,    PASTE,  GUI,    XXXXX,  XXXXX,  BTN1,   BTN2,   XXXXX,  XXXXX,  XXXXX,  \
    XXXXX, XXXXX, XXXXXXX, XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX   \
  ),

  /* MISC2 (GUI2)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |RESET |      |      |      |      |      | |      |      | PgDn |  Up  | PgUp | DEL  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | DG1  | DG2  |      |      |      |      | |      | SPC  | Left | Down |Right |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | RTOG | RMOD | RHUI | RHUD | SPC  |      | |      | ENT  | BSPC | RSAI | RSAD |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC2] = LAYOUT( \
    RESET,   _____,  _____,  _____,  _____, XXXXX, XXXXX, _____,  PGDN,   KUP,     PGUP,    DEL,    \
    DG1,     DG2,    _____,  _____,  _____, XXXXX, XXXXX, SPC,    KLEFT,  KDOWN,   KRIGHT,  _____,  \
    RTOG,    RMOD,   RHUI,   RHUD,   CSPC,  XXXXX, XXXXX, ENT,    BSPC,   RSAI,    RSAD,    _____,  \
    XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX,  XXXXX,   XXXXX,   _____   \
  ),

  /* GAME1(BL2)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  TAB |  G   |  W   |  E   |  R   |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | SHIFT|  A   |  S   |  D   |  F   |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  C   |  Q   |  M   |  V   |  SPC |      | |      |  DQ  |      |      |      |  DQ  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [GAME1] = LAYOUT( \
    GTAB,    KC_G,  KC_W,  KC_E,  KC_R,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    KC_C,    KC_Q,  KC_M,  KC_V,  SPC,   XXXXX, XXXXX, DQ,    XXXXX, XXXXX, XXXXX, DQ,        \
    XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX      \
  ),
  /* GAME2(WoL)
   * ,-----------------------------------------, ,-----------------------------------------,
   * |  TAB |  Q   |  W   |  E   |  R   |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |  A   |  S   |  D   |  F   |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |  M   |      |  SPC |      | |      |  DQ  |      |      |      |  DQ  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [GAME2] = LAYOUT( \
    GTAB,    KC_Q,  KC_W,  KC_E,  KC_R,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    XXXXX,   KC_A,  KC_S,  KC_D,  KC_F,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    XXXXX,   XXXXX, KC_M,  XXXXX, SPC,   XXXXX, XXXXX, DQ,    XXXXX, XXXXX, XXXXX, DQ,        \
    XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX      \
  ),
  /* NONE
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [NONE] = LAYOUT( \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, DF(QGMLWY) \
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  TXLED0;
  RXLED0;
}

void matrix_scan_user(void) {
  TXLED0;
  RXLED0;
}

#ifdef RGBLIGHT_ENABLE

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
    case QGMLWY:
      rgblight_mode(7);
      break;
    case LOWER:
      rgblight_mode(21);
      break;
    case RAISE:
      rgblight_mode(22);
      break;
    case MISC:
      rgblight_mode(15);
      break;
    case MISC2:
      rgblight_mode(16);
      break;
    case GAME1:
      rgblight_mode(9);
      break;
    default:
      break;
  }

  return state;
}
#endif
