#include "Gvars.h"

// bg lcd light
bool displayOn = true;
byte displayLight = 255;

// cursor
byte cursor = 0;


// controle
byte asd = 10;

//   alarme        hh mm d  s  t  q  q  s  s
byte alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte maxAlarme[] = { 24, 60, 2, 2, 2, 2, 2, 2, 2 };

// data         hh:dd - DD/MM/AA - d
byte data[] = { 0, 0, 0, 0, 0, 0 };
byte maxData[] = { 24, 60, 32, 13, 100, 7 };

// telas
byte currentWindows = MENU;

// text
char linha1[50] = {""};
char linha2[50] = {""};
