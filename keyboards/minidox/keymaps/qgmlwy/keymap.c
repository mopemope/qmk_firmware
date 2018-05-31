#include "minidox.h"
#include "pro_micro.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QGMLWY  0
#define EMACS   1
#define EMACS2  2
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
// C-@
#define C_AT LCTL(JP_AT)

// C-:
#define C_COLN LCTL(JP_COLN)
// C-;
#define C_SCLN LCTL(JP_SCLN)
// C-|
#define C_PIPE LCTL(JP_PIPE)
// C-SPC
#define C_SPC  LCTL(KC_SPC)
// M-;
#define M_SCLN LALT(JP_SCLN)

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
#define C_M_S  LCTL(LALT(JP_BSLS))

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

//#define COLN  CTL_T(JP_COLN)
#define TAB    KC_TAB
#define MINS   ALT_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define DEL    KC_DEL
#define SDEL   SFT_T(KC_DEL)
#define ADEL   ALT_T(KC_DEL)
#define RAI    MO(RAISE)
#define SPC    KC_SPC
#define RSPC   LT(RAISE, KC_SPC)
#define CSPC   CTL_T(KC_SPC)
// #define ENT    SFT_T(KC_ENT)
#define ENT    LT(LOWER,KC_ENT)
#define CENT   CTL_T(KC_ENT)
#define EENT   LT(EMACS2,KC_ENT)
#define BSPC   KC_BSPC
#define SBSPC  SFT_T(KC_BSPC)
#define EBSPC  LT(EMACS2,KC_BSPC)
#define LOW    MO(LOWER)
#define ABSPC  ALT_T(KC_BSPC)
#define CBSPC  CTL_T(KC_BSPC)
//#define GUI   LT(MISC,KC_LGUI)
#define A_M    LT(MISC,KC_A)
#define D_M    LT(MISC,KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define A_C    CTL_T(KC_A)
#define O_M    LT(MISC2,KC_O)
#define H_M    LT(MISC2,KC_H)
#define S_M    LT(MISC2,JP_SLSH)
#define S_C    CTL_T(JP_SLSH)
#define S_A    ALT_T(JP_SLSH)
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
#define ELT    TD(E_LT)
#define EGT    TD(E_GT)
#define CLT    TD(ALT_CTL)
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
#define CIRC   JP_CIRC
#define SCLN   JP_SCLN
#define COMM   JP_COMM
#define DOT    JP_DOT
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   JP_RBRC
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define ALT    OSM(MOD_LALT)
#define CTL    OSM(MOD_LCTL)
#define SFT1   SFT_T(JP_MHEN)
#define SFT2   SFT_T(JP_HENK)
#define SFT3   LT(EMACS2,JP_HENK)
#define ESC    KC_ESC
#define DQ     DF(QGMLWY)
#define DE     DF(EMACS)
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
  E_LT     = 0,
  E_GT     = 1,
  ALT_CTL  = 2,
  G_TAB    = 3,
};

enum x_taps {
  SINGLE_TAP        = 1,
  SINGLE_HOLD       = 2,
  DOUBLE_TAP        = 3,
  DOUBLE_HOLD       = 4,
  DOUBLE_SINGLE_TAP = 5,
  OTHER             = 7
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || state->pressed == 0) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (state->interrupted) {
      return DOUBLE_SINGLE_TAP;
    } else if (state->pressed) {
      return DOUBLE_HOLD;
    } else {
      return DOUBLE_TAP;
    }
  } else {
    return OTHER;
  }
}

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LALT);
      break;
    case SINGLE_HOLD:
      register_code(KC_LALT);
      break;
    case DOUBLE_TAP:
      register_code(KC_LCTRL);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LCTRL);
      break;
    case DOUBLE_SINGLE_TAP:
      register_code(KC_LALT);
      break;
    default:
      break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:
      unregister_code(KC_LALT);
      break;
    case SINGLE_HOLD:
      unregister_code(KC_LALT);
      break;
    case DOUBLE_TAP:
      unregister_code(KC_LCTRL);
      break;
    case DOUBLE_HOLD:
      unregister_code(KC_LCTRL);
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code(KC_LALT);
      break;
    default:
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [E_LT] = ACTION_TAP_DANCE_DOUBLE (M_V, C_LT),
  [E_GT] = ACTION_TAP_DANCE_DOUBLE (C_V, C_GT),
  [G_TAB] = ACTION_TAP_DANCE_DOUBLE (KC_TAB, KC_ESC),
  [ALT_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QGMLWY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   G  |   M  |   L  |   W  |           |   Y  |   F  |   U  |   B  | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   D  |   S  |   T  |   N  |   R  |           |   I  |   A  |   E  |   O  |   H  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   J  |           |   K  |   P  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | SFT  | ALT  |      |    |      |  BS  | SFT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[QGMLWY] = LAYOUT( \
  KC_Q,   KC_G,    KC_M,   KC_L,    KC_W,        KC_Y,    KC_F,    KC_U,   KC_B,   DEL, \
  D_M,    KC_S,    KC_T,   KC_N,    KC_R,        KC_I,    KC_A,    KC_E,   KC_O,   H_M, \
  Z_C,    KC_X,    KC_C,   KC_V,    KC_J,        KC_K,    KC_P,    COMM,   DOT,    S_A, \
                   SFT1,   ALT,     RSPC,        ENT,    CBSPC,   SFT2                 \
),

/* EMACS(QGMLWY)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   G  |   M  |   L  |   W  |           |   Y  |   F  |   U  |   B  | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   D  |   S  |   T  |   N  |   R  |           |   I  |   A  |   E  |   O  |   H  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   J  |           |   K  |   P  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | SFT  | ALT  |      |    |      |  BS  | SFT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[EMACS] = LAYOUT( \
  KC_Q,   KC_G,    KC_M,  KC_L,    KC_W,         KC_Y,    KC_F,    KC_U,   KC_B,  DEL,  \
  D_M,    KC_S,    KC_T,  KC_N,    KC_R,         KC_I,    KC_A,    KC_E,   KC_O,  H_M,  \
  Z_C,    KC_X,    KC_C,  KC_V,    KC_J,         KC_K,    KC_P,    COMM,   DOT,   S_A,  \
                   SFT1,  ALT,     RSPC,         ENT,     CBSPC,   SFT3                 \
),

/* EMACS2(Shortcut Layer)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      | C-G  |      |      |      |           | M-.  | E-LT |  UP  | E-GT |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | C-S  | C-T  |      | C-@  |           | M-%  | LEFT | DOWN |RIGHT |C-M-S |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | C-Z  | C-X  | C-C  | C-V  | C-B  |           | M-x  | C-;  | C-:  | C-|  | M-;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | C-SL | M-D  |      |    |      |      |      |
 *                  `-------------|C-SPC |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[EMACS2] = LAYOUT( \
  _____, C_G,   _____,   _____,  _____,       M_DOT,    ELT,      C_P,    EGT,      _____,  \
  _____, C_S,   C_T,     _____,  C_AT,        M_PER,    C_LE,     C_N,    C_RI,     C_M_S,  \
  C_Z,   C_X,   C_C,     C_V,    C_B,         M_X,      C_SCLN,   C_COLN, C_PIPE,   M_SCLN, \
                C_SL,    M_D,    C_SPC,       _____,    _____,    _____                     \
),

/* LOWER
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |           |   &  |   '  |   `  |   |  | yen  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ESC |   [  |   (  |   }  |   \  |           |  ~   |   =  |   :  |   /  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ^   |   ]  |   )  |   }  |      |           |      |   -  |   ;  |   .  |   +  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = LAYOUT( \
  EXLM,    DQT,    HASH,  DLR,    PERC,     AMPR,    QUOT,  GRV,    PIPE, YEN,  \
  ESC,     LBRC,   LPRN,  LCBR,   BSLS,     TILD,    EQL,   COLN,   SLSH, ASTR, \
  CIRC,    RBRC,   RPRN,  RCBR,   _____,    _____,   MINS,  SCLN,   DOT,  PLUS, \
                   _____, _____,  _____,    _____,   _____, _____                       \
),

/* RAISE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  F1  |  F2  |  F3  |  F4  |           |  F5  |  F6  |   [  |   ]  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |  F7  |  F8  |  F9  |  F10 |           |  F11 |  F12 |   (  |   )  |   -  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT( \
  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,        KC_6,     KC_7,    KC_8,   KC_9,   KC_0, \
  TAB,     KC_F1,  KC_F2,  KC_F3,  KC_F4,       KC_F5,    KC_F6,   LBRC,   RBRC,   AT,   \
  UNDS,    KC_F7,  KC_F8,  KC_F9,  KC_F10,      KC_F11,   KC_F12,  LPRN,   RPRN,   MINS, \
                   _____,  _____,  _____,       _____,    _____,   _____                 \
),

/* MISC (GUI)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET | WhDn | MsUp | WhUp |WRKSP1|           |UWRKSP| PgDn |  Up  | PgUp |RESET |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | MsLf | MsDn | MsRg |WRKSP2|           |DWRKSP| Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | Copy |Paste | Hide |           |QGMLWY|EMACS |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | BTN2 | BTN1 |      |    |      | CTL  | ALT  |
 *                  `-------------| GUI  |    | GUI  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISC] = LAYOUT( \
  RESET,   WH_D,    MS_U,    WH_U,    WRKSP1,    UWRKSP,   PGDN,   GU,     PGUP,   RESET, \
  XXXXX,   MS_L,    MS_D,    MS_R,    WRKSP2,    DWRKSP,   GL,     GD,     GR,     XXXXX, \
  XXXXX,   XXXXX,   COPY,    PASTE,   GH,        DQ,       DE,     XXXXX,  XXXXX,  XXXXX, \
                    BTN2,    BTN1,    GUI,       GUI,      CTL,    CLT                    \
),

/* MISC2 (GUI)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET |      |      |      |      |           |      | PgDn |  Up  | PgUp |RESET |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | GAME1| GAME2| GAME3|      |           |      | Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | RTOG | RMOD | RHUI | RHUD |           | RSAI | RSAD | RRMOD|      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | CTL  |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISC2] =  LAYOUT( \
  RESET,   XXXXX,  XXXXX, XXXXX, XXXXX,        XXXXX,  PGDN,     KUP,    PGUP,    RESET, \
  XXXXX,   DG1,    DG2,   DG3,   XXXXX,        XXXXX,  KLEFT,    KDOWN,  KRIGHT,  XXXXX, \
  XXXXX,   RTOG,   RMOD,  RHUI,  RHUD,         RSAI,   RSAD,     RRMOD,  XXXXX,   XXXXX, \
                   _____, CTL,   _____,        _____,  _____,    _____                   \
),

/* GAME1(Diablo)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Esc  |  C   |  I   |  B   |  F   |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | ESC  | TAB  |      |    |      |      |      |
 *                  `-------------| CTRL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[GAME1] =  LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,        XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,         XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  XXXXX,   KC_C,   KC_I,   KC_B,   KC_F,         XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
                   KC_ESC, KC_TAB, KC_LCTRL,     DQ,     _____,    _____                   \
),

/* GAME2(BL2)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  TAB |  G   |  W   |  E   |  R  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT|  A   |  S   |  D   |  F   |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  C   |  Q   |  M   |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | ESC  |  V   |      |    |      |      |      |
 *                  `-------------| SPC  |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[GAME2] =  LAYOUT( \
  GTAB,    KC_G,   KC_W,   KC_E,   KC_R,        XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,        XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  KC_C,    KC_Q,   KC_M,   XXXXX,  XXXXX,       XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
                   KC_ESC, KC_V,   SPC,         DQ,     _____,    _____                   \
),
/* GAME3(WoL)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  TAB |  Q   |  W   |  E   |  R   |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  A   |  S   |  D   |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |  M   |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | ESC  |  F   |      |    |      |      |      |
 *                  `-------------| SPC  |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[GAME3] =  LAYOUT( \
  GTAB,    KC_Q,   KC_W,   KC_E,   KC_R,        XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  XXXXX,   KC_A,   KC_S,   KC_D,   XXXXX,       XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  XXXXX,   XXXXX,  KC_M,   XXXXX,  XXXXX,       XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
                   KC_ESC, KC_F,   SPC,         DQ,     _____,    _____                   \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
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
    case EMACS:
      rgblight_mode(7);
      break;
    case EMACS2:
      rgblight_mode(24);
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
