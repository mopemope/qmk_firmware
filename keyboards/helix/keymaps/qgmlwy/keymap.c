#include "helix.h"
#include "bootloader.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#include "LUFA/Drivers/Peripheral/TWI.h"
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define QGMLWY  0
#define EMACS   1
#define EMACS2  2
#define LOWER   3
#define RAISE   4
#define MISC    5
#define MISC2   6
#define NONE    7

#define ____   KC_TRNS
#define XXXX   KC_NO

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
#define CBSPC  CTL_T(KC_BSPC)
//#define GUI   LT(MISC,KC_LGUI)
#define A_M    LT(MISC,KC_A)
#define D_M    LT(MISC,KC_D)
#define Z_A    ALT_T(KC_Z)
#define A_C    CTL_T(KC_A)
#define O_M    LT(MISC2,KC_O)
#define H_M    LT(MISC2,KC_H)
#define S_M    LT(MISC2,JP_SLSH)
#define S_C    CTL_T(JP_SLSH)
#define O_C    CTL_T(KC_O)
#define AT_M   LT(MISC,JP_AT)
#define AT_A   ALT_T(JP_AT)
#define AT_C   CTL_T(JP_AT)
#define M2     MO(MISC2)
#define EM2    MO(EMACS2)
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
#define ALT    OSM(MOD_LALT)
#define CTL    OSM(MOD_LCTL)
#define SFT1   SFT_T(JP_MHEN)
#define SFT2   SFT_T(JP_HENK)
#define SFT3   LT(EMACS2,JP_HENK)
#define ESC    KC_ESC
#define DQ     DF(QGMLWY)
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

#define RTOG  RGB_TOG
#define RMOD  RGB_MOD
#define RRMOD RGB_RMOD
#define RHUI  RGB_HUI
#define RHUD  RGB_HUD
#define RSAI  RGB_SAI
#define RSAD  RGB_SAD
#define RVAI  RGB_VAI
#define RVAD  RGB_VAD

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


#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QGMLWY
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   G  |   M  |   L  |   W  |             |   Y  |   F  |   U  |   B  |   :  |  @   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  _   |   D  |   S  |   T  |   N  |   R  |             |   I  |   A  |   E  |   O  |   H  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CTL  |   Z  |   X  |   C  |   V  |   J  | CTL  | ALT  |   K  |   P  |   ,  |   .  |   /  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |EMACS |QGMLWY|      | GUI  | SFT  | ALT  | SPC  | ENT  |  BS  | SFT  | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [QGMLWY] = KEYMAP( \
      ESC,   KC_1,  KC_2,   KC_3,  KC_4,  KC_5,               KC_6,   KC_7,  KC_8,  KC_9,  KC_0,  PIPE,  \
      TAB,   KC_Q,  KC_G,   KC_M,  KC_L,  KC_W,               KC_Y,   KC_F,  KC_U,  KC_B,  COLN,  AT,    \
      UNDS,  D_M,   KC_S,   KC_T,  KC_N,  KC_R,               KC_I,   KC_A,  KC_E,  KC_O,  H_M,   MINS,  \
      CTL,   KC_Z,  KC_X,   KC_C,  KC_V,  KC_J,  CTL,   ALT,  KC_K,   KC_P,  COMM,  DOT,   S_M,   SBSLS, \
      DE,    DQ,    XXXX,   GUI,   SFT1,  ALT,   SPC,   ENT,  CBSPC,  SFT2,  KLEFT, KDOWN, KUP,   KRIGHT \
   ),

  /* Emacs
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   G  |   M  |   L  |   W  |             |   Y  |   F  |   U  |   B  |   :  |  @   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  _   |   D  |   S  |   T  |   N  |   R  |             |   I  |   A  |   E  |   O  |   H  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CTL  |   Z  |   X  |   C  |   V  |   J  | CTL  | EM2  |   K  |   P  |   ,  |   .  |   /  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |EMACS |QGMLWY|      | GUI  | SFT  | ALT  | SPC  | ENT  |  BS  | SFT  | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [EMACS] = KEYMAP( \
      ESC,   KC_1,  KC_2,   KC_3,  KC_4,  KC_5,               KC_6,   KC_7,  KC_8,  KC_9,  KC_0,  PIPE,  \
      TAB,   KC_Q,  KC_G,   KC_M,  KC_L,  KC_W,               KC_Y,   KC_F,  KC_U,  KC_B,  COLN,  AT,    \
      UNDS,  D_M,   KC_S,   KC_T,  KC_N,  KC_R,               KC_I,   KC_A,  KC_E,  KC_O,  H_M,   MINS,  \
      CTL,   KC_Z,  KC_X,   KC_C,  KC_V,  KC_J,  CTL,   EM2,  KC_K,   KC_P,  COMM,  DOT,   S_M,   SBSLS, \
      DE,    DQ,    XXXX,   GUI,   SFT1,  ALT,   SPC,   ENT,  CBSPC,  SFT3,  KLEFT, KDOWN, KUP,   KRIGHT \
   ),

  /* Emacs2
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      | C-G  |      |      |      |             | M-.  | E-LT |  UP  | E-GT |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      | C-S  | C-T  |      | C-@  |             | M-%  | LEFT | DOWN |RIGHT |C-M-S |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | C-Z  | C-X  | C-C  | C-V  | C-B  |      |      | M-X  | C-;  | C-:  | C-|  | M-;  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | C-SL | M-D  | C-SPC|      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [EMACS2] = KEYMAP( \
      ____,  ____,  ____,   ____,  ____,  ____,                ____,  ____,  ____,   ____,  ____,   ____, \
      ____,  ____,  C_G,    ____,  ____,  ____,                M_DOT, ELT,   C_P,    EGT,   ____,   ____, \
      ____,  ____,  C_R,    C_S,   ____,  C_AT,                M_PER, C_LE,  C_N,    C_RI,  C_M_S,  ____, \
      ____,  C_Z,   C_X,    C_C,   C_V,   C_B,   ____,  ____,  M_X,   C_SCLN,C_COLN, C_PIPE,M_SCLN, ____, \
      ____,  ____,  ____,   ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,   ____,  ____,   ____  \
   ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  !   |  "   |  #   |  $   |  %   |             |  &   |  '   |  `   |  |   | yen  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |  @   |  {   |  }   |  _   |             |  ~   |  =   |  :   |  /   |  *   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |  (   |  )   |  \   |      |      |  ^   |  -   |  ;   |  .   |  +   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [LOWER] = KEYMAP( \
      ____,  ____,  ____,   ____,  ____,  ____,                ____,  ____,  ____,   ____,  ____,  ____, \
      ____,  EXLM,  DQT,    HASH,  DLR,   PERC,                AMPR,  QUOT,  GRV,    PIPE,  YEN,   ____, \
      ____,  ESC,   AT,     LCBR,  RCBR,  UNDS,                TILD,  EQL,   COLN,   SLSH,  ASTR,  ____, \
      ____,  ____,  ____,   LPRN,  RPRN,  BSLS, ____,   ____,  CIRC,  MINS,  SCLN,   DOT,   PLUS,  ____, \
      ____,  ____,  ____,   ____,  ____,  ____, ____,   ____,  DEL,   ____,  ____,   ____,  ____,  ____  \
   ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  1   |  2   |  3   |  4   |  5   |             |  6   |  7   |  8   |  9   |  0   |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | TAB  |  F1  |  F2  |  F3  |  F4  |             |  F5  |  F6  |  [   |  ]   |  @   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  _   |  F7  |  F8  |  F9  |  F10 |      |      |  F11 |  F12 |  (   |  )   |  -   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |  ALT |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [RAISE] = KEYMAP( \
      ____,  ____,  ____,   ____,  ____,  ____,                ____,  ____,  ____,   ____,  ____,  ____, \
      ____,  KC_1,  KC_2,   KC_3,  KC_4,  KC_5,                KC_6,  KC_7,  KC_8,   KC_9,  KC_0,  ____, \
      ____,  TAB,   KC_F1,  KC_F2, KC_F3, KC_F4,               KC_F5, KC_F6, LBRC,   RBRC,  AT,    ____, \
      ____,  UNDS,  KC_F7,  KC_F8, KC_F9, KC_F10,____,   ____, KC_F11,KC_F12,LPRN,   RPRN,  MINS,  ____, \
      ____,  ____,  ____,   ____,  ____,  ____,  ____,   ____, ALT,   ____,  ____,   ____,  ____,  ____  \
   ),

  /* Misc
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RESET | WhDn | MsUp | WhUp |WRKSP1|             |UWRKSP| PgDn |  Up  | PgUp |RESET |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RESET |      | MsLf | MsDn | MsRg |WRKSP2|             |DWRKSP| Left | Down |Right |      |RESET |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      | Copy | Paste| Hide |      |      |COLEMA|EMACS | ASTG |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | BTN2 | BTN1 | GUI  | GUI  | CTL  | ALT  |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [MISC] = KEYMAP( \
      ____,  ____,  ____,  ____,  ____,  ____,                ____,   ____,  ____,  ____,  ____,  ____,  \
      ____,  RESET, WH_D,  MS_U,  WH_U,  WRKSP1,              UWRKSP, PGDN,  GU,    PGUP,  RESET, ____,  \
      RESET, ____,  MS_L,  MS_D,  MS_R,  WRKSP2,              DWRKSP, GL,    GD,    GR,    ____,  RESET, \
      ____,  ____,  ____,  COPY,  PASTE, GH,    ____,   ____, DQ,     DE,    ASTG,  ____,  ____,  ____,  \
      ____,  ____,  ____,  ____,  BTN2,  BTN1,  GUI,    GUI,  CTL,    ALT,   ____,  ____,  ____,  ____   \
   ),

  /* Misc2
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RESET |      |      |      |      |             |      | PgDn |  Up  | PgUp |RESET |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RESET |      |      |      |      |      |             |      | Left | Down |Right |      |RESET |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | RTOG | RMOD | RHUI | RHUD |      |      | RSAI | RSAD |RRMOD |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [MISC2] = KEYMAP( \
      ____,  ____,  ____,  ____,  ____,  ____,                ____,  ____,  ____,   ____,  ____,  ____,  \
      ____,  RESET, ____,  ____,  ____,  ____,                ____,  PGDN,  KUP,    PGUP,  RESET, ____,  \
      RESET, ____,  ____,  ____,  ____,  ____,                ____,  KLEFT, KDOWN,  KRIGHT,____,  RESET, \
      ____,  ____,  RTOG,  RMOD,  RHUI,  RHUD,  ____,   ____, RSAI,  RSAD,  RRMOD,  ____,  ____,  ____,  \
      ____,  ____,  ____,  ____,  ____,  ____,  ____,   ____, ____,  ____,   ____,  ____,  ____,  ____   \
   ),

};

#else
#error "undefined keymaps"
#endif


// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
  rgblight_disable();
  rgblight_setrgb(255, 255, 255);
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}

#ifdef RGBLIGHT_ENABLE
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
    case 0:
        rgblight_mode(5);
        break;
    case 1:
        rgblight_mode(5);
        break;
    case 2:
        rgblight_mode(5);
        break;
    case 3:
        rgblight_mode(22);
        break;
    case 4:
        rgblight_mode(22);
        break;
    case 5:
        rgblight_mode(16);
        break;
    case 6:
        rgblight_mode(16);
        break;
    case 7:
        break;
    default:
        break;
    }
    return state;
}
#endif

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}

void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLAYER : "));
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case 0:
      matrix_write_P(matrix, PSTR("QGMLWY"));
      break;
    case 1:
      matrix_write_P(matrix, PSTR("EMACS"));
      break;
    case 2:
      matrix_write_P(matrix, PSTR("EMACS2"));
      break;
    case 3:
      matrix_write_P(matrix, PSTR("LOWER"));
      break;
    case 4:
      matrix_write_P(matrix, PSTR("RAISE"));
      break;
    case 5:
      matrix_write_P(matrix, PSTR("GUI"));
      break;
    case 6:
      matrix_write_P(matrix, PSTR("MISC"));
      break;
    case 7:
      break;
    default:
      break;
  }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
