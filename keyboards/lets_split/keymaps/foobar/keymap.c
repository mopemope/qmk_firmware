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
#define COMBA  11
#define COMBN  12

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
#define RJ     LT(RAISE,KC_J)
#define LK     LT(LOWER,KC_K)
#define AC     LT(COMBA,KC_A)
#define NC     LT(COMBN,KC_N)
#define NC2    CTL_T(KC_N)
#define SPC    LT(RAISE,KC_SPC)
#define CSPC   LCTL(KC_SPC)
#define CRET   LCTL(KC_ENT)
#define ENT    LT(LOWER,KC_ENT)
#define CENT   CTL_T(KC_ENT)
#define BSPC   RCTL_T(KC_BSPC)
#define SBSPC  SFT_T(KC_BSPC)
#define ABSPC  ALT_T(KC_BSPC)
#define CBSPC  CTL_T(KC_BSPC)
#define A_M    LT(MISC,KC_A)
#define D_M    LT(MISC,KC_D)
#define D_C    CTL_T(KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define Z_S    LSFT_T(KC_Z)
#define X_CT   LCTL_T(KC_X)
#define P_C    RCTL_T(KC_P)
#define A_C    RCTL_T(KC_A)
#define H_M    LT(MISC2,KC_H)
#define S_M    LT(MISC2,JP_SLSHH)
#define S_C    CTL_T(JP_SLSH)
#define S_S    RSFT_T(JP_SLSH)
#define V_A    LALT_T(KC_V)
#define O_C    CTL_T(KC_O)
#define AT_M   LT(MISC,JP_AT)
#define AT_A   ALT_T(JP_AT)
#define AT_C   CTL_T(JP_AT)
#define GL     LGUI(KC_LEFT)
#define GU     LGUI(KC_UP)
#define GD     LGUI(KC_DOWN)
#define GR     LGUI(KC_RIGHT)
#define GH     LGUI(KC_H)
#define GTAB   TD(G_TAB)
#define ELT    TD(E_LT)
#define EGT    TD(E_GT)
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
#define COMM   JP_COMM
#define CCOM   LCTL(JP_COMM)
#define DOT    RALT_T(JP_DOT)
#define CDOT   LCTL(JP_DOT)
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   ALT_T(JP_RBRC)
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define C_S    SFT_T(KC_C)
#define ESC    KC_ESC
#define DQ     DF(QGMLWY)
#define DG1    DF(GAME1)
#define DG2    DF(GAME2)
#define DG3    DF(GAME3)
#define SELA   LCTL(KC_A)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define CZ     LCTL(KC_Z)
#define CSL    LCTL(JP_SLSH)
#define CN     LALT(LCTL(KC_N))
#define CM     LALT(LCTL(KC_M))
#define CG     LCTL(KC_G)
#define CT     LCTL(KC_T)
#define CC     LCTL(KC_C)
#define CS     LCTL(KC_S)
#define CX     LCTL(KC_X)
#define CL     LCTL(KC_L)
#define CAT    LCTL(JP_AT)
#define MX     LALT(KC_X)
#undef  MD
#define MD     LALT(KC_D)
#define MSCLN  LALT(JP_SCLN)
#define APERC  LALT(JP_PERC)
#define CPIPE  LCTL(JP_PIPE)

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
#define RTOG   RGB_TOG
#define RMOD   RGB_MOD
#define RRMOD  RGB_RMOD
#define RHUI   RGB_HUI
#define RHUD   RGB_HUD
#define RSAI   RGB_SAI
#define RSAD   RGB_SAD
#define RVAI   RGB_VAI
#define RVAD   RGB_VAD
#define CTL    OSM(MOD_RCTL)

// COMB
// C-V
#define C_V LCTL(KC_V)
// M-V
#define M_V LALT(KC_V)
// C-<
#define C_LT LCTL(JP_LT)
// C->
#define C_GT LCTL(JP_GT)

enum double_taps {
  E_LT     = 0,
  E_GT     = 1,
  G_TAB    = 2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [E_LT] = ACTION_TAP_DANCE_DOUBLE (M_V, C_LT),
  [E_GT] = ACTION_TAP_DANCE_DOUBLE (C_V, C_GT),
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
    KC_Q,    KC_G,   KC_M,  KC_L,  KC_W,  XXXXX,  XXXXX,  KC_Y,  KC_F,  KC_U,  KC_B,   BSP,    \
    D_M,     KC_S,   KC_T,  NC,    KC_R,  XXXXX,  XXXXX,  KC_I,  AC,    KC_E,  KC_O,   H_M,    \
    Z_S ,    X_CT,   KC_C,  V_A,   RJ,    XXXXX,  XXXXX,  LK,    P_C,   COMM,  DOT,    S_S,    \
    XXXXX,   XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX   \
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
    EXLM,    DQT,    HASH,   DLR,   PERC,  XXXXX,  XXXXX, AMPR,   QUOT,  GRV,   PIPE,  YEN,   \
    ESC,     LBRC,   LPRN,   LCBR,  BSLS,  XXXXX,  XXXXX, TILD,   EQL,   COLN,  SLSH,  ASTR,  \
    CIRC,    RBRC,   RPRN,   RCBR,  SPC,   XXXXX,  XXXXX, _____,  MINS,  SCLN,  DOT,   PLUS,  \
    XXXXX,   XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX  \
  ),

  /* RAISE (Num + Fn + Others)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |  1   |  2   |   3  |  4   |  5   |      | |      |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | TAB  |  F1  |  F2  |  F3  |  F4  |      | |      |  F5  |  F12 |  F7  |  F8  |   @  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  _   |  F9  |  F10 |  F11 |      |      | |      |  ENT | BSPC | ZHTG |  F6  |   -  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = LAYOUT( \
    KC_1,    KC_2,  KC_3,   KC_4,   KC_5,  XXXXX,  XXXXX, KC_6,  KC_7,   KC_8,  KC_9,  KC_0,   \
    TAB,     KC_F1, KC_F2,  KC_F3,  KC_F4, XXXXX,  XXXXX, KC_F5, KC_F12, KC_F7, KC_F8, AT,     \
    UNDS,    KC_F9, KC_F10, KC_F11, _____, XXXXX,  XXXXX, ENT,   BSPC,   ZHTG,  KC_F6, MINS,   \
    XXXXX,   XXXXX, XXXXX,  XXXXX,  XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX   \
  ),

  /* MISC (GUI)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |RESET | PGDN |      | PGUP |WRKSP1|      | |      |UWRKSP| PgDn |  Up  | PgUp | DEL  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      | SELA |  GUI |WRKSP2|      | |      |DWRKSP| Left | Down |Right | HIDE |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      | COPY | PASTE|  SPC |      | |      |  ENT | BSPC | ZHTG |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC] = LAYOUT( \
    RESET, PGDN,   _____,  PGUP,  WRKSP1, XXXXX,  XXXXX,  UWRKSP, PGDN,  GU,    PGUP,  DEL,    \
    _____, _____,  SELA,   GUI,   WRKSP2, XXXXX,  XXXXX,  DWRKSP, GL,    GD,    GR,    GH,     \
    _____, XXXXX,  COPY,   PASTE, SPC,    XXXXX,  XXXXX,  ENT,    BSPC,  ZHTG,  _____, _____,  \
    XXXXX, XXXXX,  XXXXX,  XXXXX, XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX   \
  ),

  /* MISC2 (GUI2)
   * ,-----------------------------------------, ,-----------------------------------------.
   * |RESET |  DG1 |  DG2 |      | RTOG |      | |      |      | PgDn |  Up  | PgUp | DEL  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      | Left | Down | Right|      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      | COPY | PASTE| SPC  |      | |      |  ENT | BSPC | ZHTG |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MISC2] = LAYOUT( \
    RESET,   DG1,    DG2,   _____, RTOG,  XXXXX,  XXXXX, _____,  PGDN,  KUP,   PGUP,   DEL,    \
    _____,   _____,  _____, NC2,   _____, XXXXX,  XXXXX, _____,  KLEFT, KDOWN, KRIGHT, _____,  \
    _____,   _____,  COPY,  PASTE, SPC,   XXXXX,  XXXXX, ENT,    BSPC,  ZHTG,  _____,  _____,  \
    XXXXX,   XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX,  _____   \
  ),

  /* COMBA
   * ,-----------------------------------------, ,-----------------------------------------,
   * | ZHTG |  C-G | C-M-M|  C-L |  M-% |      | |      |      |      |  M-X |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  M-D |  C-S |  C-T | C-M-N|      |      | |      |      |      |   [  |      |  C-@ |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  C-Z |  C-X |  C-C |      |  SPC |      | |      |  ENT | BSPC |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [COMBA] = LAYOUT( \
    ZHTG,    CG,     CM,    CL,    APERC, XXXXX,   XXXXX, _____, _____, MX,    _____, _____,  \
    MD,      CS,     CT,    CN,    _____, XXXXX,   XXXXX, _____, _____, LBRC,  _____, CAT,    \
    CZ,      CX,     CC,    _____, SPC,   XXXXX,   XXXXX, ENT,   BSPC,  _____, _____, _____,  \
    XXXXX,   XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX   \
  ),

  /* COMBN
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      | C-G  |      |      |      |      | |      |      |  C-< |  Up  |  C-> |  C-| |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  CTL | C-S  |      |      |      |      | |      |  M-; |  Left|  Down| Right|  C-@ |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      | C-X  |      | CRET | CSPC |      | |      | ENT  | BSPC |  C-, |  C-. |  C-/ |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [COMBN] = LAYOUT( \
    _____,  CG,     _____,  _____, _____, XXXXX,   XXXXX, _____, ELT,   KUP,   EGT,    CPIPE,   \
    CTL,    CS,     _____,  _____, _____, XXXXX,   XXXXX, MSCLN, KLEFT, KDOWN, KRIGHT, CAT,     \
    _____,  CX,     _____,  CRET,  CSPC,  XXXXX,   XXXXX, ENT,   BSPC,  CCOM,  CDOT,   CSL,     \
    XXXXX,  XXXXX,  XXXXX,  XXXXX, XXXXX, XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX    \
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
      rgblight_mode(8);
      break;
    case LOWER:
      rgblight_mode(21);
      break;
    case RAISE:
      rgblight_mode(21);
      break;
    case MISC:
      rgblight_mode(16);
      break;
    case MISC2:
      rgblight_mode(16);
      break;
    case COMBA:
      rgblight_mode(5);
      break;
    case COMBN:
      rgblight_mode(5);
      break;
    case GAME1:
      rgblight_mode(10);
      break;
    case GAME2:
      rgblight_mode(10);
      break;
    default:
      break;
  }

  return state;
}
#endif
