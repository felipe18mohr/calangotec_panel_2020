#include <Arduino.h>
#include <snippets.hpp>
#include <Indutive.cpp>
#include <Capacitive.cpp>
#include <DS3231.h>

Indutive ind(pin_ind, cog, diam, 2);
Capacitive cap(pin_capl, pin_caph);
DS3231 rtc;

void setRTC();

void setup() {
  attachInterrupt(digitalPinToInterrupt(pin_ind), ind.readSensor, RISING);
  setRTC();
}

void loop() {
  cap.readSensors();
}

void setRTC(){
  rtc.setSecond(8);
  rtc.setMinute(29);
  rtc.setHour(13);
  rtc.setDate(5);
  rtc.setDoW(7);
  rtc.setMonth(4);
  rtc.setYear(2020);
  rtc.setClockMode(false);
}