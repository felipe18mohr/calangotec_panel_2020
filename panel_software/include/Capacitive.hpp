#ifndef CAPACITIVE_HPP
#define CAPACITIVE_HPP

#include <Arduino.h>

class Capacitive{
    public:
        Capacitive::Capacitive(byte cap1, byte cap2);
        void readSensors();
        byte level;
    private:
        byte capl, caph;
        bool low_level;
        bool high_level;
};

#endif