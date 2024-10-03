#include "Gvars.h"

// bg lcd light
bool displayOn = true;
byte displayLight = 255;

// cursor
byte cursor = 0;


//   alarme        hh mm d  s  t  q  q  s  s
byte alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte maxAlarme[] = { 24, 60, 2, 2, 2, 2, 2, 2, 2 };

// data        DD/MM/AA d  hh:mm Button
byte data[] = { 0, 0, 0, 0, 0, 0, 0};
byte maxData[] = {32, 13, 100, 7, 24, 60, 1};

// telas
byte currentWindows = MENU;

// text
char linha1[18] = {'\0'};
char linha2[18] = {'\0'};
