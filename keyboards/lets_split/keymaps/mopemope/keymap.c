#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define QWERTY 0
#define LOWER  1
#define RAISE  2
#define MOVE   3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define WRKSP1 LALT(LCTL(KC_UP))
#define WRKSP2 LALT(LCTL(KC_DOWN))

enum {
    QM = 0,
    LR,
    HE,
};

void qm_each(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    default:
        break;
    }
}

void qm_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    case 2:
        layer_on(MOVE);
        break;
    default:
        break;
    }
}

void qm_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    case 1:
        layer_off(MOVE);
        layer_off(LOWER);
        layer_off(RAISE);
        break;
    default:
        break;
    }

}

void lr_each(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    default:
        break;
    }
}

void lr_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    case 2:
        layer_on(LOWER);
        break;
    case 3:
        layer_on(RAISE);
        break;
    default:
        break;
    }
}

void lr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
    case 1:
        layer_off(MOVE);
        layer_off(LOWER);
        layer_off(RAISE);
        break;
    default:
        break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [QM] = ACTION_TAP_DANCE_FN_ADVANCED (qm_each, qm_finished, qm_reset),
    [LR] = ACTION_TAP_DANCE_FN_ADVANCED (lr_each, lr_finished, lr_reset),
    [HE] = ACTION_TAP_DANCE_DOUBLE (JP_MHEN, JP_HENK),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------, ,-----------------------------------------,
   * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |   O  |  P   |  BS  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  "   | A/Mo |  S   |  D   |F/Ctl |G/Alt | |H/Alt |J/Ctl |  K   |   L  | @/Mo |  :   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  -=  |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,<  |  .>  |  /?  |  \_  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |TD/QM |F12/Ct| GUI  | Alt  |Low/Ra|Sp/Sft| |En/Sft|TD/HE | Left | Down |  Up  |Right |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [QWERTY] = KEYMAP( \
    KC_TAB,  KC_Q,          KC_W,    KC_E,    KC_R,        KC_T,          KC_Y,          KC_U,        KC_I,    KC_O,    KC_P,           KC_BSPC, \
    JP_DQT,  LT(MOVE,KC_A), KC_S,    KC_D,    CTL_T(KC_F), ALT_T(KC_G),   ALT_T(KC_H),   CTL_T(KC_J), KC_K,    KC_L,    LT(MOVE,JP_AT), JP_COLN, \
    JP_MINS, KC_Z,          KC_X,    KC_C,    KC_V,        KC_B,          KC_N,          KC_M,        KC_COMM, KC_DOT,  JP_SLSH,        JP_BSLS, \
    TD(QM),  CTL_T(KC_F12), KC_LGUI, KC_LALT, TD(LR),      SFT_T(KC_SPC), SFT_T(KC_ENT), TD(HE),      KC_LEFT, KC_DOWN, KC_UP,          KC_RIGHT \
  ),

  /* Lower
   * ,-----------------------------------------, ,-----------------------------------------,
   * |      |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |  BS  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * | ESC  |   !  |   "  |   #  |   $  |   %  | |   &  |   '  |   (  |   )  |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |   ~  |   `  |   |  |   \  |  Yen | |  ^   |   [  |   ]  |   {  |   }  |  ;   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [LOWER] = KEYMAP( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    KC_ESC,  JP_EXLM, JP_DQT,  JP_HASH, JP_DLR,   JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, _______, _______, \
    _______, JP_TILD, JP_GRV,  JP_PIPE, JP_BSLS,  JP_YEN,  JP_CIRC, JP_LBRC, JP_RBRC, JP_LCBR, JP_RCBR, JP_SCLN, \
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Raise
   * ,-----------------------------------------, ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Reset |      |      |      |      |      | |      |      |      |      |      |Reset |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = KEYMAP( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Mouse
   * ,-----------------------------------------, ,-----------------------------------------.
   * | Esc  | Mute |VolDn |VolUp |      |      | |  End | PgDn | PgUp | Home |PrtScr| Del  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Reset |      |      |      |      |      | |      |      |      |      |      |Reset |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |WRKSP2|WRKSP1| | Copy |Paste |      |WhUp  |WhDn  |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |      |      | MsLf | MsDn | MsUp | MsRg |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [MOVE] = KEYMAP( \
    KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_END,     KC_PGDN,    KC_PGUP, KC_HOME,  KC_PSCR,  KC_DEL,  \
    RESET,   _______, _______, _______, _______, _______, _______,    _______,    _______, _______,  _______,  RESET, \
    _______, _______, _______, _______, WRKSP2,  WRKSP1,  LCTL(KC_C), LCTL(KC_V), _______, KC_WH_U,  KC_WH_D,  _______, \
    _______, _______, _______, _______, KC_BTN2, KC_BTN1, _______,    _______,    KC_MS_L, KC_MS_D,  KC_MS_U,  KC_MS_R  \
  )
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
