// define some nice color palettes using the ColorPalette class

#include "palettes.h"

// Color palettes
// as an array of named palettes, each containing 6 CRGB colors.

ColorPalette::ColorPalette(const char *name, std::array<CRGB, 6> colors) {
    this->name = name;
    for (int i=0; i<6; i++) {
        this->colors[i] = colors[i];
    }
};

const int paletteCount = 7;

ColorPalette *palettes[paletteCount];

void initPalettes() {
    palettes[0] = new ColorPalette("Rainbow", {
        CRGB(255, 0, 0),
        CRGB(255, 127, 0),
        CRGB(255, 255, 0),
        CRGB(0, 255, 0),
        CRGB(0, 0, 255),
        CRGB(75, 0, 130)
    });
};




