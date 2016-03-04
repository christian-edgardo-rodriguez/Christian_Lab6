#include "juegos.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Juegos::Juegos(int id, string nombre, int year, string creadores, string genero):
id(id), nombre(nombre),year(year), creadores(creadores), genero(genero){

}
string Juegos::toString()const{
	stringstream ss;
	ss<<"Id: "<<id<<"\n"
		<<"Nombre"<<nombre<<"\n"
		<<"Year"<<year<<"\n"
		<<"Creadores"<<creadores<<"\n"
		<<"Genero"<<genero<<"\n";
	return ss.str();
}