// Sample Arduino code for Meow Meow Ears v3 with Adafruit Trinket M0 bootloader/Arduino board
// Uncomment the code block you wish to run (rainbow uncommented by default)

// Include Adafruit libraries
#include <Adafruit_NeoPixel.h>

// Setup variables

int delayTime = 20;
int redValue = 127;
int greenValue = 0;
int blueValue = 32;
int catSelect = 0;
int colourIncrement = 1;
int pixelDisp = 0;

// Configure light strips
#define flowerPin 0
#define flowerCount 10

Adafruit_NeoPixel flowers = Adafruit_NeoPixel(flowerCount, flowerPin, NEO_GRB + NEO_KHZ800);

void setup() {
    flowers.begin();
    flowers.show();
// - USE CAUTION ABOVE BRIGHTNESS 50!!! 
// Linear regulator can get *hot* and battery life will be greatly reduced for little visible difference!
// - NOT recommended to run above 127 (half brightness) as designed
// ...linear regulator may get very hot above 127 brightness depending on light pattern.
    flowers.setBrightness(50);
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
    //     int catSelect = random(0, 9);
    //     if(catSelect == 3){
    //         flowers.setPixelColor(pixelSel, 0x00FFFFFF);
    //     }
    //     else{
    //         flowers.setPixelColor(pixelSel, 0x00000000);
    //     }
    // }
    // flowers.show();
    // delay(random(40, 120));
// 
// - Twinkle Twinkle, Little Star: Pink and Purple Edition -
// 
    // for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
    //     catSelect = random(0, 9);
    //     if(catSelect == 3){
    //         flowers.setPixelColor(pixelSel, random(32, 255), 0, random(32, 255));
    //     }
    //     else{
    //         flowers.setPixelColor(pixelSel, 0x00000000);
    //     }
    // }
    // flowers.show();
    // delay(random(55, 140));
// 
// - Pink to Purple Fade -
//     
    // for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
    //     flowers.setPixelColor(pixelSel, 127, 0, blueValue);
    // }
    // flowers.show();
    // delay(delayTime);
    // blueValue = blueValue + colourIncrement;
    // if(blueValue > 255){
    //     blueValue = 255;
    //     colourIncrement = -1;
    // }
    // if(blueValue < 32){
    //     blueValue = 32;
    //     colourIncrement = 1;
    // }
// 
// - Trans Pride -
// 
    // for(int pixelOffset = 0; pixelOffset < flowerCount; pixelOffset++){
    //     for(int pixelSel = 0; pixelSel < (flowerCount / 5); pixelSel++){
    //         if((pixelSel + pixelOffset) < flowerCount){
    //             pixelDisp = (pixelSel + pixelOffset);
    //         }
    //         else{
    //             pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
    //         }
    //         flowers.setPixelColor(pixelDisp, 31, 31, 255);
    //     }
    //     for(int pixelSel = (flowerCount / 5); pixelSel < (2 * (flowerCount / 5)); pixelSel++){
    //         if((pixelSel + pixelOffset) < flowerCount){
    //             pixelDisp = (pixelSel + pixelOffset);
    //         }
    //         else{
    //             pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
    //         }
    //         flowers.setPixelColor(pixelDisp, 191, 0, 100);
    //     }
    //     for(int pixelSel = (2 * (flowerCount / 5)); pixelSel < (3 * (flowerCount / 5)); pixelSel++){
    //         if((pixelSel + pixelOffset) < flowerCount){
    //             pixelDisp = (pixelSel + pixelOffset);
    //         }
    //         else{
    //             pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
    //         }
    //         flowers.setPixelColor(pixelDisp, 191, 120, 170);
    //     }
    //     for(int pixelSel = (3 * (flowerCount / 5)); pixelSel < (4 * (flowerCount / 5)); pixelSel++){
    //         if((pixelSel + pixelOffset) < flowerCount){
    //             pixelDisp = (pixelSel + pixelOffset);
    //         }
    //         else{
    //             pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
    //         }
    //         flowers.setPixelColor(pixelDisp, 191, 0, 100);
    //     }
    //     for(int pixelSel = (4 * (flowerCount / 5)); pixelSel < flowerCount; pixelSel++){
    //         if((pixelSel + pixelOffset) < flowerCount){
    //             pixelDisp = (pixelSel + pixelOffset);
    //         }
    //         else{
    //             pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
    //         }
    //         flowers.setPixelColor(pixelDisp, 31, 31, 255);
    //     }
    // flowers.show();
    // delay(500);
    // }
}