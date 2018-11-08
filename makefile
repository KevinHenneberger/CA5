all:	Main

Main:	Main.o
	g++ Main.o -o Main.exe

Main.o:	Main.cpp
	g++ -c Main.cpp

clean:
	rm -f *.o Main.exe
