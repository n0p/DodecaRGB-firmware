#pragma once

#ifndef PARTICLE_H
#define PARTICLE_H

#include <FastLED.h>
#include <vector>
#include <algorithm>
#include "points.h"

extern LED_Point points[];

#define MAX_PATH_LENGTH 11
#define PARTICLE_HOLD_TIME 15

extern CRGB leds[];

class Particle {
    enum LedStatus {free, held};

    public:
        int led_number;
        CRGB color;
        int age;       
        std::vector<int> path; 
        int hold_time;
        LedStatus status;

        void reset();
        void tick();

        Particle();

};

#endif