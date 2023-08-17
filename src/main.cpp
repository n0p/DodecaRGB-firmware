#include <Arduino.h>
#include <FastLED.h>
#include <WiFiManager.h>
#include <cmath>
#include "points.h"

/*

We have a dodecahedron with 12 sides. 
Each side is a pentgon-shaped PCB circuit board with RGB LEDs arranged on them, spaced evenly. 
An ESP32 is used to control the LEDs, using the Arduino environment and FastLED library.
Each pentagon side contains 26 RGB leds on a circuit board, arranged in the following way:
- 1 central LED in the exact middle of each side
- a ring of 10 LEDs in a circle around the central LED
- 15 LEDs around the edges, in groups of 3, spaced evenly around the edge of the pentagon
The LEDs on each face of the dodecahedron are wired in series so that the central LED is first, 
the ring LEDs come next, and the edge LEDs after that. 
Each side connects to the next, in series. 
We need to define a C++ function called "setPixel(xr,yr)" which takes two angles in radians 
and returns the best matching LED number. 
The dodecahedron has 12 sides. The code should calculate which side is needed based on the angle and configuration. 
If side 0 has pixels 1 to 26, then side 1 would have pixels 27 to 52, and so on. 
As the PCB circuit boards are wired together to form the dodecahedron, the arrangement of the sides must be 
configurable, as there are many possible configurations. 
In addition, the rotation of each side must be defined, as it can have five possible rotations.
*/

// Timezone config
/* 
  Enter your time zone (https://remotemonitoringsystems.ca/time-zone-abbreviations.php)
  See https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv for Timezone codes for your region
  based on https://github.com/SensorsIot/NTP-time-for-ESP8266-and-ESP32/blob/master/NTP_Example/NTP_Example.ino
*/
const char* NTP_SERVER = "ch.pool.ntp.org";
const char* TZ_INFO    = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";  // Switzerland

// Wifi
WiFiManager wm;   // looking for credentials? don't need em! ... google "ESP32 WiFiManager"

// LED configs
#define BRIGHTNESS  255

#define NUM_COLORS 10
CRGB my_colors[] = {
  CHSV(60, 255, 128),    // Bright yellow
  CHSV(32, 200, 110),    // Radiant orange
  CHSV(160, 179, 100),   // Sky blue
  CHSV(96, 160, 70),     // Forest green
  CHSV(213, 250, 80),    // Rich purple
  CHSV(240, 80, 90),    // Soft pink
  CHSV(125, 190, 90),    // Deep aqua
  CHSV(64, 50, 90),     // Creamy white
  CHSV(31, 140, 90),    // Warm brown
  CHSV(180, 10, 65),       // Cool gray
  CHSV(80, 50, 65)       // ?
};

CRGB leds[NUM_LEDS];


// Constants
const int LEDS_PER_RING = 10;
const int LEDS_PER_EDGE = 15;

// Configuration variables (change according to the dodecahedron's arrangement)
int sideOrder[NUM_SIDES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int sideRotation[NUM_SIDES] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1};

// Time 
tm timeinfo;
time_t now;
int hour = 0;
int minute = 0;
int second = 0;

// Time, date, and tracking state
int t = 0;
int number = 0;
int animation=0;
String formattedDate;
String dayStamp;
long millis_offset=0;
int last_hour=0;

// Days of week. Day 1 = Sunday
String DoW[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

// Months
String Months[] { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

String getFormattedDate(){
  char time_output[30];
  strftime(time_output, 30, "%a  %d-%m-%y", &timeinfo);
  return String(time_output);
}

String getFormattedTime(){
  char time_output[30];
  strftime(time_output, 30, "%H:%M:%S", &timeinfo);
  return String(time_output);
}

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(wm.getConfigPortalSSID());
}

bool getNTPtime(int sec) {
  if (WiFi.isConnected()) {
    bool timeout = false;
    bool date_is_valid = false;
    long start = millis();

    Serial.println(" updating:");
    configTime(0, 0, NTP_SERVER);
    setenv("TZ", TZ_INFO, 1);

    do {
      timeout = (millis() - start) > (1000 * sec);
      time(&now);
      localtime_r(&now, &timeinfo);
      Serial.print(" . ");
      date_is_valid = timeinfo.tm_year > (2016 - 1900);
      delay(100);
      
      // TODO: show animation

    } while (!timeout && !date_is_valid);
    
    if (!date_is_valid){
      Serial.println("Error: Invalid date received!");
      Serial.println(timeinfo.tm_year);
      return false;  // the NTP call was not successful
    } else if (timeout) {
      Serial.println("Error: Timeout while trying to update the current time with NTP");
      return false;
    } else {
      Serial.println("\n[ok] time updated: ");
      Serial.print("System time is now:");
      Serial.println(getFormattedTime());
      Serial.println(getFormattedDate());
      return true;
    }
  } else {
    Serial.println("Error: Update time failed, no WiFi connection!");
    return false;
  }
}

void ConnectToWifi(){
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  wm.setAPCallback(configModeCallback);

  //wm.resetSettings();   // uncomment to force a reset
  bool wifi_connected = wm.autoConnect("ESP32_RGB_Ticker");
  int t=0;
  if (wifi_connected){
    Serial.println();
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC address: ");
    Serial.println(WiFi.macAddress());
    Serial.print("RSSI: ");
    Serial.print(WiFi.RSSI());
    Serial.println("db");

    delay(1000);

    Serial.println("getting current time...");
    
    if (getNTPtime(10)) {  // wait up to 10sec to sync
      Serial.println("Time sync complete");
    } else {
      Serial.println("Error: NTP time update failed!");
    }
  } else {
    Serial.println("ERROR: WiFi connect failure");
    // update fastled display with error message
  }
}

void color_show(){
  // light up all LEDs in sequence
  CRGB color = CRGB::White;
  int c = random(1,255-NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    color.setHSV(c+i, 255, 128);
    leds[i] = color;
    if (digitalRead(0) == LOW){
      return;
    } else {
      delay(20);
      FastLED.show();
    }
  }
  delay(100);
  // turn off all LEDs in a dissolving pattern
  for (int x=0; x<50; x++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i].fadeToBlackBy(3+random(5));
    }
    if (digitalRead(0) == LOW){
      return;
    } else {
      FastLED.show();
      delay(50);
    }
  }
}

void solid_sides(){
  int start_color = random(NUM_COLORS);
  for (int s=0; s<NUM_SIDES; s++){
    for (int level=255; level>50; level-=1){
      for (int i=s*LEDS_PER_SIDE; i<(s+1)*LEDS_PER_SIDE; i++){
        CRGB c = my_colors[(start_color + s) % NUM_COLORS];
        leds[i] = c.fadeToBlackBy(level);;
      }
      FastLED.show();
      if (digitalRead(0) == LOW) break;
      delay(2);
    }
    if (digitalRead(0) == LOW) break;
    delay(300);    
    for (int level=50; level<255; level+=1){
      for (int i=(s+1)*LEDS_PER_SIDE; i<(s+2)*LEDS_PER_SIDE; i++){
        CRGB c = my_colors[(start_color + s + 1) % NUM_COLORS];
        leds[i] = c.fadeToBlackBy(level);
      }
      FastLED.show();
      if (digitalRead(0) == LOW) break;
      delay(2);
    }
  }
}

void flash_fade_points(){
  // randomly light up LEDs and fade them out individually, like raindrops
  static float add_strength = 10.0;
  if (true){
    for (int n=0; n<12; n++){
      CRGB c = CRGB(
          (sin(millis()/3000.0) + 1.0) * add_strength,
          (cos(millis()/7000.0) + 1.0) * add_strength,
          (sin(millis()/5000.0) + 1.0) * add_strength*0.8
        );
      if (random(2)==1){
        int r1 = random(n*LEDS_PER_SIDE+1, (n+1)*LEDS_PER_SIDE+10);
        int r2 = random(n*LEDS_PER_SIDE+11, (n+1)*LEDS_PER_SIDE+26);
        leds[r1] += c; 
        leds[r2] += c;
        if (random(10) == 0){
          leds[n*LEDS_PER_SIDE] += c.fadeToBlackBy(50);
        }
      }
    }
  }
  for (int i = 0; i < NUM_LEDS; i++){
    if (true){
      int l = leds[i].getLuma();
      leds[i].fadeToBlackBy(max(1,l/4));
    }
  }
  FastLED.show();   
  delay(20);  
}


// Function to calculate the closest LED number
int setPixel(double a, double c) {
  int ledNumber = 0;
  return ledNumber;

}

float xr,yr = 0;
void tracers(){
    FastLED.clear();
    int led = setPixel(xr,yr);
    leds[led] = CRGB::GreenYellow;
    Serial.print("LED:");
    Serial.println(led);
    // print the xy,yr,zr to serial
    Serial.print("x:");
    Serial.print(xr);
    Serial.print(" y:");
    Serial.println(yr);  
    
    xr = fmod(xr+ 0.1, 2*PI);
    yr = fmod(yr+ 0.1, 2*PI);
    FastLED.show();
    delay(300);
}

void fade_test(){
  static float ci = -300;
  static int target = 40;
  CRGB c = CRGB(0,0,0);
  for (int i = 0; i<NUM_LEDS; i++){
    float d = (ci - points[i].z);
    if (abs(d) < target) {
        float off = target - abs(d);
        c = CRGB(target+off*2, target+off*2, target);
        leds[i] = c;
        Serial.println(points[i].z);
    } else {
      leds[i] = CRGB(0,0,0);
    }
    ci = (ci+0.005);
    if (ci > 350) ci = -350;
  }
  FastLED.show();
}

void setup() {
  // set up fastled
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, 5, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  pinMode(0, INPUT_PULLUP);
  // ConnectToWifi();
  //news = fetchHeadlines();
  delay(500);
  Serial.println("Start");
}


int mode = 0;
void loop() {

  if (digitalRead(0) == LOW){
    Serial.print("Button pressed, changing mode to ");
    mode = (mode + 1) % 4;
    Serial.println(mode);
 
    while (digitalRead(0) == LOW){
      CRGB c = CRGB::White;
      FastLED.setBrightness(BRIGHTNESS);
      c.setHSV(millis()/20 % 255, 255, 128);
      FastLED.showColor(c);
      FastLED.show(); 
      delay(10); 
    }
    Serial.println("Button released");
  }
  if (mode == 0){
    fade_test();
  }
  if (mode == 1){
    flash_fade_points();
  }
  if (mode == 2){
    color_show();    
  }
  if (mode==3){
    solid_sides();
  }
  
}