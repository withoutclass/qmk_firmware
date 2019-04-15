#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _NAVIGATION 1

#define TAPPING_TOGGLE 2

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  NAVIGATION
};

#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_DVK DVORAK
#define KC_NAV NAVIGATION
#define KC_SHBSLS MT(MOD_RSFT,KC_BSLS)
#define KC_LBRALT MT(MOD_LALT, KC_LBRC)
#define KC_RBRALT MT(MOD_RALT, KC_RBRC)
#define KC_LGENT MT(MOD_LGUI, KC_ENT)
#define KC_NSPC LT(_NAVIGATION, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,  1 ,  2,   3,   4,  5,                   6,   7,   8,   9,   0, BSPC,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LCTL,  A ,  O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //,----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----.
     LSFT,SCLN, Q  , J  , K  , X  ,EQL,     GRAVE , B  , M  , W  , V  , Z  ,SHBSLS,
  //,----+----+----+----+----+----+----/    \----+----+----+----+----+----+----.
                      LCTL,LBRALT,LGENT,     NSPC,RBRALT,CAPS
  //                  `----+----+----'       `----+----+----'
  ),

  [_NAVIGATION] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,VOLU,MPLY,    ,                AT ,PGUP, UP ,PGDN,HOME,END ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|œ
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

      } else {
        layer_off(_NAVIGATION);
      }
      return false;
      break;
  }
  return true;
}
