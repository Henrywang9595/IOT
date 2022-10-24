#include <Arduino.h> 
#define PIN_PIR D5
#define PIN_BUTTON D6
#define LED_DELAY 125
#define LED_CNT 80
bool bPIR=false, bBUTTON=false;
bool state = true;
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
  if(bPIR)
  {
    bDELAY = 1;
    lasttime = millis();
  }
  if(bBUTTON)
  {
    if(bDELAY>0 && bDELAY<=LED_CNT && state)
    {
      state = false;
      digitalWrite(LED_BUILTIN,LOW);
    }
    else
    {
      state = true;
      bDELAY = 0;
    }
    delay(200);
  }
  if((bDELAY>0&&bDELAY<=LED_CNT)&&state)
  {
    if(millis()-lasttime>=LED_DELAY)
    {
      lasttime = millis();
      digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
      bDELAY++;
    }
  }
}
