#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

//Multiple layouts, Programmers Dvorak as main.

#define _DVORAK 0
#define _QWERTY 1
#define _COLEMAK 2
#define _NAVIGATION 6
#define _NUMBERS 7
#define _ADJUST 16

#define TAPPING_TOGGLE 2

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  NAVIGATION,
  NUMBERS,
  ADJUST,
};

#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_DVK DVORAK
#define KC_NAV NAVIGATION
#define KC_SHENT MT(MOD_RSFT,KC_ENT)
#define KC_LBRALT MT(MOD_LALT, KC_LBRC)
#define KC_RBRALT MT(MOD_RALT, KC_RBRC)
#define KC_LGENT MT(MOD_LGUI, KC_ENT)
#define KC_NSPC LT(_NAVIGATION, KC_SPC)

/*
#define KC_SELA LCTL(KC_A)
#define KC_UDO LCTL(KC_Z)
#define KC_SAV LCTL(KC_S)
#define KC_PRT LCTL(KC_P)
#define KC_SETT LCTL(KC_I)
#define KC_EXP LCTL(KC_E)
#define KC_DESK LCTL(KC_D)
#define KC_LCK LCTL(KC_L)
#define KC_CTLM LCTL(KC_M)
#define KC_CTLR LCTL(KC_R) */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,  1 ,  2,   3,   4,  5,                   6,   7,   8,   9,   0, BSPC,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LCTL, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //,----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----.
     LSFT,SCLN, Q  , J  , K  , X  ,EQL,     GRAVE , B  , M  , W  , V  , Z  ,SHENT,
  //,----+----+----+----+----+----+----/    \----+----+----+----+----+----+----.
                      LBRC,LBRALT,LGENT,     NSPC,RBRALT,RBRC
  //                  `----+----+----'       `----+----+----'
  ),

  [_NAVIGATION] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       ,     ,      ,VOLU,MPLY,    ,                AT ,PGUP, UP ,PGDN,HOME,END ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,   , MRWD,VOLD,MFFD,    ,               BSLS,LEFT,DOWN,RGHT,INS ,DEL ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,     ,    ,   ,         ,CIRC,PSCR,SLCK,PAUS,APP ,PIPE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,       NSPC,    ,RGUI
  //                  `----+----+----'        `----+----+----'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        //persistent_default_layer_set(1UL<<_DVORAK);
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case NAVIGATION:
      if (record->event.pressed) {
        layer_on(_NAVIGATION);
        update_tri_layer(_NAVIGATION, _NUMBERS, _ADJUST);
      } else {
        layer_off(_NAVIGATION);
        update_tri_layer(_NAVIGATION, _NUMBERS, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
