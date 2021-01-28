#ifndef SDCARD_HPP
#define SDCARD_HPP

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDCard {
  public:
    SDCard(char* file_name, float save_frequency);
    bool initSDCard(const int chip_select);
    bool savePeriodically(int hour, int minute, int second, 
                          int cont_right, int cont_left, byte fuel_level, float velocity, float accel);

  private:
    File log_file;
    char* filename;
    float save_freq;
    float save_period;
    int last_millis;

};

#endif
