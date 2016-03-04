#include "usuarios.h"
#include <string>
#include <sstream>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

Usuarios::Usuarios(string user, string password):user(user), password(password){
	vector<int>juegos();
}
bool Usuarios::agregarJuego(int id){
	for (int i = 0; i < juegos.size(); ++i){
		if (juegos[i]==id){
			throw "Este juego ya existe";
			return false;
		}
	}
	juegos.push_back(id);
	return true;
}
bool Usuarios::eliminarJuego(int id){
	for (int i = 0; i < juegos.size(); ++i){
		if (juegos[i]!=id){
			throw "Este juego no existe";
			return false;
		}else{
			juegos.erase(juegos.begin()+i);
		}
	}
	return true;
}
void Usuarios::setPassword(string password){
	this -> password= password;
}
string Usuarios::getUser(){
	return user;
}
string Usuarios::getPassword(){
	return password;
}
string Usuarios::toString()const{
	stringstream ss;
	ss<<"Usuario: "<<user<<"\n"
		<<"Password"<<password<<"\n";
	return ss.str();
}