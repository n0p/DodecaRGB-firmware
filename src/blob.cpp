#include <Blob.h>

/* 
Blobs are points that orbit a sphere at given radius. 
As they orbit, they leave a trail of color behind them.
Each blob has a color, and a radius.
They also have velocity in the A and C angles.
Every loop, the angles are updated by the velocity by calling the tick() function
*/
Blob::Blob(){
  this->reset();
}

void Blob::reset(){
  this-> lifespan = random(30000+4000);
  this->av = 0;
  this->cv = 0;
  this->a = random(TWO_PI);  // rotation angle of blob
  this->c = random(TWO_PI);  // elevation angle of blob
  this->applyForce(random(50,200)/1000.0, random(50, 200)/1000.0);
  this->color = CHSV((millis()/1000)%255, 250, 200+random(50));
  this->radius = random(50,130);
  this->age = 0;
  this->lifespan = random(3000)+3000;
}

int Blob::x(){ return sphere_r * sin(c)*cos(a); }
int Blob::y(){ return sphere_r * sin(c)*sin(a); }
int Blob::z(){ return sphere_r * cos(c); }

void Blob::applyForce(float a, float c){
  this->av += a;
  this->av = constrain(this->av, max_accel*-1, max_accel);
  this->cv += c;
  this->cv = constrain(this->cv, max_accel/2*-1, max_accel/2);
}

void Blob::tick(){
  // animate angles with velocity
  this->age++;
  this->a += av;
  this->c += cv;
  if (random(500)==1){
    float ar = random(5,50)/2000.0 * (random(2)==1 ? 1 : -1);
    float cr = random(5,50)/2000.0 * (random(2)==1 ? 1 : -1);
    this->applyForce(ar, cr);
  }
  if (this->lifespan - this->age < 100){
    this->radius *= 0.95;
  }
  if (this->lifespan - this->age < 255){
    this->color.fadeToBlackBy(1);
  }
  if (this->age > this->lifespan){
    this->reset();
  }
}