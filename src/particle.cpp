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
    this->find_nearest_leds();
}

void Particle::tick() {
    this->age++;
    if (this->age > this->hold_time) {
        this->status = held;
        int next_led = -1;
        int i = 1;
        while (next_led == -1) {
            if (std::find(this->path.begin(), this->path.end(), this->neighbors[i].led_number) == this->path.end()) {
                if (leds[this->neighbors[i].led_number] == CRGB::Black){
                    next_led = this->neighbors[i].led_number;
                } else {
                    i++;               
                }
            } else {
                i++;
                if (random(20)==0) i++;
            }
            if (i >= MAX_LED_NEIGHBORS) {
                next_led = this->neighbors[1].led_number;
            }                 
        }
        this->led_number = next_led;
        this->find_nearest_leds();
        this->path.insert(this->path.begin(), this->led_number);
        this->path.resize(MAX_PATH_LENGTH);
        this->age = 0;
    }
}

float calculatePointDistance(LED_Point p1, LED_Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
};

bool compare_distance(distance_map a, distance_map b) {
    return a.distance < b.distance;
}

void Particle::find_nearest_leds() {
    std::vector<distance_map> candidate_points;
    for (int i=0; i<NUM_LEDS; i++) {
        distance_map d;
        d.led_number = i;
        d.distance = calculatePointDistance(points[this->led_number], points[i]);
        candidate_points.push_back(d);
    }
    // sort the candidate points by distance
    std::sort(candidate_points.begin(), candidate_points.end(), compare_distance);
    candidate_points.resize(MAX_LED_NEIGHBORS);
    
    for (int i=0; i<candidate_points.size(); i++) {
        this->neighbors[i] = candidate_points[i];
    } 
    
}