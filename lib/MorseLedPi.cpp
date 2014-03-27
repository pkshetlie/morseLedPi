
#include "MorseLedPi.h"

MorseLedPi::MorseLedPi(char *str, int pin){

  pin_ = pin;
  mot_ = str;
  wiringPiSetup () ;
  pinMode (pin_, OUTPUT) ;

}

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