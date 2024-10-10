#include "save_load.h"
#include <EEPROM.h>
#include "Gvars.h"
#include "music.h"


static void saveAlarme1();
static void saveAlarme2();
static void saveMusic();



void load_all() {
  uint8_t result = 0;
  for (uint8_t i = 0; i < cursorAlarmLimite; i++) {
    result = (uint8_t)EEPROM.read(i);
    if (result < maxAlarme[i]) {
      alarme1[i] = result;
    }
  }

  for (uint8_t i = cursorAlarmLimite; i < cursorAlarmLimite * 2; i++) {
    result = (uint8_t)EEPROM.read(i);
    if (result < maxAlarme[i - cursorAlarmLimite]) {
      alarme2[i - cursorAlarmLimite] = result;
    }
  }
  
  result = EEPROM.read((cursorAlarmLimite * 2) + 1);
  if (result < songsNamesLimite) {
    currentMusic = result;
  }
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
  EEPROM.update((cursorAlarmLimite * 2) + 1, currentMusic);
}
