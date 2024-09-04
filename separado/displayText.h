#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include "Gvars.h"

void displayText();
void showMenu();
void showAlarm();
void showConfigData();

String dayOfWeek(int dayW);
String formatText(byte val, bool sinal);
String numToText(byte val);

#endif // DISPLAYTEXT_H