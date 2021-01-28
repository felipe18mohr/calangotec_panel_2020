#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SoftwareSerial.h>
#include <Nextion.h>
#include <snippets.hpp>

class Display {
  public:
    Display(int rx, int tx, int page, int fuelID, char* fuelName,
            int velID, char* velName, int accelID, char* accelName,
            int rCountID, char* rCountName, int lCountID, char* lCountName,
            int hourID, char* hourName,int minuteID, char* minuteName);
            
    void updateDisplay(int hour, int minute,  
                       int right, int left, byte fuel,
                       float vel, float acc);

  private:
    SoftwareSerial displaySerial;
    NexProgressBar fuel_level;
    NexText velocity;
    NexText accel;
    NexText right_count;
    NexText left_count;
    NexText time_hour;
    NexText time_minute;

    int bar_fuel;
    char txt_vel[10];
    char txt_accel[10];
    char txt_right[10];
    char txt_left[10];
    char txt_hour[10];
    char txt_minute[10];
    
};

#endif
