#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int _court = 50; //durée de base cf: http://fr.wikipedia.org/wiki/Morse_(alphabet)

char _lettres[37] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',' '};
int _long= 3 * _court;
int _espaceEntreLettre= 3 * _court;
int _espaceEntreMot= 7 * _court;
int _lumieres[37][6] = {{_court,_long},{_long,_court,_court,_court},{_long,_court,_long,_court},{_long,_court,_court},{_court},{_court,_court,_long,_court},{_long,_long,_court},{_court,_court,_court,_court},{_court,_court},
  {_court,_long,_long,_long},{_long,_court,_long},{_court,_long,_court,_court},{_long,_long},{_long,_court},{_long,_long,_long},{_court,_long,_long,_court},{_long,_long,_court,_long},{_court,_long,_court},
  {_court,_court,_court},{_long},{_court,_court,_long},{_court,_court,_court,_long},{_court,_long,_long},{_long,_court,_court,_long},{_long,_court,_long,_long},{_long,_long,_court,_court},{_court,_long,_long,_long,_long},
  {_court,_court,_long,_long,_long},{_court,_court,_court,_long,_long},{_court,_court,_court,_court,_long},{_court,_court,_court,_court,_court},{_long,_court,_court,_court,_court},{_long,_long,_court,_court,_court},{_long,_long,_long,_court,_court},{_long,_long,_long,_court},
  {_long,_long,_long,_long,_long},{0}};


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