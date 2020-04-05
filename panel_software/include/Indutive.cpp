#include <Indutive.hpp>

Indutive::Indutive(byte pin, byte nc, double d, byte div){
    pin_attached = pin;
    n_cog = nc;
    diameter = d;
    divide = div;
    length = diameter*PI;
    count = 0;
    time = millis();
    vel_m_s = last_m_s = 0.0;
    vel_km_h = last_km_h = 0.0;
    accel_m_s2 = 0.0;
    accel_km_h2 = 0.0;
}

void Indutive::readSensor(){
    count++;
    if(count >= (n_cog/divide)){
        count = 0;
        delta_time = (millis() - time) / 1000;
        time = millis();
        calcVel();
        calcAccel();
    }
}

void Indutive::calcVel(){
    last_m_s = vel_m_s;
    last_km_h = vel_km_h;
    vel_m_s = length/delta_time;
    vel_m_s /= divide;
    vel_km_h = 3.6 * vel_m_s;
}

void Indutive::calcAccel(){
    accel_m_s2 = (vel_m_s - last_m_s) / delta_time;
    accel_km_h2 = (vel_km_h - last_km_h) / delta_time;
}