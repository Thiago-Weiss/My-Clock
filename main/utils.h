#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

#define LCD_LIGHT 9

void previousVal(uint8_t *val, uint8_t maxVal);
void nextVal(uint8_t *val, uint8_t maxVal);
void nextValData(uint8_t *val, uint8_t maxVal);
void backMenu();

bool displayTurnOn();
void displayTurnOff();

void attAlarmePlay();
bool alarmOff();

#endif // UTILS_H
