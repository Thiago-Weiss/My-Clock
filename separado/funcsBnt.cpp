#include "funcsBnt.h"

void bnt_1_Funcs() {
  if (!displayOn) {
    displayTurnOn();
    return;
  }
  backMenuTimer.reset();
  lcd.clear();
  cursor = 0;
  
  nextVal(&currentWindows, WINDOWS_LIMITE);
}

void bnt_2_Funcs() {
  if (!displayOn) {
    displayTurnOn();
    return;
  }

  switch (currentWindows) {
    case MENU:
      {
        // faz nada
        break;
      }
    case ALARME_1:
      {
        nextVal(&cursor, cursorAlarmLimite);
        break;
      }
    case ALARME_2:
      {
        nextVal(&cursor, cursorAlarmLimite);
        break;
      }
    case DATA:
      {
        nextVal(&cursor, cursorDataLimite);
        break;
      }
    case SOUND:
      {
        // tem que implementar
        break;
      }
  }
}
void bnt_3_Funcs() {
  if (!displayOn) {
    displayTurnOn();
    return;
  }

  switch (currentWindows) {
    case MENU:
      {
        // faz nada
        break;
      }
    case ALARME_1:
      {
        nextVal(&alarme1[cursor], maxAlarme[cursor]);
        break;
      }
    case ALARME_2:
      {
        nextVal(&alarme2[cursor], maxAlarme[cursor]);
        break;
      }
    case DATA:
      {
        nextVal(&data[cursor], maxData[cursor]);
        break;
      }
    case SOUND:
      {
        // tem que implementar
        break;
      }
  }
}