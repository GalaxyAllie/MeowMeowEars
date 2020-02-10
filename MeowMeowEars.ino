// Set delay for rainbow generation
int delayTime = 20;

// Include Adafruit libraries
#include <Adafruit_NeoPixel.h>

// Configure light strips
#define flowerPin 0
#define flowerCount 10

Adafruit_NeoPixel flowers = Adafruit_NeoPixel(flowerCount, flowerPin, NEO_GRB + NEO_KHZ800);

void setup() {
    flowers.begin();
    flowers.show();
// - USE CAUTION ABOVE BRIGHTNESS 63!!! Linear regulator can get *hot* and battery life will be greatly reduced for little visible difference!
    flowers.setBrightness(63);
}

void loop() {
// 
// - Main Loop - uncomment section you want to run - 
// 
// - Rainbow Life -
// 
    for(long firstFlowerColour = 5*65536; firstFlowerColour > 0; firstFlowerColour -= 256) {
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            int colourSel = firstFlowerColour + (pixelSel * 65536L / flowerCount);
            uint32_t rainbowSel = flowers.gamma32(flowers.ColorHSV(colourSel));
            flowers.setPixelColor(pixelSel, rainbowSel);
        }
        flowers.show();
        delay(delayTime);
    }
// 
// - Twinkle Twinkle, Little Star -
// 
    // for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
    //     int catSelect = random(0, 10);
    //     if(catSelect == 3){
    //         flowers.setPixelColor(pixelSel, 0x00FFFFFF);
    //     }
    //     else{
    //         flowers.setPixelColor(pixelSel, 0x00000000);
    //     }
    // }
    // flowers.show();
    // delay(random(30,100));
}