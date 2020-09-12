#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QGMLWY  0
#define LOWER   1
#define RAISE   2
#define MISCL   3
#define MISCR   4
#define COMBA   5
#define COMBN   6
#define COMBE   7
#define COMBT   8
#define GAME1   9
#define GAME2  10
#define GAME3  11
#define GAME4  12
#define GAME5  13
#define GAME6  14
#define GAME7  15

#define _____ KC_TRNS
#define XXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))
#define UWRKSP LSFT(LALT(LCTL(KC_UP)))
#define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))
#define PREVTB LSFT(LCTL(KC_UP))
#define NEXTTB LSFT(LCTL(KC_DOWN))
#define CAF2   LALT(LCTL(KC_F2))
#define CAF7   LALT(LCTL(KC_F7))
#define PREVW  LGUI(LCTL(KC_LEFT))
#define NEXTW  LGUI(LCTL(KC_RIGHT))

#define TAB    KC_TAB
#define MINS   ALT_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define BSP    KC_BSPC
#define DEL    KC_DEL
#define SDEL   SFT_T(KC_DEL)
#define PSCR   KC_PSCR
#define SPSCR  LSFT(KC_PSCR)
#define RJ     LT(RAISE,KC_J)
#define LK     LT(LOWER,KC_K)
#define AC     LT(COMBA,KC_A)
#define NC     LT(COMBN,KC_N)
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
#define I_S    LSFT_T(KC_I)
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
#define CLEFT  LCTL(KC_LEFT)
#define CUP    LCTL(KC_UP)
#define CDOWN  LCTL(KC_DOWN)
#define CRIGHT LCTL(KC_RIGHT)
#define MLEFT  LALT(KC_LEFT)
#define MUP    LALT(KC_UP)
#define MDOWN  LALT(KC_DOWN)
#define MRIGHT LALT(KC_RIGHT)
#define MLT    LALT(KC_LT)
#define MGT    LALT(KC_GT)
#define GH     LGUI(KC_H)
#define GTAB   TD(G_TAB)
#define FG     TD(D_FG)
#define VB     TD(D_VB)
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
#define DG1    DF(GAME1)
#define DG2    DF(GAME2)
#define DG3    DF(GAME3)
#define DG4    DF(GAME4)
#define DG5    DF(GAME5)
#define DG6    DF(GAME6)
#define DG7    DF(GAME7)
#define SELA   LCTL(KC_A)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define CZ     LCTL(KC_Z)
#define CSL    LCTL(JP_SLSH)
#define CF     LCTL(KC_F)
#define CMN    LALT(LCTL(KC_N))
#define CMM    LALT(LCTL(KC_M))
#define CMD    LALT(LCTL(JP_DOT))
#define CMY    LALT(LCTL(JP_YEN))
#define CG     LCTL(KC_G)
#define CQ     LCTL(KC_Q)
#define CT     LCTL(KC_T)
#define CC     LCTL(KC_C)
#define CS     LCTL(KC_S)
#define CX     LCTL(KC_X)
#define CL     LCTL(KC_L)
#define CK     LCTL(KC_K)
#define CE     LCTL(KC_E)
#define CP     LCTL(KC_P)
#define CN     LCTL(KC_N)
#define CAT    LCTL(JP_AT)
#define MX     LALT(KC_X)
#undef  MD
#define MD     LALT(KC_D)
#define MSCLN  LALT(JP_SCLN)
#define APERC  LALT(JP_PERC)
#define CPIPE  LCTL(JP_PIPE)

#define WH_D   KC_WH_D
#define WH_U   KC_WH_U
#define PGDN   KC_PGDN
#define PGUP   KC_PGUP
#define MS_L   KC_MS_L
#define MS_U   KC_MS_U
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
#define ALT    OSM(MOD_LALT)
#define SFTZ   SFT_T(JP_ZHTG)
#define C_V    LCTL(KC_V)
#define M_V    LALT(KC_V)
#define C_LT   LCTL(JP_LT)
#define C_GT   LCTL(JP_GT)

enum double_taps {
  G_TAB = 0,
  D_FG = 1,
  D_VB = 2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [G_TAB] = ACTION_TAP_DANCE_DOUBLE (KC_TAB, KC_ESC),
  [D_FG] =  ACTION_TAP_DANCE_DOUBLE (KC_F, KC_G),
  [D_VB] =  ACTION_TAP_DANCE_DOUBLE (KC_V, KC_B),
};

enum custom_keycodes {
  CXCF = SAFE_RANGE,
  CXCB,
  CXCS,
  CXO,
  CXU,
  CCN,
  CCP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QGMLWY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   G  |   M  |   L  |   W  |           |   Y  |   F  |   U  |   B  | BSPC |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   D  |   S  |   T  |   N  |   R  |           |   I  |   A  |   E  |   O  |   H  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |      |           |      |   J  |   K  |   P  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | SFT  | ALT  |      |    |      |  BSPC| SFT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[QGMLWY] = LAYOUT( \
  KC_Q,   KC_G,    KC_M,   KC_L,    KC_W,        KC_Y,    KC_F,    KC_U,   KC_B,   BSP, \
  D_M,    KC_S,    TC,     NC,      KC_R,        KC_I,    AC,      EC,     KC_O,   H_M, \
  Z_S,    X_CT,    KC_C,   V_A,     _____,       _____,   J_C,     KC_K,   P_AL,   S_S, \
                   SFTZ,   ALT,     SPC,         ENT,     BSPC,    SFTZ                 \
),


/* LOWER
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |           |   &  |   '  |   `  |   |  | yen  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ESC |   (  |   )  |   {  |   }  |           |  ~   |   +  |   *  |   =  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ^   |   [  |  ]   |   <  |   >  |           |      |      |      |      |     |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = LAYOUT( \
  EXLM,    DQT,    HASH,  DLR,    PERC,     AMPR,    QUOT,  GRV,    PIPE,  YEN,    \
  ESC,     LPRN,   RPRN,  LCBR,   RCBR,     TILD,    PLUS,  ASTR,   EQL,   AT,     \
  CIRC,    LBRC,   RBRC,  KC_LT,  KC_GT,    _____,   _____, _____,  _____, _____,  \
                   _____, _____,  _____,    _____,   _____, _____                  \
),

/* RAISE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  F1  |  F2  |  F3  |  F4  |           |  F5  |  F12 |  F7  |  F8  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |  F9  |  F10 |  F11 |      |           |  DOT |  F6  |   <  |   >  |   -  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT( \
  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,        KC_6,     KC_7,    KC_8,   KC_9,   KC_0, \
  TAB,     KC_F1,  KC_F2,  KC_F3,  KC_F4,       KC_F5,    KC_F12,  KC_F7,  KC_F8,  AT,   \
  UNDS,    KC_F9,  KC_F10, KC_F11, _____,       DOT,      KC_F6,   KC_LT,  KC_GT,  MINS, \
                   _____,  _____,  _____,       DOT,      _____,   _____                 \
),

/* MISC LEFT
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET |      |  UP  |      |WRKSP1|           |UWRKSP| PgDn |  Up  | PgUp | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | LEFT | DOWN |RIGHT |WRKSP2|           |DWRKSP| Left | Down |Right | Hide |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | COPY |PASTE |      |    |      |      |      |
 *                  `-------------|  GUI |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISCL] = LAYOUT( \
  RESET,   _____,  KUP  ,  _____,  WRKSP1,      UWRKSP,   PGDN,   GU,     PGUP,   DEL,    \
  _____,   KLEFT,  KDOWN,  KRIGHT, WRKSP2,      DWRKSP,   GL,     GD,     GR,     GH,     \
  _____,   _____,  _____,  _____,  _____,       MLT,      MGT,    SPSCR,  _____,  _____,  \
                   COPY,   PASTE,  GUI,         _____,    _____,  _____                   \
),

/* MISC RIGHT
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|      |      |      | PREVW|           |PREVTB|  MLT |  UP  | MGT  |  DEL |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |      |      |      | NEXTW|           |NEXTTB| LEFT | DOWN |RIGHT |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISCR] =  LAYOUT( \
  RESET,   _____,  _____, _____,  PREVW,         PREVTB,  MLT,     KUP,    MGT,    DEL,    \
  TAB,     _____,  _____, _____,  NEXTW,         NEXTTB,  KLEFT,   KDOWN,  KRIGHT, _____,  \
  _____,   _____,  _____, _____,  _____,         _____,   _____,   _____,  _____,  _____,  \
                   _____, _____,  _____,         _____,   _____,   _____                   \
),

/* COMBA
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  C-Q |  C-G | C-M-M|  C-L |  M-% |           |      | CXCF | CXU  | CXCB |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  M-D | CXCS |  C-T | C-M-N|  M-X |           |      |      | C-Q  | CXO  |  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  C-Z |  C-X |  C-C |      |      |           |      |      | C-K  |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------| ZHTG |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBA] =  LAYOUT( \
   CQ,     CG,    CMM,    CL,      APERC,         _____,  CXCF,   CXU,   CXCB,   _____,  \
   MD,     CXCS,  CT,     CMN,     MX,            _____,  _____,  CQ,    CXO,    CAT,    \
   CZ,     CX,    CC,     _____,   _____,         _____,  _____,  CK,    _____,  _____,  \
                  _____,  _____,   ZHTG,          _____,  _____,  _____                  \
),

/* COMBN
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  C-G |      |  C-L |      |           | C-M-Y| CCP  |  UP  | CCN  |  M-D |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  C-S |  C-T |      |      |           |  M-; | LEFT | DOWN | RIGHT|  C-@ |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  C-X |  CRET| CSPC |      |           |  M-, | M-.  |  C-, |  C-. |  CXU |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBN] =  LAYOUT( \
  _____,   CG,   _____,  CL,     _____,        CMY,    CCP,     CUP,    CCN,    MD,    \
  TAB,     CS,   CT,     _____,  _____,        MSCLN,  CLEFT,   CDOWN,  CRIGHT, CAT,   \
  _____,   CX,   CRET,   CSPC,   _____,        MCOM,   MDOT,    CCOM,   CDOT,   CXU ,  \
                 _____,  _____,  _____,        _____,  _____,   _____                  \
),

/* COMBE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |  CUP |      |      |           | DQG  |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | CLEFT| CDOWN|CRIGHT|      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | PSCR | CAF2 | CAF7 |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBE] =  LAYOUT(                                                                       \
   _____,  _____, CUP,    _____,  _____,          DQG,    _____,  _____, _____,  _____,  \
   _____,  CLEFT, CDOWN,  CRIGHT, _____,          _____,  _____,  _____, _____,  _____,  \
   _____,  _____, PSCR,   CAF2,   CAF7,           _____,  _____,  _____, _____,  _____,  \
                  _____,  _____,  _____,          _____,  _____,  _____                  \
),

/* COMBT
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  DG1 |  DG2 |  DG3 |      |      |           |   "  |  !   |   +  |   *  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   ~  |  =   |   :  |   ;  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |  -   |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COMBT] =  LAYOUT( \
  DG1,    DG2,   DG3,    _____,  _____,        DQT,    EXLM,    PLUS,   ASTR,   PIPE,  \
  _____,  _____, _____,  _____,  _____,        TILD,   EQL,     COLN,   SCLN,   AT,    \
  _____,  _____, _____,  _____,  _____,        _____,  MINS,    COMM,   DOT,    SLSH,  \
                 _____,  _____,  _____,        _____,  _____,   _____                  \
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
                   KC_ESC, KC_TAB, KC_LCTRL,     DQG,     DQG,       DQG                      \
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
                   KC_ESC, KC_V,   SPC,         DQG,     DQG,       DQG                   \
),

/* GAME3(V)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  TAB |  Q   |  W   |  E   |  R   |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  SFT |  A   |  S   |  D   |  F   |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  CTL |  Z   |  M   |  C   |  V   |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | ESC  |  C   |      |    |      |      |      |
 *                  `-------------|  4   |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[GAME3] =  LAYOUT( \
  GTAB,    KC_Q,  KC_W,   KC_E,   KC_R,        XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  KC_LSFT, KC_A,  KC_S,   KC_D,   FG,          XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
  KC_LCTL, KC_Z,  KC_M,   KC_C,   VB,          XXXXX,  XXXXX,    XXXXX,  XXXXX,   XXXXX, \
                  KC_ESC, KC_C,   KC_4,        DQG,    DQG,      DQG                     \
),

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CXCF:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xf"));
      }
    break;
  case CXCB:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xb"));
    }
    break;
  case CXCS:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xs"));
    }
    break;
  case CXO:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x") "o");
    }
    break;
  case CXU:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x") "u");
    }
    return false;
  case CCN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "n");
    }
    return false;
  case CCP:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "p");
    }
    return false;
  }
  return true;
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
    case COMBE:
      rgblight_mode(6);
      break;
    case COMBT:
      rgblight_mode(6);
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
