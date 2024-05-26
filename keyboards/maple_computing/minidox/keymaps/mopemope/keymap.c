#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#define QGMLWY  0
#define LOWER   1
#define RAISE   2
#define MISCL   3
#define MISCR   4
#define COMBA   5
#define COMBN   6
#define COMBE   7
#define COMBT   8
#define SF6     9

#define CYBER  22
#define BL3    10
#define R6S    11
#define B4B    12
#define LD     13
#define APEX   14
#define SN     15
#define EFT    16
#define DIV    17
#define VAL    18
#define COD    19
#define BF     20
#define KOC    21

#define _____ KC_TRNS
#define XXXXX KC_NO

// #define WRKSP1 LALT(LCTL(KC_UP))
// #define WRKSP2 LALT(LCTL(KC_DOWN))
#define WRKSP1 LGUI(KC_PGUP)
#define WRKSP2 LGUI(KC_PGDN)
// #define UWRKSP LSFT(LALT(LCTL(KC_UP)))
// #define DWRKSP LSFT(LALT(LCTL(KC_DOWN)))
#define UWRKSP LSFT(LGUI(KC_PGUP))
#define DWRKSP LSFT(LGUI(KC_PGDN))
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
#define DFG    TD(D_FG)
#define DVB    TD(D_VB)
#define DSV    TD(D_SV)
#define EXLM   JP_EXLM
#define DQT    JP_DQUO
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
#define ZHTG   JP_ZKHK
#define C_S    SFT_T(KC_C)
#define ESC    KC_ESC

#define DQG    DF(QGMLWY)
#define GBL3   DF(BL3)
#define GCYB   DF(CYBER)
#define GVAL   DF(VAL)
#define GEFT   DF(EFT)
#define GR6S   DF(R6S)
#define GB4B   DF(B4B)
#define GBF    DF(BF)
#define GCOD   DF(COD)
#define GDV2   DF(DIV)
#define GAPEX  DF(APEX)
#define GKOC   DF(KOC)
#define GLD    DF(LD)
#define GSN    DF(SN)
#define GSF6   DF(SF6)

#define SELA   LCTL(KC_A)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define CZ     LCTL(KC_Z)
#define CSL    LCTL(JP_SLSH)
#define CMN    LALT(LCTL(KC_N))
#define CMM    LALT(LCTL(KC_M))
#define CMD    LALT(LCTL(JP_DOT))
#define CMY    LALT(LCTL(JP_YEN))
#define CU     LCTL(UNDS)
#define AU     LALT(UNDS)
#define CG     LCTL(KC_G)
#define CQ     LCTL(KC_Q)
#define CT     LCTL(KC_T)
#define CJ     LCTL(KC_J)
#define CC     LCTL(KC_C)
#define CS     LCTL(KC_S)
#define CX     LCTL(KC_X)
#define CL     LCTL(KC_L)
#define CK     LCTL(KC_K)
#define CE     LCTL(KC_E)
#define CP     LCTL(KC_P)
#define CN     LCTL(KC_N)
#define CF     LCTL(KC_F)
#define CB     LCTL(KC_B)
#define CAT    LCTL(JP_AT)
#define MX     LALT(KC_X)
#undef  MD
#define MD     LALT(KC_D)
#define MSCLN  LALT(JP_SCLN)
#define APERC  LALT(JP_PERC)
#define CPIPE  LCTL(JP_PIPE)
#define CEXLM  LCTL(JP_EXLM)

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
#define ALTZ   LALT(KC_Z)
#define REC    LALT(KC_F9)
#define C_LT   LCTL(JP_LT)
#define C_GT   LCTL(JP_GT)
#define EFTS   LT(EFT2,KC_SPC)
#define CP_C   LT(CP2,KC_C)
#define R6_C   LT(R6S2,KC_C)
#define DI_C   LT(DIV2,KC_LCTL)
#define AP_I   LT(APEX2,KC_I)
#define GCTL   KC_LCTL
#define GALT   KC_LALT
#define AQ     LALT(KC_Q)
#define AE     LALT(KC_E)

enum custom_keycodes {
  CXCF = SAFE_RANGE,
  CXCB,
  CXCS,
  CXCC,
  CXCG,
  CXO,
  CXU,
  CCN,
  CCP,
  CCZ,
  CCX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[SF6] = LAYOUT( \
  TAB,    KC_Q,   XXXXX,  KC_E,   KC_R,        KC_Y,   KC_U,   KC_I,   KC_O,  XXXXX,      \
  KC_B,   KC_A,   KC_S,   KC_D,   KC_F,        KC_G,   KC_J,   KC_K,   KC_L,  KC_U,       \
  KC_Z,   KC_X,   KC_C,   KC_V,   QK_RBT,      DQG,    KC_B,   KC_N,   KC_M,  DQG,        \
                  ESC,    KC_B,   KC_W,        KC_P,   KC_H,   KC_T                       \
),
/* [SF6] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        KC_Y,   KC_U,   KC_I,   KC_O,   XXXXX,     \ */
/*   KC_B,   KC_A,   KC_S,   KC_D,   KC_F,        KC_G,   KC_J,   KC_K,   KC_L,   KC_U,     \ */
/*   KC_Z,   KC_X,   KC_C,   KC_V,   QK_RBT,      XXXXX,  KC_B,   KC_N,   KC_M,   KC_T,     \ */
/*                   ESC,    KC_B,   KC_W,        KC_P,   KC_H,   DQG                       \ */
/* ), */
/* [SF62] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        KC_Y,   KC_U,   KC_I,   KC_O,   XXXXX,     \ */
/*   KC_B,   KC_A,   KC_S,   KC_D,   KC_F,        KC_G,   KC_J,   KC_K,   KC_L,   KC_U,     \ */
/*   KC_Z,   KC_X,   KC_C,   KC_V,   QK_RBT,      XXXXX,  KC_B,   KC_N,   KC_M,   KC_T,     \ */
/*                   ESC,    KC_B,   KC_W,        KC_P,   KC_H,   DQG                       \ */
/* ), */

[QGMLWY] = LAYOUT( \
  KC_Q,   KC_G,    KC_M,   KC_L,    KC_W,        KC_Y,    KC_F,    KC_U,   KC_B,   BSP, \
  D_M,    KC_S,    TC,     NC,      KC_R,        KC_I,    AC,      EC,     KC_O,   H_M, \
  Z_S,    X_CT,    KC_C,   V_A,     GUI,         DOT,     J_C,     KC_K,   P_AL,   S_S, \
                   GCTL,   GALT,    SPC,         ENT,     BSPC,    QK_RBT               \
),

[LOWER] = LAYOUT( \
  EXLM,    DQT,    HASH,  DLR,    PERC,         AMPR,    QUOT,  GRV,    PIPE,  YEN,    \
  ESC,     LPRN,   RPRN,  LCBR,   RCBR,         TILD,    DOT,   SLSH,   EQL,   AT,     \
  CIRC,    LBRC,   RBRC,  KC_LT,  KC_GT,        CIRC,    COMM,  _____,  _____, _____,  \
                   ESC,   TAB,    KC_SPC,       _____,   _____, _____                  \
),

[RAISE] = LAYOUT( \
  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,        KC_6,     KC_7,    KC_8,   KC_9,   KC_0, \
  TAB,     KC_F1,  KC_F2,  KC_F3,  KC_F4,       KC_F5,    KC_F12,  KC_F7,  KC_F8,  AT,   \
  UNDS,    KC_F9,  KC_F10, KC_F11, _____,       EXLM,     KC_F6,   KC_LT,  KC_GT,  MINS, \
                   _____,  _____,  _____,       DOT,      COMM,    ASTR                 \
),

[MISCL] = LAYOUT( \
  QK_RBT,  _____,  GU,     _____,  WRKSP1,      UWRKSP,   PGDN,   KUP,     PGUP,   DEL,    \
  _____,   GL,     GD,     GR,     WRKSP2,      DWRKSP,   CLEFT,  KDOWN,   CRIGHT, GH,     \
  _____,   _____,  _____,  _____,  ENT,         MLT,      MGT,    SPSCR,   _____,  _____,  \
                   COPY,   PASTE,  GUI,         TAB,      M_V,    C_V                     \
),

[MISCR] =  LAYOUT( \
  QK_RBT,   _____,  GU,    _____,  PREVW,         PREVTB,  MLT,     KUP,    MGT,    DEL,    \
  TAB,     GL,     GD,    GR,     NEXTW,         NEXTTB,  KLEFT,   KDOWN,  KRIGHT, _____,  \
  _____,   _____,  _____, _____,  _____,         _____,   _____,   _____,  _____,  _____,  \
                   _____, CXU,    KC_SPC,        TAB,     BSP,      AU                   \
),

[COMBA] =  LAYOUT( \
   CQ,     CG,    CMM,    CL,      APERC,         _____,  CXCF,   CXU,   CXCB,   _____,  \
   MD,     CXCS,  CT,     CMN,     MX,            _____,  _____,  CXCC,  CXO,    CAT,    \
   CZ,     CX,    _____,  _____,   _____,         _____,  _____,  CK,    _____,  _____,  \
                  ESC,    TAB,     ZHTG,          CCX,    _____,  _____                  \
),

[COMBN] =  LAYOUT( \
  _____,   CG,   _____,  CL,     _____,          AMPR,   MCOM,    CXU,     MDOT,   MD,    \
  TAB,     CS,   CT,     _____,  _____,          MSCLN,  CLEFT,   CCZ,     CRIGHT, CAT,   \
  _____,   CX,   CRET,   CSPC,   _____,          MCOM,   MDOT,    _____,  _____,   CXU,   \
                 _____,  _____,  _____,          CJ,     _____,   _____                  \
),

[COMBE] =  LAYOUT(                                                                       \
   CAF7,  _____,  CUP,    _____,  _____,         DQG,    _____,  _____, _____,  _____,  \
   CAF2,  CLEFT,  CDOWN,  CRIGHT, _____,         AU,     CU,     _____, _____,  _____,  \
   PSCR,  _____,  _____,  _____,  _____,         _____,  _____,  _____, _____,  _____,  \
                  _____,  _____,  KC_SPC,        DOT,    _____,  _____                  \
),

[COMBT] =  LAYOUT( \
  _____,  _____,  GSF6,   _____,  _____,        DQT,    EXLM,   PLUS,   ASTR,   PIPE,   \
  _____,  _____,  _____,  _____,  _____,        TILD,   EQL,    COLN,   SCLN,   AT,     \
  _____,  _____,  _____,  _____,  _____,        CIRC,   MINS,   COMM,   DOT,    SLSH,   \
                  _____,  _____,  _____,        DOT,    QUOT,   _____                   \
),

/* [BL3] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        _____,  KC_F5,  KC_F6,  KC_F7,  ESC,     \ */
/*   KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,        _____,  KC_5,   KC_6,   KC_7,   _____,   \ */
/*   GCTL,   KC_L,   KC_M,   KC_I,   KC_G,        KC_Y,   KC_T,   KC_B,   KC_U,   _____,   \ */
/*                   KC_V,   KC_C,   KC_SPC,      DQG,    ALTZ,   REC                      \ */
/* ), */

/* [R6S] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        _____,  KC_F5,  KC_F6,  KC_F7,  ESC,     \ */
/*   KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,        KC_U,   KC_5,   KC_6,   KC_7,   GUI,     \ */
/*   GALT,   KC_Z,   GCTL,   KC_X,   KC_G,        KC_Y,   KC_B,   _____,  _____,  _____,   \ */
/*                   KC_C,   KC_V,   KC_SPC,      DQG,    ALTZ,   REC                      \ */
/* ), */

/* [B4B] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        KC_T,   KC_U,   KC_N,   KC_Y,   ESC,     \ */
/*   KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,    \ */
/*   GCTL,   KC_I,   KC_3,   KC_4,   KC_5,        _____,  _____,  _____,  _____,  _____,   \ */
/*                   KC_C,   KC_V,   KC_SPC,      DQG,    ALTZ,   REC                      \ */
/* ), */

/* [COD] = LAYOUT( \ */
/*   TAB,    KC_Q,   KC_W,   KC_E,   KC_R,        KC_1,   KC_2,   KC_3,   KC_4,   ESC,     \ */
/*   KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,        KC_B,   KC_M,   KC_7,   KC_8,   GUI,     \ */
/*   GCTL,   GALT,   KC_Z,   KC_X,   KC_G,        KLEFT,  KUP,    KDOWN,  KRIGHT, _____,   \ */
/*                   KC_V,   KC_C,   KC_SPC,      DQG,    ALTZ,   REC                      \ */
/* ), */

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CXCF:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xf"));
    }
    break;
  case CXCB:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xb"));
    }
    break;
  case CXCS:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xs"));
    }
    break;
  case CXCC:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xc"));
    }
    break;
  case CXCG:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xg"));
    }
    break;
  case CXO:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") "o");
    }
    break;
  case CXU:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") "u");
    }
    break;
  case CCN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "n");
    }
    break;
  case CCP:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "p");
    }
    break;
  case CCZ:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "z");
    }
    break;
  case CCX:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "x");
    }
    break;
  }
  return true;
}

/*
bool change;
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GVAL:
      rgblight_mode(RGBLIGHT_MODE_BREATHING+1);
      rgblight_sethsv(HSV_PURPLE);
      change = true;
      break;
    case GEFT:
      rgblight_mode(RGBLIGHT_MODE_BREATHING);
      rgblight_sethsv(HSV_WHITE);
      change = true;
      break;
    case GR6S:
      rgblight_mode(RGBLIGHT_MODE_BREATHING);
      rgblight_sethsv(HSV_GREEN);
      change = true;
      break;
    case GDV2:
      rgblight_mode(RGBLIGHT_MODE_BREATHING);
      rgblight_sethsv(HSV_CYAN);
      change = true;
      break;
    case DQG:
      rgblight_sethsv(0xFF, 0xFF, 0xFF);
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
      change = true;
      break;
    default:
      change = false;
    }
}

bool main_mode = true;
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
  case QGMLWY:
    if (!change) {
      rgblight_sethsv(0xFF, 0xFF, 0xFF);
      if (main_mode) {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
      } else {
        rgblight_mode(RGBLIGHT_MODE_TWINKLE+3);
      }
      main_mode = !main_mode;
    }
    break;
  case LOWER:
    rgblight_mode(RGBLIGHT_MODE_KNIGHT+1);
    rgblight_sethsv(HSV_BLUE);
    break;
  case RAISE:
    rgblight_mode(RGBLIGHT_MODE_KNIGHT+1);
    rgblight_sethsv(HSV_BLUE);
    break;
  case MISCL:
    rgblight_mode(RGBLIGHT_MODE_SNAKE+2);
    rgblight_sethsv(HSV_YELLOW);
    break;
  case MISCR:
    rgblight_mode(RGBLIGHT_MODE_SNAKE+2);
    rgblight_sethsv(HSV_YELLOW);
    break;
  case COMBA:
    rgblight_mode(RGBLIGHT_MODE_TWINKLE+5);
    rgblight_sethsv(HSV_GOLD);
    break;
  case COMBN:
    rgblight_mode(RGBLIGHT_MODE_TWINKLE+5);
    rgblight_sethsv(HSV_GOLD);
    break;
  case COMBE:
    rgblight_mode(RGBLIGHT_MODE_BREATHING+2);
    rgblight_sethsv(HSV_AZURE);
    break;
  case COMBT:
    rgblight_mode(RGBLIGHT_MODE_BREATHING+2);
    rgblight_sethsv(HSV_AZURE);
    break;
  default:
    break;
  }

  return state;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
*/
