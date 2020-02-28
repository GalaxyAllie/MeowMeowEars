// Sample Arduino code for Meow Meow Ears v3 with Adafruit Trinket M0 bootloader/Arduino board
// Uncomment the code block you wish to run (rainbow uncommented by default)

// Include libraries
#include <Adafruit_NeoPixel.h>
#include <Adafruit_FreeTouch.h>
#include <adafruit_ptc.h>
#include <samd21_ptc_component.h>

// Setup variables

int delayTime = 20;
int redValue = 127;
int greenValue = 0;
int blueValue = 255;
int catSelect = 0;
int colourIncrement = 1;
int pixelDisp = 0;
int modeSel = 0;
int initialTouchValue = 500;
int touchValue = 0;
int counter = 0;

// Configure everything :) 
#define flowerPin 0
#define flowerCount 10

Adafruit_NeoPixel flowers = Adafruit_NeoPixel(flowerCount, flowerPin, NEO_GRB + NEO_KHZ800);
Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);

void setup() {
    Serial.begin(115200);
    flowers.begin();
    flowers.show();
// - USE CAUTION ABOVE BRIGHTNESS 50!!! 
// Linear regulator can get *hot* and battery life will be greatly reduced for little visible difference!
// - NOT recommended to run above 127 (half brightness) as designed
// ...linear regulator may get very hot above 127 brightness depending on light pattern.
    flowers.setBrightness(20);
    if (! qt_1.begin())  
        Serial.println("Failed to begin qt on pin A0");
    initialTouchValue = qt_1.measure();
}

bool capTouchDetect() {
    Serial.println("\n*** Touch Result ***");
    counter = millis();
    touchValue = qt_1.measure(); 
    Serial.print("Right Ear: "); Serial.print(touchValue);
    Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");   
    if(touchValue > (initialTouchValue + 100)){
        return true;
    }
    else{
        return false;
    }
}

void loop() {
// 
// - Main Loop - uncomment section you want to run - 
// 
// - Rainbow Life -
// 
    if(modeSel == 0)
    {
        for(long firstFlowerColour = 5*65536; firstFlowerColour > 0; firstFlowerColour -= 256) {
            for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
                int colourSel = firstFlowerColour + (pixelSel * 65536L / flowerCount);
                uint32_t rainbowSel = flowers.gamma32(flowers.ColorHSV(colourSel));
                flowers.setPixelColor(pixelSel, rainbowSel);
            }
            flowers.show();
            if(capTouchDetect() == true){
                delay(50);
                if(capTouchDetect() == true){
                    modeSel += 1;
                    delay(200);
                }
            }
            if(modeSel != 0){
                break;
            }
            delay(delayTime);
              int counter, result = 0;
        }
    }
// 
// - Twinkle Twinkle, Little Star -
// 
    else if (modeSel == 1)
    {    
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            int catSelect = random(0, 9);
            if(catSelect == 3){
                flowers.setPixelColor(pixelSel, 0x00FFFFFF);
            }
            else{
                flowers.setPixelColor(pixelSel, 0x00000000);
            }
        }
        flowers.show();
        delay(random(40, 120));
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel += 1;
                delay(200);
            }
        }
    }
// 
// - Twinkle Twinkle, Little Star: Pink and Purple Edition -
// 
    else if (modeSel == 2)
    {
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            catSelect = random(0, 9);
            if(catSelect == 3){
                flowers.setPixelColor(pixelSel, random(32, 255), 0, random(32, 255));
            }
            else{
                flowers.setPixelColor(pixelSel, 0x00000000);
            }
        }
        flowers.show();
        delay(random(55, 140));
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel += 1;
                delay(200);
            }
        }
    }
    

// 
// - Unicorn Magic -
//     
    else if(modeSel == 3)
    {
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            flowers.setPixelColor(pixelSel, 127, 0, blueValue);
        }
        flowers.show();
        delay(delayTime);
        blueValue = blueValue + colourIncrement;
        if(blueValue > 255){
            blueValue = 255;
            colourIncrement = -1;
        }
        if(blueValue < 32){
            blueValue = 32;
            colourIncrement = 1;
        }
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel += 1;
                delay(200);
            }
        }
    }
// 
// - Under the Sea -
//     
    else if(modeSel == 4)
    {
        for(int pixelSel = 0; pixelSel < flowerCount; pixelSel++){
            flowers.setPixelColor(pixelSel, 0, greenValue, blueValue);
        }
        flowers.show();
        delay(delayTime);
        greenValue = greenValue + colourIncrement;
        blueValue = blueValue - colourIncrement;
        if((greenValue > 255) || (blueValue < 0)){
            greenValue = 255;
            blueValue = 0;
            colourIncrement = -1;
        }
        if((greenValue < 0) || (blueValue > 255)){
            greenValue = 0;
            blueValue = 255;
            colourIncrement = 1;
        }
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel += 1;
                delay(200);
            }
        }
    }
// 
// - Trans Pride -
//
    else if(modeSel == 5)
    {
        for(int pixelOffset = 0; pixelOffset < flowerCount; pixelOffset++){
            for(int pixelSel = 0; pixelSel < (flowerCount / 5); pixelSel++){
                if((pixelSel + pixelOffset) < flowerCount){
                    pixelDisp = (pixelSel + pixelOffset);
                }
                else{
                    pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
                }
                flowers.setPixelColor(pixelDisp, 31, 31, 255);
            }
            for(int pixelSel = (flowerCount / 5); pixelSel < (2 * (flowerCount / 5)); pixelSel++){
                if((pixelSel + pixelOffset) < flowerCount){
                    pixelDisp = (pixelSel + pixelOffset);
                }
                else{
                    pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
                }
                flowers.setPixelColor(pixelDisp, 191, 0, 100);
            }
            for(int pixelSel = (2 * (flowerCount / 5)); pixelSel < (3 * (flowerCount / 5)); pixelSel++){
                if((pixelSel + pixelOffset) < flowerCount){
                    pixelDisp = (pixelSel + pixelOffset);
                }
                else{
                    pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
                }
                flowers.setPixelColor(pixelDisp, 180, 165, 180);
            }
            for(int pixelSel = (3 * (flowerCount / 5)); pixelSel < (4 * (flowerCount / 5)); pixelSel++){
                if((pixelSel + pixelOffset) < flowerCount){
                    pixelDisp = (pixelSel + pixelOffset);
                }
                else{
                    pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
                }
                flowers.setPixelColor(pixelDisp, 191, 0, 100);
            }
            for(int pixelSel = (4 * (flowerCount / 5)); pixelSel < flowerCount; pixelSel++){
                if((pixelSel + pixelOffset) < flowerCount){
                    pixelDisp = (pixelSel + pixelOffset);
                }
                else{
                    pixelDisp = ((pixelSel + pixelOffset) - flowerCount);
                }
                flowers.setPixelColor(pixelDisp, 31, 31, 255);
            }
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel = 0;
                delay(200);
            }
        }
        if(modeSel != 5){
            break;
        }
        flowers.show();
        delay(200);
        }
        if(capTouchDetect() == true){
            delay(50);
            if(capTouchDetect() == true){
                modeSel = 0;
                delay(200);
            }
        }
        delay(200);
    }
}