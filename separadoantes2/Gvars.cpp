#include "Gvars.h"

byte asd = 10;  //controle

//   alarme        hh mm d  s  t  q  q  s  s
byte alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

byte *alarmes[] = { alarme1, alarme2 };
byte maxAlarme[] = { 24, 60, 2, 2, 2, 2, 2, 2, 2 };

byte posAlarme = 0;
byte posAlarmeLimite = sizeof(alarme1) / sizeof(alarme1[0]);

// data         hh:dd - DD/MM/AA - d
byte data[] = { 0, 0, 0, 0, 0, 0 };
byte maxData[] = { 24, 60, 32, 13, 100, 7 };

byte posData = 0;
byte posDataLimite = sizeof(data) / sizeof(data[0]);

// telas
byte telaAtual = 0;
byte telaLimite = 4;

// text
String linha1 = "";
String linha2 = "";







