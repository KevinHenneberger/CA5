all:	Main

Main:	City.o Flight.o Map.o Main.o
	g++ City.o Flight.o Map.o Main.o -o Main.exe

Main.o:	Main.cpp
	g++ -c Main.cpp

Map.o:	Map.cpp Map.h
	g++ -c Map.cpp

Flight.o:	Flight.cpp Flight.h
	g++ -c Flight.cpp

City.o:	City.cpp City.h
	g++ -c City.cpp

clean:
	rm -f *.o Main.exe
