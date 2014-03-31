#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class MorseLedPi{
  public:
    MorseLedPi(char* str, int pin);
    void startLed();
    int returnKey(char c);
    void setWord(char *word);
  protected:
    int pin_;
    char *mot_;

};