#include <Arduino.h>
#include <Wire.h>
#include <DS3231.h>
#include <MPU6050_tockn.h>
#include <snippets.hpp>
#include <Indutive.cpp>
#include <Capacitive.cpp>
#include <Gyroscope.cpp>
#include <SDCard.cpp>

Indutive ind(pin_ind, cog, diam, 2);
Capacitive cap(pin_capl, pin_caph);
Gyroscope gyro(angle, central_angle);
SDCard sdcard("log.txt", 1);
DS3231 rtc;

void printInfos();
void setRTC();
void indCB();

void setup() {
  attachInterrupt(digitalPinToInterrupt(pin_ind), indCB, RISING);
  sdcard.initSDCard(pin_chip_select);
  setRTC();
}

void loop() {
  static bool h12, PM;
  cap.readSensors();
  gyro.steeringWheelTurning();
  sdcard.savePeriodically(rtc.getHour(h12,PM), rtc.getMinute(), rtc.getSecond(),
                          gyro.left_cont, gyro.right_cont, cap.level, 
                          ind.vel_km_h, ind.accel_km_h2);
}

void setRTC() {
  rtc.setSecond(8);
  rtc.setMinute(29);
  rtc.setHour(13);
  rtc.setDate(5);
  rtc.setDoW(7);
  rtc.setMonth(4);
  rtc.setYear(2020);
  rtc.setClockMode(false);
}

void indCB() {
  ind.readSensor();
}

void printInfos() {
  static bool h12, PM;
  Serial.print(rtc.getHour(h12, PM)); Serial.print(":");
  Serial.print(rtc.getMinute()); Serial.print(":");
  Serial.println(rtc.getSecond());

  Serial.print("Right Cont: ");
  Serial.println(gyro.right_cont);
  Serial.print("Left Cont: ");
  Serial.println(gyro.left_cont);
  
  Serial.print("Fuel level: ");
  Serial.println(cap.level);

  Serial.print("Velocity (km/h): ");
  Serial.println(ind.vel_km_h);
  Serial.print("Accel (km/h^2): ");
  Serial.println(ind.accel_km_h2);

  Serial.println("-=-");

}
