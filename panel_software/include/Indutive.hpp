#ifndef INDUTIVE_HPP
#define INDUTIVE_HPP

#include <Arduino.h>

class Indutive{
    public:
        Indutive(byte pin, byte nc, double d, byte div);
        void readSensor();
        void calcVel();
        void calcAccel();
        double vel_m_s;
        double vel_km_h;
        double accel_m_s2;
        double accel_km_h2;
        
    private:
        byte pin_attached;
        byte n_cog;
        byte divide;
        byte count;
        double diameter;
        double length;
        unsigned long time;
        unsigned int delta_time;
        double last_m_s;
        double last_km_h;
};

#endif
