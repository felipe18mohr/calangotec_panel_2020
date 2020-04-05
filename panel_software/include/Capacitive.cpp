#include <Capacitive.hpp>

Capacitive::Capacitive(char cap1, char cap2){
    capl = cap1; 
    caph = cap2;
}

void Capacitive::readSensors(){
    low_level = digitalRead(capl);
    high_level = digitalRead(caph);
    level = low_level + high_level;
}