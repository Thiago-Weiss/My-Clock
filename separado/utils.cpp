#include "utils.h"

void nextVal(byte *val, byte maxVal)
{
  *val += 1;
  if (*val >= maxVal)
    *val = 0;
  backMenuTimer.reset();
  Serial.println(*val);
}

void backMenu()
{
  currentWindows = MENU;
  lcd.clear();
}

void attLight()
{
  displayLight = (displayOn ? (analogRead(LCD_LIGHT_VALUE) / 4) - 1 : 0);
  analogWrite(LCD_LIGHT, displayLight);
}

void displayTurnOn()
{
  Serial.println("luz on");

  displayOn = true;
  displayOffTimer.reset();
}

void displayTurnOff()
{
  Serial.println("luz off");
  displayOn = false;
}





