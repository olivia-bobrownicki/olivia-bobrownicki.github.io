//this code will show you the battery charge left on the screen
//and dim the screen (to conserve power)
//and go to sleep when you press the left builtin button
//to wake it up again, just hit the reset button on the side


//download as zip and add to libraries folder in Arduino folder https://github.com/pangodream/18650CL
#include <Pangodream_18650_CL.h> 
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>


#define ADC_PIN 34
#define CONV_FACTOR 1.8
#define READS 20
Pangodream_18650_CL BL(ADC_PIN, CONV_FACTOR, READS);

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

#define BUTTON_PIN_BITMASK 0x800000000 // 2^35 in hex


void IRAM_ATTR goToSleep() {
  esp_deep_sleep_start();
}



void setup() {

  tft.init();
  tft.setRotation(1);
  attachInterrupt(0, goToSleep, CHANGE);

  //set screen Back Light brightness
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 5000, 8); // 0-15, 5000, 8
  ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
  ledcWrite(0, 125); // 0-15, 0-255 (with 8 bit resolution); 0=totally dark;255=totally shiny

}




void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.setTextSize(2);
  tft.drawString("Battery Level: ", 0, 50);
  tft.setTextSize(1);
  tft.drawFloat(BL.getBatteryChargeLevel(), 3, 0, 80, 4);

  delay(4000);

  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  delay(1000);

 // PUT CODE HERE FOR GIF


  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  delay(1000);

  // randomly generate an int to determine color of printed text
  int x, y;
  int result;

  char snum[10];
  result = random(0,10) % 2;
  

  if(result==0)
  {
    tft.setTextColor(TFT_WHITE);
  }
  if(result==1)
  {
    tft.setTextColor(TFT_RED);
  }

  tft.drawString("Dear lost sharer", 0, 0, 1);
  delay(1000);

  tft.drawString("of silences,", 0, 40, 1);
  delay(2000);


  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.drawString("I would send", 10, 0, 1);
  tft.drawString("a letter", 10, 20, 1);
  delay(1000);
  tft.drawString("the way the tree", 10, 60, 1);
  tft.drawString("sends messages,", 30, 80, 1);
  delay(2000);

  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(4);
  delay(500);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("in leaves,", 10, 40, 1);
  delay(2000);

  tft.fillScreen(TFT_GREEN);
  delay(500);
  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("or the sky in", 0, 0, 1);
  tft.drawString("exclamations",0,20,1);
  delay(1000);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("of pure cloud.", 50, 70, 1);
  
  delay(3000);

  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.setTextColor(TFT_BLACK);
  tft.drawString("Therefore I write", 0, 0, 1);
  tft.setTextColor(TFT_BLUE);

  tft.drawString("in this blue", 0, 25, 1);
  tft.drawString("ink,", 0, 50, 1);
  delay(1500);
  tft.drawString("color", 60, 50, 1);
  tft.drawString("of secret veins", 0, 75, 1);
  tft.drawString("and arteries.", 0, 100, 1);
  delay(4500);

  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.setTextColor(TFT_WHITE);
  tft.drawString("It is morning here.", 0, 10, 1);
  delay(2000);
  tft.drawString("Already the postman", 0, 50, 1);
  tft.drawString("walks", 0, 70, 1);
  delay(2000);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("the innocent", 0, 0, 1);
  tft.drawString("streets,", 0, 25, 1);
  delay(2000);
  tft.drawString("dangerous as Aeolus", 0, 50, 1);
  tft.drawString("with his bag", 0, 75, 1);
  tft.drawString("of winds,", 20, 95, 1);
  delay(3000);

  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.drawString("or Hermes, the", 0, 0, 1);
  tft.drawString("messenger,", 40, 20, 1);
  delay(2000);
  tft.drawString("god of sleep", 0, 45, 1);
  tft.drawString("and dreams", 0, 65, 1);
  delay(2000);
  tft.drawString("who traces my image", 0, 95, 1);
  delay(2000);
  tft.drawString("upon this stamp.", 40, 115, 1);
  delay(4000);

  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.drawString("In public buildings", 0, 40, 1);
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.drawString("letters are weighed", 0, 40, 1);
  delay(1000);
  tft.drawString("and sorted", 0, 65, 1);
  delay(1000);
  tft.drawString("like", 70, 115, 1);
  delay(1000);

  tft.fillScreen(TFT_RED);
  delay(500);
  tft.setTextSize(6);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED);
  tft.drawString("meat;", 30, 40, 1);
  delay(2000);

  tft.fillScreen(TFT_RED);
  delay(500);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  delay(500);

  tft.drawString("in railway stations", 0, 0, 1);
  delay(1000);
  tft.drawString("huge sacks of mail", 0, 25, 1);
  delay(1000);
  tft.drawString("are hidden like", 0, 50, 1);
  tft.drawString("robbers' booty", 0, 70, 1);
  delay(1500);
  tft.drawString("behind freight-car", 0, 95, 1);
  tft.drawString("doors.", 70, 115, 1);
  delay(3000);

  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("And in another city", 0, 40, 1);
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.setTextSize(3);
  tft.drawString("the", 50, 20, 1);
  tft.setTextSize(5);
  delay(500);
  tft.drawString("conjurer", 0, 70, 1);
  tft.setTextSize(2);
  delay(1500);
  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("will hold a fan of", 0, 0, 1);
  tft.drawString("letters", 40, 20, 1);
  delay(1000);
  tft.drawString("before your", 0, 60, 1);
  delay(1000);
  tft.drawString("outstretched hand-", 20, 80, 1);
  delay(2000);


  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("\"Pick any card", 0, 0, 1);
  tft.drawString(". . . \"", 30, 30, 1);
  delay(1500);
  tft.fillScreen(TFT_BLACK);
  tft.drawString("You must", 0, 0, 1);
  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.setTextSize(6);
  tft.drawString("tear", 40, 40, 1);
  tft.setTextSize(2);
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  tft.drawString("the envelope", 0, 0, 1);
  delay(400);
  tft.drawString("as", 20, 20, 1);
  delay(400);
  tft.drawString("you", 40, 40, 1);
  delay(400);
  tft.drawString("would", 60, 60, 1);
  delay(400);
  tft.drawString("tear", 80, 80, 1);
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  delay(200);
  tft.setTextSize(6);
  tft.drawString("bread.", 40, 70, 1);
  tft.setTextSize(2);
  delay(2000);


  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("Only then", 0, 0, 1);
  delay(500);
  tft.drawString("dark rivers", 20, 20, 1);
  delay(1000);
  tft.drawString("of ink", 0, 40, 1);
  delay(500);
  tft.drawString("will thaw", 20, 60, 1);
  delay(500);
  tft.drawString("and", 70, 90, 1);
  delay(1000);

  tft.fillScreen(TFT_BLACK);
  delay(200);
  tft.drawString("f", 50, 30, 1);
  delay(200);
  tft.drawString("l", 60, 50, 1);
  delay(200);
  tft.drawString("o", 70, 70, 1);
  delay(200);
  tft.drawString("w", 80, 90, 1);
  delay(500);

  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("under all the", 0, 0, 1);
  delay(500);
  tft.drawString("bridges", 0, 20, 1);
  delay(500);
  tft.drawString("we have failed", 0, 60, 1);
  delay(700);
  tft.drawString("to build", 0, 90, 1);
  delay(2000);

  tft.fillScreen(TFT_BLACK);
  delay(500);
  tft.drawString("between", 0, 0, 1);
  tft.setTextSize(1.5);
  delay(1000);
  tft.drawString("us.", 100, 115, 1);
  delay(3000);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(2);
  delay(500);
  tft.drawString("  - Linda Pastan", 0, 60, 1);
  delay(4000);
  tft.fillScreen(TFT_BLACK);
  delay(1000);

  delay(1000);
}