#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

#define LCD_LIGHT 9


void nextVal(uint8_t *val, uint8_t maxVal);
void backMenu();

bool displayTurnOn();
void displayTurnOff();

void attAlarmePlay();


#endif // UTILS_H
