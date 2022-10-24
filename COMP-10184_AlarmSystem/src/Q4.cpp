#include <Arduino.h> 
#define PIN_PIR D5
#define PIN_BUTTON D6
#define LED_DELAY 125
#define LED_CNT 80
bool bPIR=false, bBUTTON=false;
int bDELAY = 0;
long lasttime = 0;
// *************************************************************
void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
  // configure the LED output
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  // PIR sensor is an INPUT
  pinMode(PIN_PIR, INPUT);
  
}
// *************************************************************
void loop() {
  // read PIR sensor (true = Motion detected!). As long as there
  // is motion, this signal will be true. About 2.5 seconds after
  // motion stops, the PIR signal will become false.
  bPIR = digitalRead(PIN_PIR);
  bBUTTON = digitalRead(PIN_BUTTON);
  if(bPIR&&(bDELAY == 0))
  {
    bDELAY = 1;
    lasttime = millis();
  }
  if(bBUTTON && (bDELAY>0&&bDELAY<=LED_CNT))
  {
    bDELAY = 0;
    digitalWrite(LED_BUILTIN,LOW);
  }
  else if(bDELAY>LED_CNT)
  {
    //bDELAY = LED_CNT+1;
    digitalWrite(LED_BUILTIN,HIGH);
  }
  if(bDELAY>0&&bDELAY<=LED_CNT)
  {
    if(millis()-lasttime>=LED_DELAY)
    {
      lasttime = millis();
      digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
      bDELAY++;
    }
  }
}
