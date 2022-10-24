#include <Arduino.h> 
#define PIN_PIR D5
#define LED_DELAY 125
bool stopflag = true;
// *************************************************************
void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
  // configure the LED output
  pinMode(LED_BUILTIN, OUTPUT);
  // PIR sensor is an INPUT
  pinMode(PIN_PIR, INPUT);
}
// *************************************************************
void loop() {
  bool bPIR;
  // read PIR sensor (true = Motion detected!). As long as there
  // is motion, this signal will be true. About 2.5 seconds after
  // motion stops, the PIR signal will become false.
  bPIR = digitalRead(PIN_PIR);
  if(bPIR && stopflag)
  {
    for(int i=0;i<40;i++)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(LED_BUILTIN, LOW);
      delay(LED_DELAY);
    }
    stopflag = false;
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
