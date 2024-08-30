#define BUTTON_PIN    2    // Pino ao qual o botão está conectado
#define BUTTON_BOUNCE 50
#define BUTTON_PRESS  800

class Button{
  private: 
    int timeBounce           = BUTTON_BOUNCE;
    int timePress            = BUTTON_PRESS;
    unsigned int lastMove    = 0;
    bool last_status         = false;
    byte DigPin;
    void (*funcPressed)();
    void (*funcRelease)()    = nullptr;
  	void (*funcPress)()    	 = nullptr;
	const int x = 10;


  public:
    Button(uint8_t p, void (*press)()) {
      DigPin = p;
      pinMode(DigPin, INPUT);
      funcPressed = press;

    }

    void setTimeBounce(int val){
      timeBounce = val;
    }

    void setRelease(void (*release)()){
      funcRelease = release;
    }
  
  	void setPress(void (*press)()){
      funcPress = press;
    }
  
    void setPresed(void (*presed)()){
      funcPressed = presed;
    }

  
  	
    void att(){
      bool status   = digitalRead(BUTTON_PIN);
      int time      = millis() - lastMove;

      if (time < timeBounce) return;        // check bounce

      if (status == last_status){           // check switch state
        if (status and time > timePress){   // check button press
            if (funcPress != nullptr){
       			funcPress();
			}
        }
        return;
      }




      lastMove    = millis();
      last_status = status;
      
      if (status){                        // check pressed
        funcPressed();
      }else{                              // check relesed
        if (funcRelease != nullptr){
        funcRelease();
        }
      }
    }
};

int teste = 0;
void myFunction() {
  Serial.println("press");
  Serial.println(teste++);
}

Button bnt1(1, myFunction);

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  bnt1.att();
  
  int sensorValue = analogRead(A0);  // Lê o valor do pino analógico
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);  // Imprime o valor no monitor serial
  delay(200);
}

