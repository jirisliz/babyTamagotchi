#ifndef LCD5110_H
#define LCD5110_H

#include <Arduino.h>

// Define digital pins
#define PIN_RESET 13
#define PIN_SCE   14
#define PIN_DC    15
#define PIN_SDIN  16
#define PIN_SCLK  17

#define LCD_C     LOW
#define LCD_D     HIGH

// Bounds of the display
#define LCD_X     84
#define LCD_Y     48

class CLcd5110 {
  public:
    CLcd5110();
    static void LcdClear();
    static void LcdInitialise();
    static void gotoXY(int x, int y);
    static void LcdWrite(char dc, char data);
    static void LcdString(char*);
    static void LcdCharacter(char character);
    static void LcdBitmap(char my_array[]);

};


class CBaby {
  private:
  // In range: 0-100
  int hunger, poop, happy;

  unsigned char countCyc;

  void drawFacePart(char my_array[]);
  void drawPoop();
  void incCount(unsigned char aMax);

  void drawBars(int aVal, int aPos);
  
  public:
    CBaby();

    // Call from timer
    void updateBaby();

    void babyFeed();
    void babyPlay();
    void babyClean();
};

#endif
