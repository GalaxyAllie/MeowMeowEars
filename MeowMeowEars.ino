// Set delay for rainbow generation
int delayTime = 20;

// Create variables used later
int colourSel = 0;
int pixelDisp = 0;
int incomingInt = 0;

// Include Adafruit libraries
#include <Adafruit_NeoPixel.h>

// Configure light strips
#define flowerPin 0
#define flowerCount 10
 
Adafruit_NeoPixel flowers = Adafruit_NeoPixel(flowerCount, flowerPin, NEO_GRB + NEO_KHZ800);

void setup() {
    flowers.begin();
    flowers.show();
    flowers.setBrightness(15);
}

void loop() {
    for(long firstFlowerColour = 5*65536; firstFlowerColour > 0; firstFlowerColour -= 256) {
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            int colourSel = firstFlowerColour + (pixelSel * 65536L / flowerCount);
            uint32_t rainbowSel = flowers.gamma32(flowers.ColorHSV(colourSel));
            flowers.setPixelColor(pixelSel, rainbowSel);
        }
        flowers.show();
        delay(delayTime);
    }
}