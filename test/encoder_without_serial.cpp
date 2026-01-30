#include <Arduino.h>

#define enc 2

volatile unsigned long count;

unsigned long t1 = millis();
unsigned long t2 = t1; //t2 for removing counter issue
unsigned long t3 = t1; //t3 for measuring time for rpm

void counter(){
  if ((t1-t2)>3){
  count++;
  t2 = t1;
  }
}

void setup(){
  t1 = millis();
  pinMode(enc, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enc), counter, RISING);
  Serial.begin(9600);

}

void  loop(){
  t1= millis();  
  if(t1-t3 >= 500){
    t3 = t1;
    noInterrupts();
    unsigned pulses = count;
    count = 0;
    interrupts();
    double rpm = (120/36)*pulses;
    Serial.println(rpm);
  }
}