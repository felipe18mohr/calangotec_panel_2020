#include <SDCard.hpp>

SDCard::SDCard(char* file_name, float save_frequency) {
  filename = file_name;
  save_freq = save_frequency;
  save_period = 1000/save_freq;
} 

bool SDCard::initSDCard(const int chip_select) {
  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(chip_select)) {
    Serial.println("SD Card failed, or not present");
    return false;
  }
  Serial.println("SD Card initialized.");
  
  log_file = SD.open(filename, FILE_WRITE);
  if (!log_file) {
    Serial.print("Error opening "); Serial.println(filename);
    return false;
  }

  last_millis = millis();

  return true;
}

bool SDCard::savePeriodically(int hour, int minute, int second, int cont_right, int cont_left, byte fuel_level, float velocity, float accel) {
  
  if (millis() - last_millis >= save_period) {
    String dataString = "-=-";
    dataString += String(hour) + ":" + String(minute) + ":" + String(second) +"\n";
    dataString += "L/R: " + String(cont_left) + "/" + String(cont_right) + "\n";
    dataString += "Fuel: " + String(fuel_level) + "\n";
    dataString += "Velocity: " + String(velocity) + "km/h\n";
    dataString += "Accel: " + String(accel) + "km/h2\n";

    last_millis = millis();
  }
}
