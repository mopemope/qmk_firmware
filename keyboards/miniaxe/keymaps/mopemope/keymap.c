/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "pro_micro.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QGMLWY  0
#define QWERTY  1
#define LOWER   3
#define RAISE   4
#define MISCL   5
#define MISCR   6
#define GAME1   7
#define GAME2   8
#define GAME3   9
#define COMBR  11
#define COMBL  12
#define COMBE  13
#define COMBT  14

#define _____ KC_TRNS
#define XXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))

#define TAB    KC_TAB
#define MINS   ALT_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define BSP    KC_BSPC
#define DEL    KC_DEL
#define ALT    OSM(MOD_LALT)
#define CTL    OSM(MOD_RCTL)
#define SDEL   SFT_T(KC_DEL)
#define SFT1   SFT_T(JP_MHEN)
#define SFT2   SFT_T(JP_HENK)
#define SFTZ   SFT_T(JP_ZHTG)
#define RJ     LT(RAISE,KC_J)
#define LK     LT(LOWER,KC_K)
#define AC     LT(COMBR,KC_A)
#define NC     LT(COMBL,KC_N)
#define EC     LT(COMBE,KC_E)
#define KC     LT(COMBE,KC_K)
#define TC     LT(COMBT,KC_T)
#define SPC    LT(RAISE,KC_SPC)
#define CSPC   LCTL(KC_SPC)
#define CRET   LCTL(KC_ENT)
#define ENT    LT(LOWER,KC_ENT)
#define CENT   CTL_T(KC_ENT)
#define BSPC   RCTL_T(KC_BSPC)
#define SBSPC  SFT_T(KC_BSPC)
#define ABSPC  ALT_T(KC_BSPC)
#define CBSPC  CTL_T(KC_BSPC)
#define D_M    LT(MISCL,KC_D)
#define D_C    CTL_T(KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define Z_S    LSFT_T(KC_Z)
#define X_CT   LCTL_T(KC_X)
#define P_AL   LALT_T(KC_P)
#define J_C    RCTL_T(KC_J)
#define P_C    RCTL_T(KC_P)
#define A_C    RCTL_T(KC_A)
#define H_M    LT(MISCR,KC_H)
#define S_C    CTL_T(JP_SLSH)
#define S_S    RSFT_T(JP_SLSH)
#define V_A    LALT_T(KC_V)
#define O_C    CTL_T(KC_O)
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
#define DOT    JP_DOT
#define CDOT   LCTL(JP_DOT)
#define MCOM   LALT(JP_COMM)
#define MDOT   LALT(JP_DOT)
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   ALT_T(JP_RBRC)
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define C_S    SFT_T(KC_C)
#define ESC    KC_ESC
#define DQG    DF(QGMLWY)
#define DQW    DF(QWERTY)
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
#define CMD    LALT(LCTL(JP_DOT))
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
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   G  |   M  |   L  |   W  |           |   Y  |   F  |   U  |   B  | BSP  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   D  |   S  |   T  |   N  |   R  |           |   I  |   A  |   E  |   O  |  H   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |      |           |      |   J  |   K  |   P  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |  SFT |  ALT | SPC  |           | ENT  | CTRL |  BSP |
 *               `--------------------'           `--------------------'
 */
[QGMLWY] = LAYOUT( \
  KC_Q,    KC_G,   KC_M,  KC_L,  KC_W,             KC_Y,   KC_F,   KC_U,  KC_B,   BSP,     \
  D_M,     KC_S,   TC,    NC,    KC_R,             KC_I,   AC,     EC,    KC_O,   H_M,     \
  Z_S,     X_CT,   KC_C,  KC_V,  GUI,              SPC,    KC_J,   KC_K,  P_AL,   S_S,     \
                   SFT1,  ALT,   SPC,              ENT,    CTL,    BSP                     \
),

/* LOWER (Symbol)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |           |   &  |   '  |   `  |  yen |  DEL |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ESC |   (  |   )  |   {  |   }  |           |   ~  |   =  |   :  |   ;  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ^  |   [  |   ]  |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[LOWER] = LAYOUT( \
  EXLM,   DQT,     HASH,  DLR,   PERC,              AMPR,  QUOT,  GRV,    YEN,   DEL,      \
  ESC,    LPRN,    RPRN,  LCBR,  RCBR,              TILD,  EQL,   COLN,   SCLN,  AT,       \
  CIRC,   LBRC,    RBRC,  _____, _____,             _____, _____, _____,  _____, _____,    \
                  _____, _____, _____,             _____, _____, _____ \
),

/* RAISE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  F1  |  F2  |  F3  |  F4  |           |  F5  | F12  |  F7  |  F8  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |  F9  |  F10 |  F11 |      |           |  DQG |  F6  |   <  |   >  |   -  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |   .  |  :   |      |
 *               `--------------------'           `--------------------'
 */
[RAISE] = LAYOUT( \
  KC_1,    KC_2,   KC_3,  KC_4,  KC_5,              KC_6,  KC_7,   KC_8,  KC_9,   KC_0,   \
  TAB,     KC_F1,  KC_F2, KC_F3, KC_F4,             KC_F5, KC_F12, KC_F7, KC_F8,  AT,     \
  UNDS,    KC_F9,  KC_F10,KC_F11,_____,             DQG,   KC_F6,  KC_LT, KC_GT,  MINS,   \
                   _____, _____, _____,             DOT,   COLN,   _____                  \
),

/* MISC_LEFT
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET| WHDN | MSUP | WHUP |WRKSP1|           |UWRKSP| PGDN |  UP  | PGUP | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | MSL  | MSDN | MSR  |WRKSP2|           |DWRKSP| LEFT | DOWN | RIGHT|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | COPY | PASTE|      |           |      |      |      | HIDE |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | BTN2 | BTN1 |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[MISCL] = LAYOUT( \
  RESET,   WH_D,   MS_U,  WH_U,  WRKSP1,           UWRKSP, PGDN,  GU,    PGUP,  DEL,     \
  _____,   MS_L,   MS_D,  MS_R,  WRKSP2,           DWRKSP, GL,    GD,    GR,    _____,   \
  _____,   _____,  COPY,  PASTE, _____,            _____,  _____, _____, GH,    _____,   \
                   _____, BTN2,  BTN1,             _____,  _____, _____                  \
),

/* MISC_RIGHT
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|  DG1 |  DG2 |  DG3 | RTOG |           |      | PGDN |  UP  | PGUP | RESET|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB | RHUI | RHUD | RSAI | RSAD |           |      | LEFT | DOWN | RIGHT|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | COPY | PASTE| RMOD |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[MISCR] = LAYOUT( \
  RESET,   DG1,    DG2,   DG3,   RTOG,             _____, PGDN,   KUP,   PGUP,   RESET,   \
  TAB,     RHUI,   RHUD,  RSAI,  RSAD,             _____, KLEFT,  KDOWN, KRIGHT, _____,   \
  _____,   _____,  COPY,  PASTE, RMOD,             _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* COMB_RIGHT (Emacs)
 *
 * ,----------------------------------.           ,----------------------------------.
 * | ZHTG |  C-G | C-M-M|  C-L | M-%  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  M-D |  C-S |  C-T | C-M-N| M-X  |           |      |      |   [  | C-M-.|  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  C-Z |  C-X |  C-C |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[COMBR] = LAYOUT( \
  ZHTG,    CG,     CM,    CL,    APERC,            _____, _____,  _____, _____,  _____,   \
  MD,      CS,     CT,    CN,    MX,               _____, _____,  LBRC,  CMD,    CAT,     \
  CZ,      CX,     CC,    _____, _____,            _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* COMB_LEFT (Emacs)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  C-G |      |      |      |           |      |  C-> |  UP  |  C-> |  DEL |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  C-S |  C-T |      |      |           |  M-; | LEFT | DOWN | RIGHT|  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  C-X |  CRET| CSPC |      |           |  M-, |  M-. |  C-, |  C-. |  C-/ |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[COMBL] = LAYOUT( \
  _____,   CG,     CM,    CL,    _____,            _____, ELT,    KUP,   EGT,    DEL,     \
  TAB,     CS,     CT,    _____, _____,            MSCLN, KLEFT,  KDOWN, KRIGHT, CAT,     \
  _____,   CX,     CRET,  CSPC,  _____,            MCOM,  MDOT,   CCOM,  CDOT,   CSL,     \
                   _____, _____, _____,            _____, _____,  _____   \
),

/* COMB_RIGHT2 (COMBE)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      | DQW  |           | DQG  |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[COMBE] = LAYOUT( \
  _____,   _____,  _____, _____, DQW,              DQG,   _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* COMB_LEFT2 (COMBT)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |   (  |   )  |   +  |   *  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   ~  |   =  |   :  |   ;  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |   -  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[COMBT] = LAYOUT( \
  _____,   _____,  _____, _____, _____,            LPRN,  RPRN,   PLUS,  ASTR,   PIPE,    \
  _____,   _____,  _____, _____, _____,            TILD,  EQL,    COLN,  SCLN,   AT,      \
  _____,   _____,  _____, _____, _____,            _____, MINS,   COMM,  DOT,    SLSH,    \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* GAME1
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           | DQG  |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[GAME1] = LAYOUT( \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* GAME2
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           | DQG  |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[GAME2] = LAYOUT( \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
),

/* GAME3
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           | DQG  |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[GAME3] = LAYOUT( \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
  _____,   _____,  _____, _____, _____,            _____, _____,  _____, _____,  _____,   \
                   _____, _____, _____,            _____, _____,  _____                   \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
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
      rgblight_mode(21);
      break;
    case MISCR:
      rgblight_mode(16);
      break;
    case MISCL:
      rgblight_mode(16);
      break;
    case COMBR:
      rgblight_mode(5);
      break;
    case COMBL:
      rgblight_mode(5);
      break;
    case COMBE:
      rgblight_mode(6);
      break;
    case COMBT:
      rgblight_mode(6);
      break;
    case GAME1:
      rgblight_mode(11);
      break;
    case GAME2:
      rgblight_mode(11);
      break;
    case GAME3:
      rgblight_mode(11);
      break;
    default:
      break;
  }

  return state;
}
#endif
