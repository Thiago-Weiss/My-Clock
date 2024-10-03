#ifndef GVARS_H
#define GVARS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_AHTX0.h>
#include "virtuabotixRTC.h"

#include "Button.h"
#include "utils.h"
#include "Timer.h"

// sensor de temperatura e humidade
extern Adafruit_AHTX0 sensorTemp;

// LCD
extern LiquidCrystal_I2C lcd;

#define LCD_LIGHT 9
extern bool displayOn;
extern byte displayLight;

// Bnt
extern Button bnt1;
extern Button bnt2;
extern Button bnt3;

// RTC
extern virtuabotixRTC myRTC;

// Timer
extern Timer backMenuTimer;
extern Timer displayOffTimer;




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

// cursor
extern byte cursor;
#define cursorAlarmLimite 9
#define cursorDataLimite 7


// Alarmes
extern byte alarme1[];
extern byte alarme2[];
extern byte maxAlarme[];

// Dados
extern byte data[];
extern byte maxData[];

// Dados da tela
extern byte currentWindows;

// Textos
extern char linha1[];
extern char linha2[];

#endif  // GVARS_H
