#pragma once

#ifndef USERSPACE
#define USERSPACE
#endif

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_HANDS_DOWN = SAFE_RANGE,
    KC_QWERTY_GAME,
    VIMWRITE,
    VIMWRITEQUIT,
    VIMQUIT,
    VIMQUITALL,
    VIPASTE,
    LNX_LAST,
    KU_QU,
    DLSIM,
    SLACK_CODE,
    SLACK_CODE_PASTE,
    COPY_PASTE,
    IMPORT_PDB,
};

enum layer {
    _HANDS_DOWN,
    _NAV_NUM_SYM,
    _BYO_ONOTE_VSC,
    _QWERTY_GAME,
};


#define  SFTBSP         SFT_T(KC_BSPC)
#define  SPCNAV         LT(_NAV_NUM_SYM, KC_SPC)

#define  CTLTAB         CTL_T(KC_TAB)
#define  ALTENT         ALT_T(KC_ENT)

#define  GUIDEL         GUI_T(KC_DEL)
#define  ALTESC         ALT_T(KC_ESC)

#define  ALT_UP         ALT_T(KC_UP)

#define  PC_UNDO        C(KC_Z)
#define  PC_SALL        C(KC_A)
#define  PC_CUT         C(KC_X)
#define  PC_COPY        C(KC_C)
#define  PC_PASTE       C(KC_V)
#define  PC_FIND        C(KC_F)
#define  PC_LOCK        G(KC_L)
#define  PC_BSWD        C(KC_BSPC)
#define  PC_SLACK       A(KC_Q)
#define  PC_SCSH        G(S(KC_S))
#define  PC_LWRD        C(KC_LEFT)
#define  PC_RWRD        C(KC_RIGHT)
#define  WINRUN         C(A(KC_K))

#define  LNX_PASTE      S(C(KC_V))
#define  LNX_LWD        A(KC_B)
#define  LNX_RWD        A(KC_F)
// reverse search
#define  LNX_RSR        C(KC_R)
// vertical split
#define  BY_VSPL        C(KC_F2)
// horizontal split
#define  BY_HSPL        S(KC_F2)
// change layout
#define  BY_CLYT        S(KC_F8)
// fullscreen pane
#define  BY_FPNE        S(KC_F11)
// kill pane
#define  BY_KPNE        C(KC_F6)
// disable function keys
#define  BY_DISF        S(KC_F12)
// move window left
#define  BY_MVWL        S(C(KC_F3))
// move window right
#define  BY_MVWR        S(C(KC_F4))
// shift pane focus left
#define  BY_FSPL        S(KC_F3)
// shift pane focus right
#define  BY_FSPR        S(KC_F4)
// new pane
#define  BY_NWIN        KC_F2
// focus on left window
#define  BY_FSWL        KC_F3
// focus on right window
#define  BY_FSWR        KC_F4
// refresh settings
#define  BY_RFSH        KC_F5
// exit server
#define  BY_KSRV        KC_F6
// rename window
#define  BY_RNWN        KC_F8
#define  VS_CTLP        C(KC_P)
#define  VS_SCTP        S(C(KC_P))
#define  VS_COMT        C(KC_SLSH)
// focus on terminal
#define  VS_TERM        C(KC_GRV)
// focus on code area
#define  VS_EDIT        C(KC_1)
// go to next editor
#define  VS_NEDT        C(KC_PGDN)
// go to prev editor
#define  VS_PEDT        C(KC_PGUP)

// to-do
#define ON_TODO         C(KC_1)
// important
#define ON_IMPT         C(KC_2)
// question
#define ON_QUES         C(KC_3)

#define PY_IPDB         IMPORT_PDB


#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define SEND_CAP_STRING(str, capitalized) if (MODS_SHIFT) { \
                                            clear_mods(); \
                                            SEND_STRING(capitalized); \
                                          } else { \
                                            SEND_STRING(str); \
                                          }

// #define _________________HANDSDOWNNEU_R1___________        KC_X , KC_F , KC_M,  KC_P,  KC_B,
// #define _________________HANDSDOWNNEU_R2___________        KC_R , KC_S , KC_N,  KC_T,  KC_G,
// #define _________________HANDSDOWNNEU_R3___________        KC_W , KC_C , KC_L,  KC_D,  KC_V,

// #define _________________NAVNUMSYM_LEFT_R1___________      _______,    KC_AMPR,    KC_PERC,    KC_BSLS,    KC_LBRC,    KC_RBRC
// #define _________________NAVNUMSYM_LEFT_R2___________      KC_SLSH,    KC_COLN,    KC_GRV,     KC_PAST,    KC_LPRN,    KC_RPRN
// #define _________________NAVNUMSYM_LEFT_R3___________      _______,    KC_7,       KC_3,       KC_1,       KC_5,       KC_9

// KC_F11,     KC_F12,     KC_8,       KC_2,       KC_0,       KC_4,       KC_6,       _______,
//     _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_EQL,     _______,    _______,
//                             _______,    _______,    KC_UP,      _______,    _______,    _______,

void my_custom_function(void);
