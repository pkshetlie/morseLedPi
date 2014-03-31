
all All: morseTest

morseTest: morse.o MorsePi.o
	g++ -Wall -o morseTest morse.o MorsePi.o -I/usr/local/include -L/usr/local/lib -lwiringPi

morse.o: morse.cpp
	g++ -Wall -o morse.o -c morse.cpp

MorsePi.o: lib/MorsePi.cpp lib/MorsePi.h
	g++ -Wall -o MorsePi.o -c lib/MorsePi.cpp -I/usr/local/include -L/usr/local/lib -lwiringPi
