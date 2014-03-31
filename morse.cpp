#include <iostream>
#include <cstdlib>
#include "lib/MorsePi.h"

using namespace std;




int main (int argc,char *argv[])
{

  char *mot = argv[2];
  int pin = atoi(argv[1]);

  cout<<"pin : "<<pin<<endl;
  cout<<"mot : "<<mot<<endl;
  MorseLedPi *m = new MorseLedPi(mot,pin);
  m->startLed();

  return 0 ;
}


