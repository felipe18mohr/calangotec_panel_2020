#include <snippets.hpp>
#include <Arduino.h>
#include <Wire.h>
#include <DS3231.h>
#include <MPU6050_tockn.h>
#include <Indutive.cpp>
#include <Capacitive.cpp>
#include <Gyroscope.cpp>
#include <SDCard.cpp>
#include <Display.cpp>

Display display(rx_ss, rx_ss, page_number, fuel_id, fuel_name,
                vel_id, vel_name, accel_id, accel_name,
                r_count_id, r_count_name, l_count_id, l_count_name,
                hour_id, hour_name, minute_id, minute_name);
Indutive ind(pin_ind, cog, diam, 2);
Capacitive cap(pin_capl, pin_caph);
Gyroscope gyro(angle, central_angle);
SDCard sdcard("log.txt", 1);
DS3231 rtc;


void printInfos();
void setRTC();
void indCB();

void setup() {
  Serial.begin(9600);
  nexInit();
  attachInterrupt(digitalPinToInterrupt(pin_ind), indCB, RISING);
  sdcard.initSDCard(pin_chip_select);
  setRTC();
}

void loop() {
  static bool h12, PM;
  cap.readSensors();
  gyro.steeringWheelTurning();
  sdcard.savePeriodically(rtc.getHour(h12,PM), rtc.getMinute(), rtc.getSecond(),
                          gyro.right_count, gyro.left_count, cap.level, 
                          ind.vel_km_h, ind.accel_km_h2);
  display.updateDisplay(rtc.getHour(h12, PM), rtc.getMinute(),
                        gyro.right_count, gyro.left_count, cap.level, 
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
  Serial.println(gyro.right_count);
  Serial.print("Left Cont: ");
  Serial.println(gyro.left_count);
  
  Serial.print("Fuel level: ");
  Serial.println(cap.level);

  Serial.print("Velocity (km/h): ");
  Serial.println(ind.vel_km_h);
  Serial.print("Accel (km/h^2): ");
  Serial.println(ind.accel_km_h2);

  Serial.println("-=-");

}
