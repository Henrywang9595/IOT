// COMP-10184 – Mohawk College 
//student name: Zhenglin Wang, 000818211
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 
//It seems like I output the light turn on and off command reversed, when I wave my hand, the light off, after 10s it back to on.....
//And my senser seems broken, probabaly I open thel id and try to clean it but got it messy.... sorry for that.  
#include <Arduino.h> 
 
// digital input pin definitions 
#define PIN_PIR D5 
#define LED_DELAY 10000
 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
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
 
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  bPIR = digitalRead(PIN_PIR); 
 
  if(bPIR)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(LED_DELAY);
    digitalWrite(LED_BUILTIN, LOW);
  }
} 