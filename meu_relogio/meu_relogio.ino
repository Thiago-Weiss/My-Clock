// tela lcd
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27
#define colunas   16
#define linhas    2


// minha frase
// XXXXXXXXXXXXXXXX
// HH:MM:SS sabado
// XXXDD/MM/AAAAXXX
// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);



//relogio
#include <virtuabotixRTC.h>

#define   clk   6
#define   dat   7
#define   rst   8
virtuabotixRTC   myRTC(clk, dat, rst);
// ========================================================================================================
// --- Protótipo das Funções ---
void DS1302();
String week(int dayW);


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()  
{     
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY
  Serial.begin(9600);
  Serial.println("teste");

}


// ========================================================================================================
// --- Loop Infinito ---
void loop()  
{
  DS1302();
  delay(1000);
}


// ===========================================c:\Users\Eu\AppData\Local\Arduino15\libraries\LiquidCrystal_I2C\examples\I2C_scanner_port\I2C_scanner_port.ino=============================================================
// --- Desenvolvimento das Funções ---
void DS1302()
{

  String linha1 ="";
  String linha2 ="";
  myRTC.updateTime();
  linha1 += (myRTC.hours < 10 ? "0" : "") + String(myRTC.hours) + ":";
  linha1 += (myRTC.minutes < 10 ? "0" : "") + String(myRTC.minutes) + ":";
  linha1 += (myRTC.seconds < 10 ? "0" : "") + String(myRTC.seconds) + " ";
  linha1 += week(myRTC.dayofweek);
  lcd.setCursor(0, 0); 
  lcd.print(linha1);

  linha2 += "-- ";
  linha2 += padNumber(myRTC.dayofmonth, 2) + "/";
  linha2 += padNumber(myRTC.month, 2) + "/";
  linha2 += padNumber(myRTC.year, 4);
  linha2 += " --";

  lcd.setCursor(0,1);
  lcd.print(linha2);

}
 
String week(int dayW)
{
  
  switch(dayW)
  {
    case 1: return "Domingo";
    case 2: return "Segunda";
    case 3: return "Terca  ";
    case 4: return "Quarta ";
    case 5: return "Quinta ";
    case 6: return "Sexta  ";
    case 7: return "Sabado ";
  } 
} 

String padNumber(int number, int width) {
  String str = String(number);
  while (str.length() < width) {
    str = "0" + str;
  }
  return str;
}












