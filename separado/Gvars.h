#ifndef GVARS_H
#define GVARS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_AHTX0.h>
#include "virtuabotixRTC.h"
#include "Timer.h"
#include "Button.h"


// LCD
extern LiquidCrystal_I2C lcd;

// sensor de temperatura e humidade
extern Adafruit_AHTX0 sensorTemp;

// RTC
extern virtuabotixRTC myRTC;

// Timer
extern Timer backMenuTimer;
extern Timer displayOffTimer;
extern Timer alarmTimer;

// Bnt
extern Button bnt1;
extern Button bnt2;
extern Button bnt3;



// Enum para as telas
enum WINDOWS {
  MENU,
  ALARME_1,
  ALARME_2,
  SOUND,
  DATA,
  ALARME_PLAYING
};


#define WINDOWS_LIMITE 5
// Dados da tela
extern uint8_t currentWindows;

// cursor
extern uint8_t cursor;
#define cursorAlarmLimite 9
#define cursorDataLimite 7


// Alarmes
extern uint8_t alarme1[];
extern uint8_t alarme2[];
extern const uint8_t maxAlarme[];
extern uint8_t alarmPlaying;

// Dados
extern uint8_t data[];
extern const uint8_t maxData[];


#endif  // GVARS_H
