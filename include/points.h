#pragma once
#ifndef POINTS_H
#define POINTS_H

#include <Arduino.h>

#define LEDS_PER_SIDE 26
#define NUM_SIDES 12
#define NUM_LEDS NUM_SIDES*LEDS_PER_SIDE  // 6x4 LEDs side, 6 sides for now

// define X,Y,Z struct
struct LED_Point {
  int index;
  float x;
  float y;
  float z;
  int side;       // which of the 12 sides it's on
  int label_num;  // which LED on the side (they are labelled)
  
  // default constructor
  LED_Point(
    int i, float fx, float fy, float fz, 
    int fside, int flabel_num) : 
      index(i), x(fx), y(fy), z(fz), side(fside), label_num(flabel_num) {}
  
};

extern LED_Point points[];


#endif /* LED_POINTS_H_ */