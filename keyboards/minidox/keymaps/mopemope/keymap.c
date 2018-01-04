#include "minidox.h"
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
#define MISC2   6
#define NONE    7

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
#define C_M_S LCTL(LALT(JP_BSLS))

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

//#define COLN  CTL_T(JP_COLN)
#define TAB    KC_TAB
//#define MINS  CTL_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define DEL    KC_DEL
#define SDEL   SFT_T(KC_DEL)
#define RAI    MO(RAISE)
#define SPC    LT(RAISE, KC_SPC)
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
//#define GUI   LT(MISC,KC_LGUI)
#define A_M    LT(MISC,KC_A)
#define Z_A    ALT_T(KC_Z)
#define A_C    CTL_T(KC_A)
#define O_M    LT(MISC,KC_O)
#define S_M    LT(MISC2,JP_SLSH)
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
#define MINS   JP_MINS
#define SCLN   JP_SCLN
#define COMM   JP_COMM
#define DOT    JP_DOT
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   JP_RBRC
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define ALT    KC_LALT
#define CTL    KC_LCTL
#define SFT    KC_LSFT
#define ESC    KC_ESC
#define DC     DF(COLEMAK)
#define DE     DF(EMACS)
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
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | CTL  | SFT  |      |    |      |  BS  | ALT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[COLEMAK] = KEYMAP( \
  KC_Q,   KC_W,    KC_F,   KC_P,    KC_G,        KC_J,    KC_L,    KC_U,   KC_Y,   DEL,  \
  A_M,    KC_R,    KC_S,   KC_T,    KC_D,        KC_H,    KC_N,    KC_E,   KC_I,   O_M,  \
  Z_A,    KC_X,    KC_C,   KC_V,    KC_B,        KC_K,    KC_M,    COMM,   DOT,    S_M,  \
                   CTL,    SFT,     SPC,         ENT,     SBSPC,   ALT                   \
),

/* EMACS(COLEMAK)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  | DEL  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | CTL  | SFT  |      |    |      |  BS  | ALT  |
 *                  `-------------| SPC  |    | ENT  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[EMACS] = KEYMAP( \
  KC_Q,   KC_W,    KC_F,  KC_P,    KC_G,         KC_J,    KC_L,    KC_U,   KC_Y,  DEL, \
  A_M,    KC_R,    KC_S,  KC_T,    KC_D,         KC_H,    KC_N,    KC_E,   KC_I,  O_M,  \
  Z_A,    KC_X,    KC_C,  KC_V,    KC_B,         KC_K,    KC_M,    COMM,   DOT,   S_M,  \
                   CTL,   SFT,     SPC,          ENT,     EBSPC,   ALT                  \
),

/* EMACS2(COLEMAK Shortcut Layer)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET | M-W  | C-F  | C-Y  | C-G  |           | M-.  | E-LT |  UP  | E-GT |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | C-A  | C-R  | C-S  | C-T  | C-@  |           | M-%  | LEFT | DOWN |RIGHT |C-M-S |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | C-Z  | C-X  | C-C  | C-V  | C-B  |           | M-x  | C-;  | C-:  | C-|  | M-;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | C-SL | M-D  |      |    |      |      |      |
 *                  `-------------|C-SPC |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[EMACS2] = KEYMAP( \
  _______, M_W,     C_F,    C_Y,   C_G,         M_DOT,    ELT,        C_P,    EGT,      _______, \
  C_A,     C_R,     C_S,    C_T,   C_AT,        M_PER,    C_LE,       C_N,    C_RI,     C_M_S,   \
  C_Z,     C_X,     C_C,    C_V,   C_B,         M_X,      C_SCLN,     C_COLN, C_PIPE,   M_SCLN,  \
                    C_SL,   M_D,   C_SPC,       _______,  _______,    _______                    \
),

/* LOWER (Symbol)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |           |   &  |   '  |   `  |   |  | yen  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ESC |   @  |   {  |   }  |   _  |           |  ~   |   =  |   :  |   /  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |   (  |   )  |   \  |           |  ^   |   -  |   ;  |   .  |   +  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | DEL  |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = KEYMAP( \
  EXLM,     DQT,     HASH,    DLR,      PERC,     AMPR,    QUOT,    GRV,    PIPE, YEN,  \
  ESC,      AT,      LCBR,    RCBR,     UNDS,     TILD,    EQL,     COLN,   SLSH, ASTR, \
  XXXXXXX,  XXXXXXX, LPRN,    RPRN,     BSLS,     CIRC,    MINS,    SCLN,   DOT,  PLUS, \
                     _______, _______,  _______,  _______, DEL,     _______             \
),

/* RAISE (Num + Fn + Others)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB |  F1  |  F2  |  F3  |  F4  |           |  F5  |  F6  |   [  |   ]  |   @  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |  F7  |  F8  |  F9  |  F10 |           |  F11 |  F12 |   (  |   )  |   -  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | DEL  |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = KEYMAP( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,   KC_9,   KC_0, \
  TAB,     KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,   LBRC,   RBRC,   AT,   \
  UNDS,    KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,  KC_F12,  LPRN,   RPRN,   MINS, \
                    _______, _______, _______,      _______, DEL,     _______               \
),

/* MISC (GUI)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET | WhDn | MsUp | WhUp |WRKSP1|           |UWRKSP| PgDn |  Up  | PgUp |RESET |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | MsLf | MsDn | MsRg |WRKSP2|           |DWRKSP| Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | Copy |Paste | ZHTG |           |COLEMA|EMACS | ASTG |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | BTN2 | BTN1 |      |    |      | CTL  | ALT  |
 *                  `-------------| GUI  |    | GUI  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISC] = KEYMAP( \
  RESET,   WH_D,    MS_U,    WH_U,    WRKSP1,    UWRKSP,   PGDN,    KUP,     PGUP,    RESET,   \
  XXXXXXX, MS_L,    MS_D,    MS_R,    WRKSP2,    DWRKSP,   KLEFT,   KDOWN,   KRIGHT,  XXXXXXX, \
  XXXXXXX, XXXXXXX, COPY,    PASTE,   ZHTG,      DC,       DE,      ASTG,    XXXXXXX, XXXXXXX, \
                    BTN2,    BTN1,    GUI,       GUI,      CTL,     ALT                        \
),

/* MISC2 (GUI)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET |      |      |      |      |           |      |      |  Up  |      |RESET |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           | Hide | Left | Down |Right |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | ALT  | GUI  |      |    |      | GUI  | ALT  |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[MISC2] =  KEYMAP( \
  RESET,   _______, _______, _______, _______,      _______, _______, GU,      _______, RESET,   \
  _______, _______, _______, _______, _______,      GH,      GL,      GD,      GR,      _______, \
  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, \
                    ALT,     GUI,     _______,      _______, GUI,     ALT                        \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
