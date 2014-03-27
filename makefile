
all All: morseTest

morseTest: morse.o MorseLedPi.o
	g++ -Wall -o morseTest morse.o MorseLedPi.o -I/usr/local/include -L/usr/local/lib -lwiringPi

morse.o: morse.cpp
	g++ -Wall -o morse.o -c morse.cpp

MorseLedPi.o: lib/MorseLedPi.cpp lib/MorseLedPi.h
	g++ -Wall -o MorseLedPi.o -c lib/MorseLedPi.cpp -I/usr/local/include -L/usr/local/lib -lwiringPi
