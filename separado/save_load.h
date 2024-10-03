#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H
#include <EEPROM.h>

#include "Gvars.h"

void load_all();

void saveAll();
void saveAlarme1();
void saveAlarme2();
void saveMusic();


#endif  // SAVE_LOAD_H
