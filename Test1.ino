#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 2

byte Pixel = 2;
byte Power = 3;
// Pins for the NEOPixel and the DIO itself
int buttonState = 0;
// Setup Control Button

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  pinMode(Pixel, OUTPUT); 
  pinMode(Power, INPUT);
  // Setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW)
  {
    red();
  }
  else 
  {
    blue();
  }
  
}

void red ()
{
  for (int i =0; i < 12; i++) {
    strip.setPixelColor(i,strip.Color(255,0,0));
  }
  strip.show();
}

void blue ()
{
  for (int i =0; i < 12; i++) {
    strip.setPixelColor(i,strip.Color(0,0,255));
  }
  strip.show();
}


