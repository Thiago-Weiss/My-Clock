#include "utils.h"


#include "music.h"
#include "Gvars.h"
#include "save_load.h"


// bg lcd light
static bool displayOn = true;
static uint8_t displayLight = 255;





void nextVal(uint8_t *val, uint8_t maxVal) {
  *val += 1;
  if (*val >= maxVal)
    *val = 0;
  backMenuTimer.reset();
  Serial.println(*val);
}

void backMenu() {
  currentWindows = MENU;
  lcd.clear();
  saveAll();
}



bool displayTurnOn() {
  if (displayOn) {
    displayOffTimer.reset();
    return false;
  }
  uint8_t displayLight = 255;
  analogWrite(LCD_LIGHT, displayLight);
  displayOn = true;
  displayOffTimer.reset();
  return true;
}

void displayTurnOff() {
  uint8_t displayLight = 0;
  analogWrite(LCD_LIGHT, displayLight);
  displayOn = false;
}


void attAlarmePlay() {
  //   alarme        hh mm d  s  t  q  q  s  s

  static bool alarme_1_ativado = false;
  if (alarme1[myRTC.dayofweek + 1]) {
    if (alarme1[0] == myRTC.hours) {
      if (alarme2[1] == myRTC.minutes) {
        if (!alarme_1_ativado) {
          alarme_1_ativado = false;
          startPlayMusic(songs[0], 0);

          currentWindows = ALARME_PLAYING;
        }
      } else {
        alarme_1_ativado = false;
      }
    }
  }

  static bool alarme_2_ativado = false;
  if (alarme2[myRTC.dayofweek + 1]) {
    if (alarme2[0] == myRTC.hours) {
      if (alarme2[1] == myRTC.minutes) {
        if (!alarme_1_ativado) {
          alarme_1_ativado = false;
          startPlayMusic(songs[0], 0);
        }
      } else {
        alarme_2_ativado = false;
      }
    }
  }
}
