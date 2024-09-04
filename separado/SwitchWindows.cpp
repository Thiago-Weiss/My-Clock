#include "SwitchWindows.h"

void switchWindows(byte *val, byte maxVal) {
  nextVal(val, maxVal); // Certifique-se de que nextVal está acessível
  lcd.clear(); // Certifique-se de que lcd está acessível

  switch (telaAtual) {
    case MENU:
      {
        clearBnt(&bnt2);
        clearBnt(&bnt3);
        break;
      }
    case ALARME_1:
    case ALARME_2:
      {
        posAlarme = 0;
        bnt2.setPresed(nextValAlarm);
        bnt2.setPress(nextValAlarm);
        bnt2.setValue(&posAlarme);
        bnt2.setMaxValue(posAlarmeLimite);

        bnt3.setPresed(nextVal);
        bnt3.setPress(nextVal);
        bnt3.setValue(&alarmes[telaAtual - 1][posAlarme]);
        bnt3.setMaxValue(maxAlarme[posAlarme]);
        break;
      }
    case CONFIG_ALARME:
      posData = 0;
      bnt2.setPresed(nextValData);
      bnt2.setPress(nextValData);
      bnt2.setValue(&posData);
      bnt2.setMaxValue(posDataLimite);

      bnt3.setPresed(nextVal);
      bnt3.setPress(nextVal);
      bnt3.setValue(&data[posData]);
      bnt3.setMaxValue(maxData[posData]);
  }
}

void clearBnt(Button *bnt) {
  Serial.println("aqui");
  bnt->setPresed(nullptr);
  bnt->setPress(nullptr);
  bnt->setRelease(nullptr);
  bnt->setValue(&asd);
  bnt->setMaxValue(10);
}
