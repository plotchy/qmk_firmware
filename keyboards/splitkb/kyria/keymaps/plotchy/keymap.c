/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "plotchy.h"

#define M_LWR MO(_LOWER)
#define M_RSE MO(_RAISE)
#define L(kc) (LSFT(kc))
#define R(kc) (RALT(kc))

#define  ESCBYO         LT(_BYO_ONOTE_VSC, KC_ESC)
#define  NUMTOG         TG(_NAV_NUM_SYM)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: _HANDS_DOWN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_HANDS_DOWN] = LAYOUT(
     XXXXXXX, KC_X ,  KC_F   ,  KC_M  ,   KC_P ,   KC_B ,                                         KC_MINS,   KC_DOT ,  KC_SLSH , KC_COMM ,  KC_Q , XXXXXXX,
     KC_Z   , KC_R ,  KC_S   ,  KC_N  ,   KC_T ,   KC_G ,                                         KC_QUOT,   KC_A   ,   KC_E   ,   KC_I  ,  KC_H ,  KC_J  ,
     KC_HOME, KC_W ,  KC_C   ,  KC_L  ,   KC_D ,   KC_V , PC_BSWD, XXXXXXX,     XXXXXXX, XXXXXXX, KC_EQL ,   KC_U   ,   KC_O   ,   KC_Y  ,  KC_K , KC_END ,
                              VS_TERM , XXXXXXX, ESCBYO, SFTBSP , ALTENT,     CTLTAB, SPCNAV, GUIDEL, XXXXXXX, VS_COMT
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV_NUM_SYM] = LAYOUT(
    _______,    KC_AMPR,    KC_PERC,    KC_BSLS,    KC_LBRC,    KC_RBRC,                                    _______,    _______,    KC_UP,      _______,    _______,    _______,
    KC_SLSH,    KC_COLN,     KC_GRV,    KC_PAST,    KC_LPRN,    KC_RPRN,                                    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_EQL,     _______,
    _______,       KC_7,       KC_3,       KC_1,       KC_5,       KC_9,_______,_______,_______,_______,       KC_8,       KC_2,       KC_0,       KC_4,       KC_6,       _______,
                                        _______,    _______,    _______,_______,_______,_______,_______,    _______,    _______,    _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BYO_ONOTE_VSC] = LAYOUT(
    KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    _______,    ON_QUES,    ON_IMPT,    ON_TODO,    PY_IPDB,    _______,                                BY_FPNE,    BY_CLYT,    BY_HSPL,    BY_VSPL,    BY_DISF,    BY_KPNE,
    _______,    _______,    _______,    _______,    _______,    _______,_______,_______,_______,_______,BY_FSWL,    BY_FSWR,    BY_NWIN,    BY_MVWL,    BY_MVWR,    _______,
                                        _______,    _______,    _______,_______,_______,_______,_______,_______,    _______,    _______
    ),
};