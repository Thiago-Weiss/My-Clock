#include "utils.h"
#include "music.h"


void nextVal(byte *val, byte maxVal) {
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
  byte displayLight = 255;
  analogWrite(LCD_LIGHT, displayLight);
  displayOn = true;
  displayOffTimer.reset();
  return true;
}

void displayTurnOff() {
  byte displayLight = 0;
  analogWrite(LCD_LIGHT, displayLight);
  displayOn = false;
}


void att_alarme() {
  //   alarme        hh mm d  s  t  q  q  s  s

  static bool alarme_1_ativado = false;
  if (alarme1[myRTC.dayofweek + 1]) {
    if (alarme1[0] == myRTC.hours) {
      if (alarme2[1] == myRTC.minutes) {
        if (!alarme_1_ativado) {
          alarme_1_ativado = false;
          startPlayMusic(songs[1], 3);

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
          startPlayMusic(songs[1], 3);
        }
      } else {
        alarme_2_ativado = false;
      }
    }
  }
}
