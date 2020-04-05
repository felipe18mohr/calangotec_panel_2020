#ifndef CAPACITIVE_HPP
#define CAPACITIVE_HPP

#include <Arduino.h>

class Capacitive{
    public:
        Capacitive::Capacitive(char cap1, char cap2);
        void readSensors();
        char level;
    private:
        char capl, caph;
        bool low_level;
        bool high_level;
};

#endif