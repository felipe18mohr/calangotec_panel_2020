#include <Display.hpp>

Display::Display(int rx, int tx, int page, 
                 int fuelID, char* fuelName,
                 int velID, char* velName, 
                 int accelID, char* accelName,
                 int rCountID, char* rCountName, 
                 int lCountID, char* lCountName,
                 int hourID, char* hourName,
                 int minuteID, char* minuteName) : 
      displaySerial{rx, tx}, 
      fuel_level{page, fuelID, fuelName},
      velocity{page, velID, velName}, 
      accel{page, accelID, accelName},
      right_count{page, rCountID, rCountName}, 
      left_count{page, lCountID, lCountName},
      time_hour{page, hourID, hourName},
      time_minute{page, minuteID, minuteName} {
  
  displaySerial.begin(9600);
  nexInit();
}

void Display::updateDisplay(int hour, int minute,  
                            int right, int left, byte fuel, 
                            float vel, float acc) {
  
  bar_fuel = map(fuel, 0, 2, 20, 90);
  fuel_level.setValue(bar_fuel);

  memset(txt_vel, 0, sizeof(txt_vel));
  itoa(vel, txt_vel, 10);
  velocity.setText(txt_vel);

  memset(txt_accel, 0, sizeof(txt_accel));
  itoa(acc, txt_accel, 10);
  accel.setText(txt_accel);

  memset(txt_right, 0, sizeof(txt_right));
  itoa(right, txt_right, 10);
  right_count.setText(txt_right);

  memset(txt_left, 0, sizeof(txt_left));
  itoa(left, txt_left, 10);
  left_count.setText(txt_left);

  memset(txt_hour, 0, sizeof(txt_hour));
  itoa(hour, txt_hour, 10);
  time_hour.setText(txt_hour);

  memset(txt_minute, 0, sizeof(txt_minute));
  itoa(minute, txt_minute, 10);
  time_minute.setText(txt_minute);  

}
