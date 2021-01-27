#include <Capacitive.hpp>

Capacitive::Capacitive(byte cap1, byte cap2){
    capl = cap1; 
    caph = cap2;
}

byte Capacitive::readSensors(){
    low_level = digitalRead(capl);
    high_level = digitalRead(caph);
    level = low_level + high_level;
    return level;
}
