#pragma once

#include <Arduino.h>
#include <WiFiManager.h>

extern const char* NTP_SERVER;    // defined in network.cpp
extern const char* TZ_INFO;       // defined in network.cpp
extern String DoW[];              // defined in network.cpp
extern String Months[];           // defined in network.cpp


String getFormattedDate();
String getFormattedTime();
void configModeCallback (WiFiManager *myWiFiManager);
bool getNTPtime(int sec);
bool ConnectToWifi(boolean force_reset=false);


