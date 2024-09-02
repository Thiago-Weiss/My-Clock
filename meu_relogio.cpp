#include <Wire.h>
#include <LiquidCrystal_I2C.h>


/////////////// class button ///////////////
/////////////// class button ///////////////
/////////////// class button ///////////////
#define BUTTON_BOUNCE 50
#define BUTTON_PRESS 800
class Button {
private:
  byte timeBounce = BUTTON_BOUNCE;
  byte timePress = BUTTON_PRESS;
  unsigned int lastMove = 0;
  bool last_status = true;
  byte digPin;
  void (*funcPressed)(byte *val, byte maxVal) = nullptr;
  void (*funcRelease)(byte *val, byte maxVal) = nullptr;
  void (*funcPress)(byte *val, byte maxVal)   = nullptr;
  byte *value;
  byte maxValue;

public:
  Button(byte p, void (*press)(byte *val, byte maxVal), byte *val, byte maxVal) {
    digPin = p;
    pinMode(digPin, INPUT);
    funcPressed = press;
    value = val;
    maxValue = maxVal;
  }

  void setTimeBounce(byte val) {
    timeBounce = val;
  }

  void setRelease(void (*release)()) {
    funcRelease = release;
  }

  void setPress(void (*press)()) {
    funcPress = press;
  }

  void setPresed(void (*presed)()) {
    funcPressed = presed;
  }

/////////////////////////////////////////////////////
  void teste(){
      Serial.println("press");
      Serial.println(funcPress == nullptr);
      Serial.println("release");
      Serial.println(funcRelease == nullptr);
  }
/////////////////////////////////////////////////////

  // step
  void att() {
    bool status = digitalRead(digPin);
    unsigned int time = millis() - lastMove;

    if (time < timeBounce) return;  // check bounce

    if (status == last_status) {          // check switch state
      if (status and time > timePress) {  // check button press
        if (funcPress != nullptr) {
          funcPress(value, maxValue);
        }
      }
      return;
    }

    lastMove = millis();
    last_status = status;

    if (status) {  // check pressed
        if (funcPressed != nullptr){
          funcPressed(value, maxValue);
        }
    } else {  // check relesed
      if (funcRelease != nullptr) {
        funcRelease(value, maxValue);
      }
    }
  }
};
////////////////////////////////////////////////////////////




/////////////// vars ///////////////
/////////////// vars ///////////////
/////////////// vars ///////////////

//   alarme          hh:mm d-s-t-q-q-s-s
byte alarme1[]    = {0,0,0,0,0,0,0,0,0};
byte alarme2[]    = {0,0,0,0,0,0,0,0,0};

byte* alarmes[]   = {alarme1, alarme2};
byte maxAlarme[]  = {24,60,1,1,1,1,1,1,1};

byte posAlarme    = 0;

// telas
byte telaAtual = 0;
byte telaLimite = 3;



////////////////////////////////////
/////////////// funcs //////////////
/////////////// funcs //////////////
/////////////// funcs //////////////

void clearBnt(Button* bnt){
  *bnt.setPresed(nullptr);
  *bnt.setPress(nullptr);
  *bnt.setRelease(nullptr);
}


void switchWindows(byte *val, byte maxVal){
  nextVal(val, maxVal);
  lcd.clear();
  switch (telaAtual){
    case 0:{ 
      clearBnt(bnt2);
      clearBnt(bnt3);
      break;
    }   
    case 1:{
      showConfigAlarm();
      break;
    }

  }
}

void nextVal(byte *val, byte maxVal) {
  *val += 1;
  if (*val >= maxVal)*val = 0;
  Serial.println(*val);
}

void displayText(){
  switch (telaAtual){
    case 0:{
      showMenu();
      break;
    }   
    case 1:{
      showConfigAlarm();
      break;
    }

  }
}

void showMenu(){
  lcd.setCursor(0, 0);
  lcd.print("menu");
  lcd.setCursor(0, 1);
  lcd.print("mostar hora");

/*
  String linha1 = "";
  myRTC.updateTime();
  linha1 += (myRTC.hours < 10 ? "0" : "") + String(myRTC.hours) + ":";
  linha1 += (myRTC.minutes < 10 ? "0" : "") + String(myRTC.minutes) + ":";
  linha1 += (myRTC.seconds < 10 ? "0" : "") + String(myRTC.seconds) + " ";
  linha1 += dayOfWeek(myRTC.dayofweek);
  lcd.setCursor(0, 0); 
  lcd.print(linha1);


  String linha2 = "";
  linha2 += "-- ";
  linha2 += (myRTC.dayofmonth < 10 ? "0": "") + String(myRTC.dayofmonth) + "/"
  linha2 += (myRTC.month < 10 ? "0": "") + String(myRTC.month) + "/"
  linha2 += String(myRTC.year);
  linha2 += " --";
  lcd.setCursor(0,1);
  lcd.print(linha2);
*/
}
 
String dayOfWeek(int dayW){
  switch(dayW){
    case 1: return "Domingo";
    case 2: return "Segunda";
    case 3: return "Terca  ";
    case 4: return "Quarta ";
    case 5: return "Quinta ";
    case 6: return "Sexta  ";
    case 7: return "Sabado ";
  } 
} 

void showConfigAlarm(){


}




void (*bntFuncs[])(byte*, byte) = {nullptr, nextVal};
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////




byte asd = 0;

#define BNT_PIN1 4
#define BNT_PIN2 7
#define BNT_PIN3 8

Button bnt1(BNT_PIN1, switchWindows, &telaAtual, telaLimite);
Button bnt2(BNT_PIN2, bntFuncs[1], &alarmes[0][0], maxAlarme[0]);
Button bnt3(BNT_PIN3, bntFuncs[0], &asd, 10);


#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(alarmes[0][0]);
  delay(50);
  Serial.print(alarmes[0][0]);
  bnt1.att();
  bnt2.att();
  bnt3.att();

}


/*  
byte customChar[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};
    lcd.write(byte(0)); // Exibe o caractere personalizado
*/

/*
EEPROM.write(10, 123);          // Escreve o valor 123 no endereço 10
EEPROM.update(10, 123);         // Atualiza o valor no endereço 10 se for diferente do valor atual (byte)
byte value = EEPROM.read(10);   // Lê o byte armazenado no endereço 10

int value;
EEPROM.get(10, value);  // Lê um int do endereço 10 e armazena na variável `value`

int value = 1234;
EEPROM.put(10, value);  // Escreve o valor `1234` no endereço 10

*/


/*

void functionA() {
  Serial.println("Function A called");
}

void functionB() {
  Serial.println("Function B called");
}

void functionC() {
  Serial.println("Function C called");
}

void (*func[])() = {functionA, functionB, functionC};

*/