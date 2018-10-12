#include "minidox.h"
#include "pro_micro.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QGMLWY  0
#define LOWER   3
#define RAISE   4
#define MISCL   5
#define MISCR   6
#define GAME1   7
#define GAME2   8
#define GAME3   9
#define NONE    10
#define COMBA   11
#define COMBN   12

#define _____ KC_TRNS
#define XXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))

// Emacs shortcut
// C-A
#define C_A LCTL(KC_A)
// C-Z
#define C_Z LCTL(KC_Z)
// C-G
#define C_G LCTL(KC_G)
// C-X
#define C_X LCTL(KC_X)
// C-S
#define C_S LCTL(KC_S)
// C-C
#define C_C LCTL(KC_C)
// C-F
#define C_F LCTL(KC_F)
// C-E
#define C_E LCTL(KC_E)
// C-B
#define C_B LCTL(KC_B)
// C-O
#define C_O LCTL(KC_O)
// C-L
#define C_L LCTL(KC_L)
// C-R
#define C_R LCTL(KC_R)
// C-T
#define C_T LCTL(KC_T)
// C-Y
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
// C-,
#define C_COM LCTL(JP_COMM)
// C-.
#define C_DOT LCTL(JP_DOT)
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
// C-M-N
#define CMN LCTL(LALT(KC_N))
// C-M-M
#define CMM LCTL(LALT(KC_M))

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
#define DEL    KC_DEL
#define SPC    LT(RAISE, KC_SPC)
#define ENT    LT(LOWER,KC_ENT)
#define BS     KC_BSPC
#define BSPC   RCTL_T(KC_BSPC)
//#define GUI   LT(MISC,KC_LGUI)
#define D_M    LT(MISCL,KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define H_M    LT(MISCR,KC_H)
#define S_A    ALT_T(JP_SLSH)
#define GL     LGUI(KC_LEFT)
#define GU     LGUI(KC_UP)
#define GD     LGUI(KC_DOWN)
#define GR     LGUI(KC_RIGHT)
#define GH     LGUI(KC_H)
#define ELT    TD(E_LT)
#define EGT    TD(E_GT)
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
#define CTL    OSM(MOD_RCTL)
#define SFT1   SFT_T(JP_MHEN)
#define SFT2   SFT_T(JP_HENK)
#define SFTZ   SFT_T(JP_ZHTG)
#define ESC    KC_ESC
#define DQ     DF(QGMLWY)
#define DG1    DF(GAME1)
#define DG2    DF(GAME2)
#define DG3    DF(GAME3)
#define SELA   LCTL(KC_A)
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
#define CA     LT(COMBA,KC_A)
#define CN     LT(COMBN,KC_N)
#define CN2    CTL_T(KC_N)

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
 * |   Q  |   G  |   M  |   L  |   W  |           |   Y  |   F  |   U  |   B  | BSPC |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   D  |   S  |   T  |   N  |   R  |           |   I  |   A  |   E  |   O  |   H  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   J  |           |   K  |   P  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | SFT  | ALT  |      |    |      |  BSPC| SFT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[QGMLWY] = LAYOUT( \
  KC_Q,   KC_G,    KC_M,   KC_L,    KC_W,        KC_Y,    KC_F,    KC_U,   KC_B,  BS,  \
  D_M,    KC_S,    KC_T,   CN,      KC_R,        KC_I,    CA,      KC_E,   KC_O,  H_M, \
  Z_C,    KC_X,    KC_C,   KC_V,    KC_J,        KC_K,    KC_P,    COMM,   DOT,   S_A, \
                   SFTZ,   ALT,     SPC,         ENT,     BSPC,    SFTZ                \
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
 * |  TAB |  F1  |  F2  |  F3  |  F4  |           |  F5  |  F12 |   [  |   ]  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |  F7  |  F8  |  F9  |  F10 |           |  F11 |  F6  |   (  |   )  |   -  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT( \
  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,        KC_6,     KC_7,    KC_8,   KC_9,   KC_0, \
  TAB,     KC_F1,  KC_F2,  KC_F3,  KC_F4,       KC_F5,    KC_F12,  LBRC,   RBRC,   AT,   \
  UNDS,    KC_F7,  KC_F8,  KC_F9,  KC_F10,      KC_F11,   KC_F6,   LPRN,   RPRN,   MINS, \
                   _____,  _____,  _____,       _____,    _____,   _____                 \
),

/* MISC LEFT
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET | PgDn |      | PgUp |WRKSP1|           |UWRKSP| PgDn |  Up  | PgUp | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | SELA | GUI  |WRKSP2|           |DWRKSP| Left | Down |Right | Hide |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | COPY |PASTE |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISCL] = LAYOUT( \
  RESET,   PGDN,   _____,  PGUP,   WRKSP1,      UWRKSP,   PGDN,   GU,     PGUP,   DEL,    \
  _____,   _____,  SELA,   GUI,    WRKSP2,      DWRKSP,   GL,     GD,     GR,     GH,     \
  _____,   _____,  COPY,   PASTE,  _____,       _____,    _____,  _____,  _____,  _____,  \
                   _____,  _____,  _____,       _____,    _____,  _____                   \
),

/* MISC RIGHT
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ESC | GAME1| GAME2| GAME3| RTOG |           |      | PgDn |  Up  | PgUp |  DEL |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |      |      |      |      |           |      | Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | COPY | PASTE|      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISCR] =  LAYOUT( \
  ESC,     DG1,    DG2,   DG3,   RTOG,          _____,   PGDN,    KUP,    PGUP,   DEL,    \
  TAB,     _____,  _____, CN2,   _____,         _____,   KLEFT,   KDOWN,  KRIGHT, _____,  \
  _____,   _____,  COPY,  PASTE, _____,         _____,   _____,   _____,  _____,  _____,  \
                   _____, _____, _____,         _____,   _____,   _____                   \
),

/* COMBA
 *
 * ,----------------------------------.           ,----------------------------------.
 * | ZHTG |  C-G | C-M-M|  C-L |  M-% |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  M-D |  C-S |  C-T | C-M-N|      |           |      |      |   [  |      |  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  C-Z |  M-X |  C-C |      |      |           |      |      |   ]  |      |  C-\ |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBA] =  LAYOUT( \
  ZHTG,    C_G,   CMM,    C_L,     M_PER,          _____,  _____,    _____,  _____,   _____, \
  M_D,     C_S,   C_T,    CMN,     _____,          _____,  _____,    LBRC,   _____,   C_AT,  \
  C_Z,     M_X,   C_C,    _____,   _____,          _____,  _____,    RBRC,   _____,   C_SL,  \
                  _____,  _____,   _____,          _____,  _____,    _____                   \
),

/* COMBN
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  C-G |      |      |      |           |      | C-<  |  Up  |  C-> |  C-| |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |  M-; | Left | Down | Right|  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  C-X |      |      | C-SPC|           |      |      |  C-, |  C-. |  C-\ |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBN] =  LAYOUT( \
  _____,  C_G,     _____,  _____,  _____,        _____,  ELT,     KUP,    EGT,    C_PIPE, \
  _____,  _____,   _____,  _____,  _____,        M_SCLN, KLEFT,   KDOWN,  KRIGHT, C_AT,   \
  _____,  C_X,     _____,  _____,  C_SPC,        _____,  _____,   C_COM,  C_DOT,  C_SL ,  \
                   _____,  _____,  _____,        _____,  _____,   _____                   \
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
                   KC_ESC, KC_TAB, KC_LCTRL,     DQ,     DQ,       DQ                      \
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
                   KC_ESC, KC_V,   SPC,         DQ,     DQ,       DQ                   \
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
                   KC_ESC, KC_F,   SPC,         DQ,     DQ,       DQ                      \
),

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
    case LOWER:
      rgblight_mode(21);
      break;
    case RAISE:
      rgblight_mode(21);
      break;
    case MISCL:
      rgblight_mode(16);
      break;
    case MISCR:
      rgblight_mode(16);
      break;
    case COMBA:
      rgblight_mode(5);
      break;
    case COMBN:
      rgblight_mode(5);
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
