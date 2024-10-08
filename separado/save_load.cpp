#include "save_load.h"
#include <EEPROM.h>
#include "Gvars.h"


static void saveAlarme1();
static void saveAlarme2();
static void saveMusic();



void load_all() {
  for (uint8_t i = 0; i < cursorAlarmLimite; i++) {
    alarme1[i] = (uint8_t)EEPROM.read(i);
  }
  for (uint8_t i = cursorAlarmLimite; i < cursorAlarmLimite * 2; i++) {
    alarme2[i] = (uint8_t)EEPROM.read(i);
  }
  // load music
}


void saveAll() {
  saveAlarme1();
  saveAlarme2();
  saveMusic();
}


static void saveAlarme1() {
  //   alarme        hh mm d  s  t  q  q  s  s
  for (uint8_t i = 0; i < cursorAlarmLimite; i++) {
    EEPROM.update(i, alarme1[i]);
  }
}

static void saveAlarme2() {
  for (uint8_t i = cursorAlarmLimite; i < cursorAlarmLimite * 2; i++) {
    EEPROM.update(i, alarme2[i]);
  }
}

static void saveMusic() {
}
