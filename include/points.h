#pragma once
#ifndef POINTS_H
#define POINTS_H

#include <Arduino.h>
#include <vector>
#include <algorithm>
#include "points.h"

#define LEDS_PER_SIDE 26
#define NUM_SIDES 12
#define NUM_LEDS NUM_SIDES*LEDS_PER_SIDE  // 6x4 LEDs side, 6 sides for now
#define MAX_LED_NEIGHBORS 6

struct Vector3D {
    float x;
    float y;
    float z;
};

struct distance_map {
    int led_number;
    float distance;
    Vector3D direction;
};

// define X,Y,Z struct
class LED_Point {
  public:
    int index;
    float x;
    float y;
    float z;
    int side;       // which of the 12 sides it's on
    int label_num;  // which LED on the side (they are labelled)
  
    distance_map neighbors[MAX_LED_NEIGHBORS];
    void find_nearest_leds();

    // default constructor
    LED_Point(
      int i, float fx, float fy, float fz, 
      int fside, int flabel_num) : 
        index(i), x(fx), y(fy), z(fz), side(fside), label_num(flabel_num) { }
  
};

extern LED_Point points[];

extern bool compare_distance(distance_map a, distance_map b);
extern float calculatePointDistance(LED_Point p1, LED_Point p2);

#endif /* LED_POINTS_H_ */