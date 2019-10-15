#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "pro_micro.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define QGMLWY  0
#define LOWER   3
#define RAISE   4
#define MISC    5
#define MISC2   6
#define GAME1   7
#define GAME2   8
#define GAME3   9

#define KC______  KC_TRNS
#define KC_XXXXX  KC_NO
#define KC_LOWER  LOWER
#define KC_RAISE  RAISE
#define KC_RST    RESET
#define KC_JMINS  ALT_T(JP_MINS)
#define KC_LENT   LT(LOWER,KC_ENT)
#define KC_RSPC   LT(RAISE, KC_SPC)
#define KC_CBSPC  CTL_T(KC_BSPC)
#define KC_ADEL   ALT_T(KC_DEL)
#define KC_JAT1   ALT_T(JP_AT)
#define KC_SFT1   SFT_T(JP_MHEN)
#define KC_SFT2   SFT_T(JP_HENK)
#define KC_SFT3   SFT_T(JP_ZHTG)
#define KC_ALT1   OSM(MOD_RALT)
#define KC_CTL1   OSM(MOD_LCTL)
#define KC_MISC   LT(MISC,KC_TAB)
#define KC_MISC2  LT(MISC2,KC_TAB)
#define KC_DM     LT(MISC,KC_D)
#define KC_CZ     CTL_T(KC_Z)
#define KC_HM     LT(MISC2,KC_H)
#define KC_JEXLM  JP_EXLM
#define KC_JDQT   JP_DQT
#define KC_JHASH  JP_HASH
#define KC_JDLR   JP_DLR
#define KC_JPERC  JP_PERC
#define KC_JAMPR  JP_AMPR
#define KC_JQUOT  JP_QUOT
#define KC_JGRV   JP_GRV
#define KC_JPIPE  JP_PIPE
#define KC_JY     JP_YEN
#define KC_JAT    JP_AT
#define KC_JLCBR  JP_LCBR
#define KC_JRCBR  JP_RCBR
#define KC_JUNDS  JP_UNDS
#define KC_JTILD  JP_TILD
#define KC_JEQL   JP_EQL
#define KC_JCOLN  JP_COLN
#define KC_JSLSH  JP_SLSH
#define KC_JSL1   ALT_T(JP_SLSH)
#define KC_JASTR  JP_ASTR
#define KC_JLPRN  JP_LPRN
#define KC_JRPRN  JP_RPRN
#define KC_JBSLS  JP_BSLS
#define KC_JCIRC  JP_CIRC
#define KC_JSCLN  JP_SCLN
#define KC_JCOMM  JP_COMM
#define KC_JDOT   JP_DOT
#define KC_JPLUS  JP_PLUS
#define KC_JLBRC  JP_LBRC
#define KC_JRBRC  JP_RBRC
#define KC_JZHTG  JP_ZHTG
#define KC_JUNDS  JP_UNDS
#define KC_WRK1   LALT(LCTL(KC_UP))
#define KC_WRK2   LALT(LCTL(KC_DOWN))
#define KC_UWRK   LSFT(LALT(LCTL(KC_UP)))
#define KC_DWRK   LSFT(LALT(LCTL(KC_DOWN)))
#define KC_COPY   LCTL(KC_C)
#define KC_PASTE  LCTL(KC_V)
#define KC_KLEFT  KC_LEFT
#define KC_KUP    KC_UP
#define KC_KDOWN  KC_DOWN
#define KC_KRIGHT KC_RIGHT
#define KC_GL     LGUI(KC_LEFT)
#define KC_GU     LGUI(KC_UP)
#define KC_GD     LGUI(KC_DOWN)
#define KC_GR     LGUI(KC_RIGHT)
#define KC_GH     LGUI(KC_H)
#define KC_HIDE   LGUI(KC_H)
#define KC_RTOG   RGB_TOG
#define KC_RMOD   RGB_MOD
#define KC_RRMOD  RGB_RMOD
#define KC_RHUI   RGB_HUI
#define KC_RHUD   RGB_HUD
#define KC_RSAI   RGB_SAI
#define KC_RSAD   RGB_SAD
#define KC_RVAI   RGB_VAI
#define KC_RVAD   RGB_VAD
#define KC_DQ     DF(QGMLWY)
#define KC_DG1    DF(GAME1)
#define KC_DG2    DF(GAME2)
#define KC_DG3    DF(GAME3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QGMLWY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ESC,     Q,     G,     M,     L,     W,                      Y,     F,     U,     B, JCIRC,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      MISC,    DM,     S,     T,     N,     R,                      I,     A,     E,     O,    HM, MISC2,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTL1,    CZ,     X,     C,     V,     J,                      K,     P, JCOMM,  JDOT,  JSL1,  JAT1,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  SFT3,  ALT1,   RSPC,    LENT, CBSPC,  SFT3 \
                              //`--------------------'  `--------------------'
  ),

  [LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     _____,  JEXLM, JDQT, JHASH,  JDLR, JPERC,                  JAMPR, JQUOT,   JGRV,JPIPE,    JY, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _____,  JCIRC,JLBRC, JLPRN, JLCBR, JBSLS,                  JTILD,  JEQL,  JCOLN,JSLSH, JASTR, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _____, _____, JRBRC, JRPRN, JRCBR, _____,                  _____, JMINS,  JSCLN, JDOT, JPLUS, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 _____, _____, _____,     _____,_____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     _____,      1,    2,     3,     4,     5,                      6,     7,      8,    9,     0, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _____,     F1,   F2,    F3,    F4,    F5,                     F6,    F7,     F8,  F10,   JAT, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _____,  JUNDS,_____, _____, _____, _____,                    F11,   F12,  _____,_____, JMINS, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 _____, _____, _____,     _____,_____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [MISC] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       RST,  XXXXX,  WH_D,  MS_U,  WH_U,  WRK1,                   UWRK,  PGDN,    GU,  PGUP, XXXXX,   RST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     XXXXX,  XXXXX,  MS_L,  MS_D,  MS_R,  WRK2,                   DWRK,    GL,    GD,    GR, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     XXXXX,  _____, _____,  COPY, PASTE,  HIDE,                  _____, _____, _____, _____, _____, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  BTN2,  BTN1,  LGUI,      LGUI, CTL1,  ALT1 \
                              //`--------------------'  `--------------------'
  ),

  [MISC2] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       RST,  XXXXX,XXXXX, XXXXX, XXXXX,  UWRK,                   UWRK,  PGDN,   KUP,   PGUP, XXXXX,   RST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     XXXXX,  XXXXX,  DG1,   DG2,   DG3,  DWRK,                   DWRK, KLEFT, KDOWN, KRIGHT, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     XXXXX,  XXXXX, RTOG,  RMOD,  RHUI,  RHUD,                   RSAI,  RSAD, RRMOD,  XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  ALT1,  CTL1, _____,     _____, CTL1,  ALT1 \
                              //`--------------------'  `--------------------'
  ),

  [GAME1] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        F1,     F2,   F3,    F4,    F5,    F6,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
         1,      2,    3,     4,     5,     6,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       ESC,      C,    I,     B,     F, XXXXX,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   ESC,   TAB,   LCTL,       DQ,    DQ,    DQ \
                              //`--------------------'  `--------------------'
  ),

  [GAME2] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ESC,    TAB,    G,     W,     E,     R,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,  LSFT,    A,     S,     D,     F,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,     C,    Q,     M, XXXXX, XXXXX,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   ESC,     V,   SPC,        DQ,    DQ,    DQ \
                              //`--------------------'  `--------------------'
  ),

  [GAME3] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ESC,    TAB,    Q,     W,     E,     R,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX,    A,     S,     D, XXXXX,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX,XXXXX,     M, XXXXX, XXXXX,                   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   ESC,     F,   SPC,        DQ,    DQ,    DQ \
                              //`--------------------'  `--------------------'
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  return true;
}

#endif

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
    case GAME2:
      rgblight_mode(9);
      break;
    case GAME3:
      rgblight_mode(9);
      break;
    default:
      break;
  }

  return state;
}
#endif
