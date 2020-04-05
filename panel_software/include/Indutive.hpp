#ifndef INDUTIVE_HPP
#define INDUTIVE_HPP

#include <Arduino.h>

class Indutive{
    public:
        Indutive(int pin, int n, double d);
        void readSensor();
        void calcVel();
        void calcAccel();
        double vel_m_s;
        double vel_km_h;
        double accel_m_s2;
        double accel_km_h2;
        
    private:
        int pin_attached;
        int n_cog;
        int count;
        double diameter;
        double length;
        unsigned long time;
        unsigned int delta_time;
        double last_m_s;
        double last_km_h;
};

#endif