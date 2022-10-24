#include <Arduino.h> 
// digital input pin definitions
#define PIN_PIR D5
#define LED_DELAY 125
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
  bool bPIR;
  // read PIR sensor (true = Motion detected!). As long as there
  // is motion, this signal will be true. About 2.5 seconds after
  // motion stops, the PIR signal will become false.
  bPIR = digitalRead(PIN_PIR);
  if(bPIR)
  {
    for(int i=0;i<40;i++)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(LED_DELAY);
      digitalWrite(LED_BUILTIN, LOW);
      delay(LED_DELAY);
    }
  }
}
