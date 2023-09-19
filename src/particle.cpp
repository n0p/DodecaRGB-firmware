#include "particle.h"

Particle::Particle() {
    this->reset();
}

void Particle::reset() {
    this->led_number = random(NUM_LEDS);
    this->color = CHSV(random(255), 255, 255);
    this->age = 0;
    this->hold_time = PARTICLE_HOLD_TIME;
    this->status = free;
}

void Particle::tick() {
    this->age++;
    if (this->age > this->hold_time) {
        this->status = held;
        int next_led = -1;
        int i = 1;
        while (next_led == -1) {
            LED_Point *p = &points[this->led_number];
            if (std::find(this->path.begin(), this->path.end(), p->neighbors[i].led_number) == this->path.end()) {
                if (leds[p->neighbors[i].led_number] == CRGB::Black){
                    next_led = p->neighbors[i].led_number;
                } else {
                    i++;               
                }
            } else {
                i++;
                if (random(20)==0) i++;
            }
            if (i >= MAX_LED_NEIGHBORS) {
                next_led = p->neighbors[1].led_number;
            }                 
        }
        this->led_number = next_led;
        this->path.insert(this->path.begin(), this->led_number);
        this->path.resize(MAX_PATH_LENGTH);
        this->age = 0;
    }
}

