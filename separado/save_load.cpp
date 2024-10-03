#include "save_load.h"



void load_all() {
  for (byte i = 0; i < cursorAlarmLimite; i++) {
    alarme1[i] = (byte)EEPROM.read(i);
  }
  for (byte i = cursorAlarmLimite; i < cursorAlarmLimite * 2; i++) {
    alarme2[i] = (byte)EEPROM.read(i);
  }
}


void saveAll() {
  saveAlarme1();
  saveAlarme2();
  saveMusic();
}

void saveAlarme1() {
  //   alarme        hh mm d  s  t  q  q  s  s
  for (byte i = 0; i < cursorAlarmLimite; i++) {
    EEPROM.update(i, alarme1[i]);
  }
}
void saveAlarme2() {
  for (byte i = cursorAlarmLimite; i < cursorAlarmLimite * 2; i++) {
    EEPROM.update(i, alarme2[i]);
  }
}
void saveMusic() {
}
