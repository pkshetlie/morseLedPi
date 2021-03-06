//------------------------------------------------------------------------------
//
// Copyright 2014 - Pierrick Pobelle
//
//------------------------------------------------------------------------------
//  This file is part of MorseLedPi.
//
//  MorseLedPi is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  MorseLedPi is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  You should have received a copy of the GNU General Public License
//  along with MorseLedPi.  If not, see <http://www.gnu.org/licenses/>.
//
//------------------------------------------------------------------------------

/**
  * A little programm to test your RaspBerry Pi
  *
  */
#include "MorsePi.h"

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


/**
 * MorseLedPi constructor
 * @param char * str a char* to transform in morseCode
 * @param int pin pin ID to use cf :
 */
MorseLedPi::MorseLedPi(char *str, int pin){
  pin_ = pin;
  mot_ = str;
  wiringPiSetup () ;
  pinMode (pin_, OUTPUT) ;
}

/**
 * [MorseLedPi::startLed description]
 */
void MorseLedPi::startLed(){
  int i=0;
  while(mot_[i]){
    int j=0;
    int *lumiere;
    int key = returnKey(mot_[i]);
    lumiere =  _lumieres[key];
    while(lumiere[j]){
      digitalWrite (pin_, HIGH) ; delay (lumiere[j]) ;
      digitalWrite (pin_,  LOW) ; delay (_court) ;
      j++;
    }
    i++;
    delay(100);
  }
}
/**
 * return the letter key for associate to morse array
 * @param  c the letter
 * @return  index of the char
 */
int MorseLedPi::returnKey(char c){
  for(int i = 0; i< 37; i++ ){
    if(c == _lettres[i]){
      return i;
    }
  }
  cout<< c <<" -> non reconnu"<<endl;
  return 36;
}
/**
 * Allow to change the word to send
 * @param mot new word
 */
void MorseLedPi::setWord(char *mot){
  mot_ = mot;
}