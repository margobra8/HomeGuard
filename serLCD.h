/* HomeGuard project

*********************************** NOTE ***********************************

USE ONLY FOR SERIAL LCD DISPLAY (VCC, Rx, GND)
FOR HITACHI CONTROLLER DISPLAY USE <LiquidCrystal.h>

****************************************************************************

MIT license
written by Marcos Gómez - http://margobra8.ml/
*/

#ifndef serLCD_h
#define serLCD_h

#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds,digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif
#include "SoftwareSerial.h"

// Commands
#define LCD_BACKLIGHT   0x80
#define LCD_CLEARDISPLAY  0x01
#define LCD_CURSORSHIFT   0x10
#define LCD_DISPLAYCONTROL  0x08
#define LCD_ENTRYMODESET  0x04
#define LCD_FUNCTIONSET   0x20
#define LCD_SETCGRAMADDR  0x40
#define LCD_SETDDRAMADDR  0x80
#define LCD_SETSPLASHSCREEN 0x0A
#define LCD_SPLASHTOGGLE  0x09
#define LCD_RETURNHOME    0x02

// Flags for display entry mode
#define LCD_ENTRYRIGHT    0x00
#define LCD_ENTRYLEFT   0x02

// Flags for display on/off control
#define LCD_BLINKON   0x01
#define LCD_CURSORON    0x02
#define LCD_DISPLAYON   0x04

// Flags for display size
#define LCD_2LINE   0x02
#define LCD_4LINE   0x04
#define LCD_16CHAR    0x10
#define LCD_20CHAR    0x14

//  Flags for setting display size
#define LCD_SET2LINE    0x06
#define LCD_SET4LINE    0x05
#define LCD_SET16CHAR   0x04
#define LCD_SET20CHAR   0x03

class serLCD : public SoftwareSerial {
public:
  serLCD (int pin);

  void clear();
  void clearLine(int);
  void home();
  void setBrightness(int);

  void setSplash();
  void setType(int);  // new in 1.6
  void scrollLeft();  // new in 1.6
  void scrollRight(); // new in 1.6
  void toggleSplash();

  void blink();
  void noBlink();
  void cursor();
  void noCursor();
  void display();
  void noDisplay();

  void setCursor(int, int);
  void selectLine(int);

  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void createChar(int, uint8_t[]);
  void printCustomChar(int);

private:
  void command(uint8_t);
  void specialCommand(uint8_t);

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;
  uint8_t _numlines;
  uint8_t _numchars;
  uint8_t _rowoffset;
};

#endif
