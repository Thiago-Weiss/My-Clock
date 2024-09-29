#include <Wire.h>
#include "Gvars.h"
#include "SwitchWindows.h"
#include "displayText.h"



//==========================================
/////////////// class lcd //////////////////
#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
//==========================================

#include "virtuabotixRTC.h"

#define clk 2
#define dat 3
#define rst 5
virtuabotixRTC myRTC(clk, dat, rst);

//==========================================
/////////////// class button ///////////////
#define BNT_PIN1 4
#define BNT_PIN2 7
#define BNT_PIN3 8

Button bnt1(BNT_PIN1, switchWindows, &telaAtual, telaLimite);
Button bnt2(BNT_PIN2, nullptr, &asd, 10);
Button bnt3(BNT_PIN3, nullptr, &asd, 10);
//==========================================


void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  bnt1.att();
  bnt2.att();
  bnt3.att();
  displayText();

}


// problema no showalarm