// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define MOVE 1 // Symbols layer
#define FUNC 2 // Motion layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │;: │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ ,<│.> │/? │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤SPC├───┐   ┌───┤SPC├───┘
      *               └───┤TAB│   │ENT├───┘
      *                   └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,          KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        LSFT_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                    LGUI_T(KC_TAB), LT(MOVE, KC_SPC), LCTL_T(KC_ESC),           KC_ENT,  LT(MOVE, KC_SPC),  LT(FUNC, KC_RALT)
    ),
    /* Layer 1: Symbols
    * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
    * | 1!  | 2@  | 3#  | 4$  | 5%  |                      | 6^  | 7&  | 8*  | 9(  | 0)  |
    * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
    * | `~  |HOME |PGUP |PGDN | END |                      |LEFT |DOWN | UP  |RGHT | ;:  |
    * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
    * |SHFT |     |     |     |     |                      | -_  | =+  | [{  | ]}  |SHF\||
    * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
    *               .-------.-------.-------.      .-------.-------.-------.   
    *               |       |       |       |      |       |(hold) |       |
    *               '-------'-------'-------'      '-------'-------'-------' 
    */
    [MOVE] = LAYOUT_split_3x5_3(
        KC_1,               KC_2,    KC_3,     KC_4,   KC_5,               KC_6,    KC_7,     KC_8,     KC_9,    KC_0,
        KC_GRAVE,         KC_HOME, KC_PGUP,  KC_PGDN, KC_END,             KC_LEFT, KC_DOWN,   KC_UP,  KC_RIGHT,  KC_TRNS,
        LSFT_T(KC_SLSH),  KC_TRNS,  KC_TRNS, KC_TRNS, KC_QUOT,            KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, RSFT_T(KC_BSLS),
                                KC_LGUI, KC_TRNS, KC_DEL,      KC_BSPC,  KC_TRNS,  KC_TRNS
    ),
    /* Layer 2: Function keys
    * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
    * | F1  | F2  | F3  | F4  | F5  |                      | F6  | F7  | F8  | F9  | F10 |
    * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
    * | F11 | F12 |PREV |PLAY |NEXT |                      |MUTE |Vol- |Vol+ | Br- | Br+ |  
    * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
    * |     |     |     |     |     |                      |     |     |     |     |     |
    * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
    *               .-------.-------.-------.      .-------.-------.-------.   
    *               |       |       |       |      |       |       |(hold) |
    *               '-----------------------'      '-------'-------'-------' 
    */
    [FUNC] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,                           KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,
        KC_F11,  KC_F12,  KC_MPRV,  KC_MPLY, KC_MNXT,                         KC_MUTE,  KC_VOLD, KC_VOLU, KC_LPRN, KC_RPRN,
        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_LGUI, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};
