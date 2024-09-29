#include <Wire.h>
#include "Gvars.h"
#include "displayText.h"
#include "funcsBnt.h"

//==========================================
/////////////// class RTC //////////////////
#define clk 3
#define dat 2
#define rst 5
virtuabotixRTC myRTC(clk, dat, rst);
//==========================================

//==========================================
/////////////// class temp //////////////////
Adafruit_AHTX0 sensorTemp;
//==========================================

//==========================================
/////////////// class LCD //////////////////

#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
//==========================================

//==========================================
/////////////// class Button ///////////////
#define BNT_PIN1 4
#define BNT_PIN2 7
#define BNT_PIN3 8

Button bnt1(BNT_PIN1, bnt_1_Funcs, true, true, false);
Button bnt2(BNT_PIN2, bnt_2_Funcs, true, true, false);
Button bnt3(BNT_PIN3, bnt_3_Funcs, true, true, false);
//==========================================

//==========================================
/////////////// class Timer ////////////////
Timer backMenuTimer(1000 * 30, backMenu); // 10s
Timer displayOffTimer(1000 * 120, displayTurnOff);      // 60s
//==========================================


//==========================================
/////////////// sound ///////////////
#define BUZZER_PIN 6

void setup()
{
  // buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

  // lcd
  pinMode(LCD_LIGHT, OUTPUT);
  digitalWrite(LCD_LIGHT, HIGH);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  backMenuTimer.stop();


}

void loop()
{
  bnt1.att();
  bnt2.att();
  bnt3.att();
  backMenuTimer.att();
  displayOffTimer.att();
  displayText();
}





