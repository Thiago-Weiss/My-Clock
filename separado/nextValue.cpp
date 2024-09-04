#include "nextValue.h"

void nextVal(byte *val, byte maxVal) {
  *val += 1;
  if (*val >= maxVal) *val = 0;
  Serial.println(*val);
}

void nextValAlarm(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  bnt3.setValue(&alarmes[telaAtual - 1][posAlarme]);
  bnt3.setMaxValue(maxAlarme[posAlarme]);
}

void nextValData(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  bnt3.setValue(&data[posData]);
  bnt3.setMaxValue(maxData[posData]);
}