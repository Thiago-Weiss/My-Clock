#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include "Gvars.h"

void displayText();
void showMenuLinha1();
void showMenuLinha2Data();
void showMenuLinha2Temp();
void showAlarm(byte alarme[]);
void showConfigData();

void dayOfWeek(uint8_t dayW, char* result);
void numToText(uint8_t val, char* result);
void formatNum(uint8_t val, char* result, uint8_t pos);
void formatDay(uint8_t val, char* result);


#endif  // DISPLAYTEXT_H