#pragma once

#ifndef PARTICLE_H
#define PARTICLE_H

#include <FastLED.h>
#include <vector>
#include <algorithm>
#include "points.h"

extern LED_Point points[];

#define MAX_LED_NEIGHBORS 6
#define MAX_PATH_LENGTH 11
#define PARTICLE_HOLD_TIME 10

struct distance_map {
    int led_number;
    float distance;
};

extern CRGB leds[];
extern bool compare_distance(distance_map a, distance_map b);
extern float calculatePointDistance(LED_Point p1, LED_Point p2);

class Particle {
    enum LedStatus {free, held};

    public:
        int led_number;
        CRGB color;
        int age;       
        std::vector<int> path; 
        int hold_time;
        LedStatus status;
        distance_map neighbors[MAX_LED_NEIGHBORS];

        void find_nearest_leds();
        void reset();
        void tick();

        Particle();

};

#endif