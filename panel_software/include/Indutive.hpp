#ifndef INDUTIVE_HPP
#define INDUTIVE_HPP

#include <Arduino.h>

class Indutive{
    public:
        Indutive(char pin, char nc, double d, char div);
        void readSensor();
        void calcVel();
        void calcAccel();
        double vel_m_s;
        double vel_km_h;
        double accel_m_s2;
        double accel_km_h2;
        
    private:
        char pin_attached;
        char n_cog;
        char divide;
        char count;
        double diameter;
        double length;
        unsigned long time;
        unsigned int delta_time;
        double last_m_s;
        double last_km_h;
};

#endif