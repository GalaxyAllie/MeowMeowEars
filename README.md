# Meow Meow Ears

This is a project to create a pair of programmable neko mimis that feature ten LEDs.

## WARNINGS - *max power draw* and *brightness* and *health*

Please be aware that the LEDs can *easily* exceed the max power draw of this circuit design. It is highly recommended not to exceed 150 mA. They're cat ears, you don't need to blind everyone - keep the NeoPixel library brightness down to around 50 or so, tops :)

Also be aware some people are *photo sensitive* - these are meant for rave environments. For environments where people may not expect flashing lights (and where they do...) *please be considerate*.

## Basic Features

- ATSAMD21 microcontroller (ARM Cortext M0)
- Ten WS2812b RGB LEDs
- Power and status LEDs
- One capacitive touch zone - though this isn't used in the example code
- Native USB (you can even use it as a keyboard, hopefully)
- Designed to be put in cat ear headbands. Meow!
- Probably a fair number of bugs and bad design decisions!

## Copyright/Liability

I licence this work under [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/#)

Also, I'm obviously not responsible for injuries or anything like that - this is definitely not a safety-tested, commercial project. Build at your own risk. It probably won't even work :)

## Build Notes

You really shouldn't draw over 50 mA or so of power, you're probably blinding people if you do :) - see warnings above. Thus, you should be fine to input all the way up to the linear regulator max voltage rating of 6V - but you're wasting energy over 3.3V. Thus, 3x NiMH batteries or a 3.7V Lion battery would be good power choices - be smart and sensible though. Batteries can be dangerous.

Boards can be ordered from [Osh Park](https://oshpark.com/shared_projects/3kRYov0c) - that's not an affiliate link or anything, just a convenient source. And they're purple.

## Bill of Materials

| Component                               | Manufacturer                 | Qty |
|-----------------------------------------|------------------------------|-----|
| This board                              | Whoever you choose           | 1   |
| ATSAMD21E18A-AU-ND                      | Microchip Technology         | 1   |
| S2B-PH-SM4-TB(LF)(SN)                   | JST                          | 1   |
| 0.1uF 0603 Capacitor                    | Any                          | 10  |
| 1uF 0603 Capacitor                      | Any                          | 2   |
| 10uF 0603 Capacitor                     | Any                          | 2   |
| WS2812b LED                             | Worldsemi                    | 10  |
| UV/blacklight LED 0805 (or fave :) )    | Generic                      | 2   |
| AP2112K-3.3TRG1                         | Diodes Incorporated          | 1   |
| BAT54-TP                                | Micro Commercial Co          | 2   |
| USB3076-30-A                            | GCT                          | 1   |
| 510 Ohm 0805 Resistor (diff if UV sub)  | Any                          | 2   |
| 330 Ohm 0805 Resistor                   | Any                          | 1   |
| 3.5 x 6 mm push button switch           | Generic                      | 1   |

## Example Code

The example C++/Arduino code is designed to pretend the board is an Adafruit Trinket M0, and is for use with the Trinket M0 bootloader.

## Thanks

Thank you to the following people:

- Ladyada and [Adafruit](https://learn.adafruit.com/how-to-program-samd-bootloaders/trinket-m0-wiring) - for building excellent products and teaching people electronics. I used a lot of Trinket M0's in prototyping this. Seriously, people, go buy their products - they're fantastic (and the boards are way cuter than some others, especially look at the Metro M4 Express - it's just adorable).

- [OpenMoji](https://www.openmoji.org) - this is the source of the emoji used on the board silk.

- Q - for being an awesome friend who has helped with so much of the EDA side of working this all out. Thank you for answering late night messages with silly questions!

- JoJo Siwa - because the inspirational quote comes from one of your songs, and your concert on the [D.R.E.A.M. tour](https://www.jojodreamtour.com/) I went to in Cardiff was amazing. I'm not sure if it's your original quote tho, so I didn't quote it as you - I think I've heard it before? Either way, very inspiring performance! Keep things fun and positive and spread the positive energy, people!

## Version History

### v1

This was essentially a light strip on a cat ear shaped PCB.

### v2

This added an ATSAMD21 microcontroller.

### v3

This is the release version - it fixes the major bugs and makes them ready for general use.
