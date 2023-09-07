#pragma once
#include <FastLED.h>

class Blob {
  public:
    int sphere_r = 290; // radius of sphere the blob orbits
    int radius; // radius of blob
    float a,c = 0;  // polar angles
    float av;  // velocity of angles in radians
    float cv;  // velocity of angles in radians
    const float max_accel = 0.04;
    long age;
    long lifespan;

    CRGB color;

    // constructor
    Blob();

    void reset();
    int x();
    int y();
    int z();
    void applyForce(float a, float c);
    void tick();

};

