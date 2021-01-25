#ifndef GYROSCOPE_HPP
#define GYROSCOPE_HPP

#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

class Gyroscope{
  public:
    Gyroscope(double ang1, double ang2);
    void steeringWheelTurning();
    int left_cont, right_cont;

  private:
    MPU6050 mpu6050;
    char last_state;
    double ang, cent_ang;
    double yaw;
};

#endif