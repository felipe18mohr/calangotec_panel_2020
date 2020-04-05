#include <Arduino.h>
#include <snippets.hpp>
#include <Indutive.cpp>

Indutive ind(pin_ind, cog, diam);

void setup() {
  attachInterrupt(digitalPinToInterrupt(pin_ind), ind.readSensor, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
}