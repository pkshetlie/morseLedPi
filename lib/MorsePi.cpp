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

int MorseLedPi::returnKey(char c){
  for(int i = 0; i< 37; i++ ){
    if(c == _lettres[i]){
      return i;
    }
  }
  cout<< c <<" -> non reconnu"<<endl;
  return 36;
}

void MorseLedPi::setWord(char *mot){
  mot_ = mot;
}