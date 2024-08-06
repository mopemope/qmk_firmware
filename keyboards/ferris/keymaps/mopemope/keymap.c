// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

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
#define SF6     9
#define VAL    10
#define EFT    11
#define DIV    12
#define CYBER  13
#define COD    14

/* #define CYBER  22 */
/* #define BL3    10 */
/* #define R6S    11 */
/* #define B4B    12 */
/* #define LD     13 */
/* #define APEX   14 */
/* #define SN     15 */
/* #define COD    19 */
/* #define BF     20 */
/* #define KOC    21 */

#define ____ KC_TRNS
#define XXXX KC_NO

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
// #define LK     LT(LOWER,KC_K)
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
#define Q_M    LT(MISCL,KC_Q)
#define D_C    CTL_T(KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define Z_S    LSFT_T(KC_Z)
#define D_S    LSFT_T(KC_D)
#define H_S    LSFT_T(KC_H)
#define I_S    LSFT_T(KC_I)
#define TABC   CTL_T(KC_TAB)
#define TABG   GUI_T(KC_TAB)
#define TABS   LSFT_T(KC_TAB)
#define ESCC   CTL_T(KC_ESC)
#define ESCS   LSFT_T(KC_ESC)
#define X_CT   LCTL_T(KC_X)
#define P_AL   LALT_T(KC_P)
#define J_C    RCTL_T(KC_J)
#define P_C    RCTL_T(KC_P)
#define A_C    RCTL_T(KC_A)
#define H_M    LT(MISCR,KC_H)
#define B_M    LT(MISCR,KC_BSPC)
#define DELM   LT(MISCR,KC_DEL)
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
#define COMS   LSFT_T(JP_COMM)
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
#define SFT    KC_LSFT
#define C_V    LCTL(KC_V)
#define M_V    LALT(KC_V)
#define ALTZ   LALT(KC_Z)
#define ALTX   LALT(KC_X)
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
  CCR,
  CCW,
  SOCD_W,
  SOCD_A,
  SOCD_S,
  SOCD_D,
  LP,
  LK,
  MP,
  MK,
  HP,
  HK
};

bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;

bool lp_down = false;
bool lk_down = false;
bool mp_down = false;
bool mk_down = false;
bool hp_down = false;
bool hk_down = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QGMLWY] = LAYOUT(
    Q_M, KC_G,    KC_M,    KC_L,    KC_W,            KC_Y,    KC_F,  KC_U,    KC_B,   DEL,
    D_M, KC_S,    TC,      NC,      KC_R,            KC_I,    AC,    EC,      KC_O,   H_M,
    Z_S, X_CT,    KC_C,    KC_V,    TABG,            DOT,     KC_J,  KC_K,    P_AL,   S_S,
                                    GALT, SPC,  ENT, BSPC
  ),
  [LOWER] = LAYOUT(
    EXLM, DQT,    HASH,    DLR,     PERC,            AMPR,    QUOT,  GRV,     PIPE,   YEN,
    ESC,  LPRN,   RPRN,    LCBR,    RCBR,            TILD,    DOT,   SLSH,    EQL,    AT,
    CIRC, LBRC,   RBRC,    KC_LT,   KC_GT,           CIRC,    COMM,  XXXX,    XXXX,   SLSH,
                                    TAB, KC_SPC,XXXX,XXXX
  ),
  [RAISE] = LAYOUT(
    KC_1, KC_2,   KC_3,    KC_4,    KC_5,            KC_6,    KC_7,  KC_8,    KC_9,   KC_0,
    TAB,  KC_F1,  KC_F2,   KC_F3,   KC_F4,           KC_F5,   KC_F12,KC_F7,   KC_F8,  AT,
    UNDS, KC_F9,  KC_F10,  KC_F11,  XXXX,            EXLM,    KC_F6, KC_LT,   KC_GT,  MINS,
                                    XXXX, XXXX, DOT, COMM
  ),
  [MISCL] = LAYOUT(
    QK_RBT,XXXX,  GU,    XXXX,     WRKSP1,           UWRKSP, PGDN,  KUP,    PGUP,   DEL,
    XXXX,  GL,    GD,    GR,       WRKSP2,           DWRKSP, CLEFT, KDOWN,  CRIGHT, XXXX,
    XXXX,  XXXX,  XXXX,  XXXX,     ENT,              MLT,    MGT,   SPSCR,  XXXX,   SLSH,
                                   COPY, PASTE,M_V, C_V
  ),
  [MISCR] = LAYOUT(
    QK_RBT,XXXX,  GU,    XXXX,     PREVW,            PREVTB, MLT,   KUP,   MGT,    DEL,
    TAB,   GL,    GD,    GR,       NEXTW,            NEXTTB, KLEFT, KDOWN, KRIGHT, XXXX,
    SFT,   XXXX,  XXXX,  XXXX,     XXXX,             XXXX,   XXXX,  XXXX,  XXXX,   SFT,
                                   CXU,KC_SPC, DOT, COMM
  ),
  [COMBA] = LAYOUT(
    CQ, CQ,     CMM,    CL,       APERC,             XXXX,  CXCF,  CXU,    CXCB,   XXXX,
    MD, CXCS,   CT,     CMN,      MX,                XXXX,  XXXX,  CXCC,   CXO,    XXXX,
    CZ, CX,     XXXX,   XXXX,     XXXX,              XXXX,  XXXX,  CK,     XXXX,   XXXX,
                                  TAB, ZHTG,  DOT, COMM
  ),
  [COMBN] = LAYOUT(
    XXXX, CG,   XXXX,   CL,       XXXX,              AMPR,  MCOM,  CXU,    MDOT,   MD,
    TAB,  CS,   CT,     XXXX,     XXXX,              MSCLN, CLEFT, CCZ,    CRIGHT, CAT,
    XXXX, CX,   CRET,   CSPC,     XXXX,              MCOM,  MDOT,  XXXX,   XXXX,   CXU,
                                  ____, ____,  CJ, ____
  ),
  [COMBE] = LAYOUT(
    CAF7, ____, CUP,    XXXX,     CCW,               DQG,  XXXX,  XXXX,   XXXX,  XXXX,
    CAF2, CLEFT,CDOWN,  CRIGHT,   CCR,               AU,   CU,    XXXX,   XXXX,  XXXX,
    PSCR, XXXX, XXXX,   XXXX,     XXXX,              XXXX, XXXX,  XXXX,   XXXX,  XXXX,
                                  ____, KC_SPC, DOT, ____
  ),
  [COMBT] = LAYOUT(
    GVAL, XXXX, GSF6,   XXXX,   GCYB,              DQT,  EXLM,  PLUS,   ASTR,  PIPE,
    XXXX, XXXX, XXXX,   XXXX,   XXXX,              TILD, EQL,   COLN,   SCLN,  AT,
    XXXX, XXXX, XXXX,   XXXX,   XXXX,              CIRC, DOT,   COMM,   XXXX,  XXXX,
                                ____, GUI, MINS, UNDS
  ),
  [SF6] = LAYOUT(
    XXXX, KC_Q,  XXXX,  XXXX,   KC_R,              KC_Y, LP,   MP,    HP,   XXXX,
    KC_B, SOCD_A,SOCD_S,SOCD_D, KC_F,              KC_G, LK,   MK,    HK,   KC_U,
    TAB,  KC_X,  KC_C,  XXXX,   XXXX,              KC_T, XXXX, KC_N,  KC_M, DQG,
                                KC_B,SOCD_W,KC_H, KC_P
  ),
  [VAL] = LAYOUT(
    TAB, KC_Q,  SOCD_W,KC_E,   KC_R,              KC_F1,KC_F2,KC_F3, KC_4,  ESC,
    KC_B,SOCD_A,SOCD_S,SOCD_D, KC_F,              KC_5, KC_6, KC_7,  KC_8,  XXXX,
    KC_Z,KC_X,  KC_B,  KC_G,   KC_C,              KC_T, KC_V, GCTL,  XXXX,  DQG,
                               KC_4,KC_SPC,KC_ENT,KC_H
  ),
  [CYBER] = LAYOUT(
    TAB, KC_Q,  SOCD_W,KC_E,   KC_R,              KC_1 ,KC_M, KC_J,  KC_K,  ESC,
    SFT, SOCD_A,SOCD_S,SOCD_D, KC_F,              KC_3, KC_I, KC_O,  KC_P,  XXXX,
    GCTL,KC_X,  GALT,  KC_V,   KC_T,              KC_N, KC_Z, GCTL,  XXXX,  DQG,
                               KC_C,KC_SPC,KC_ENT,KC_V
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SOCD_W:
    if (record->event.pressed) {
      if (s_down) {
        unregister_code(KC_S);
      } else {
        register_code(KC_W);
      }
      w_down = true;
    } else {
      unregister_code(KC_W);
      w_down = false;
      if (s_down) {
        register_code(KC_S);
      }
    }
    return false;
  case SOCD_A:
    if (record->event.pressed) {
      if (d_down) {
        unregister_code(KC_D);
      } else {
        register_code(KC_A);
      }
      a_down = true;
    } else {
      unregister_code(KC_A);
      a_down = false;
      if (d_down) {
        register_code(KC_D);
      }
    }
    return false;
  case SOCD_S:
    if (record->event.pressed) {
      if (w_down) {
        unregister_code(KC_W);
      } else {
        register_code(KC_S);
      }
      s_down = true;
    } else {
      unregister_code(KC_S);
      s_down = false;

      if (w_down) {
        register_code(KC_W);
      }
    }
    return false;
  case SOCD_D:
    if (record->event.pressed) {
      if (a_down) {
        unregister_code(KC_A);
      } else {
        register_code(KC_D);
      }
      d_down = true;
    } else {
      unregister_code(KC_D);
      d_down = false;
      if (a_down) {
        register_code(KC_A);
      }
    }
    return false;
  case LP:
    if (record->event.pressed) {
      if (lk_down) {
        unregister_code(KC_J);
      }
      register_code(KC_U);
      lp_down = true;
    } else {
      unregister_code(KC_U);
      lp_down = false;
    }
    return false;
  case LK:
    if (record->event.pressed) {
      if (lp_down) {
        unregister_code(KC_U);
      }
      register_code(KC_J);
      lk_down = true;
    } else {
      unregister_code(KC_J);
      lk_down = false;
    }
    return false;
  case MP:
    if (record->event.pressed) {
      if (mk_down) {
        unregister_code(KC_K);
      }
      register_code(KC_I);
      mp_down = true;
    } else {
      unregister_code(KC_I);
      mp_down = false;
    }
    return false;
  case MK:
    if (record->event.pressed) {
      if (mp_down) {
        unregister_code(KC_I);
      }
      register_code(KC_K);
      mk_down = true;
    } else {
      unregister_code(KC_K);
      mk_down = false;
    }
    return false;
  case HP:
    if (record->event.pressed) {
      if (hk_down) {
        unregister_code(KC_L);
      }
      register_code(KC_O);
      hp_down = true;
    } else {
      unregister_code(KC_O);
      hp_down = false;
    }
    return false;
  case HK:
    if (record->event.pressed) {
      if (hp_down) {
        unregister_code(KC_O);
      }
      register_code(KC_L);
      hk_down = true;
    } else {
      unregister_code(KC_L);
      hk_down = false;
    }
    return false;
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
  case CCR:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "r");
    }
    break;
  case CCW:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") "w");
    }
    break;
  }
  return true;
}
