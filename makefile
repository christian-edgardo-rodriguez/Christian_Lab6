main.exe:	juegos.o usuarios.o main.o
	g++ juegos.o usuarios.o main.o -o main.exe

main.o:	main.cpp usuarios.h juegos.h
	g++ -c main.cpp

juegos.o:	juegos.cpp juegos.h
	g++ -c juegos.cpp
	
usuarios.o:	usuarios.cpp usuarios.h
	g++ -c usuarios.cpp