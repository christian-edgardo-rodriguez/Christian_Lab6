#pragma once
#include <string>

using std::string;

class Juegos{
	int id;
	string nombre;
	int year;
	string creadores;
	string genero;
 public: 
 	Juegos(int id, string nombre, int year, string creadores, string genero);
 	int getId();
 	string toString()const;
};