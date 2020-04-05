#include <Arduino.h>
#include <snippets.hpp>
#include <Indutive.cpp>
#include <Capacitive.cpp>

Indutive ind(pin_ind, cog, diam, 2);
Capacitive cap(pin_capl, pin_caph);

void setup() {
  attachInterrupt(digitalPinToInterrupt(pin_ind), ind.readSensor, RISING);
}

void loop() {
  cap.readSensors();  
}