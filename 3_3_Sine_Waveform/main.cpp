#include "mbed.h"

const double pi = 3.141592653589793238462;
const double amplitude = 0.5f;
const double offset = 65535 / 2;

// The sinwave is created on this pin
// Adjust analog output pin name to your board spec.
AnalogOut aout(PA_4);

int main()
{
    double rads = 0.0;
    uint16_t sample = 0;

    while (1) {
        // sinewave output
        for (int i = 0; i < 360; ++i) {
            rads = (pi * i) / 180.0f;
            // In order to let the output won't be negative, so we plus offset at the end.
            sample = (uint16_t)(amplitude * (offset * (cos(rads + pi) + offset))); 
            aout.write_u16(sample);
            
        }
    }


}