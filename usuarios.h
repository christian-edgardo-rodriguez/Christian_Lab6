#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Usuarios{
	string user;
	string password;
	vector<int>juegos;
 public:
 	Usuarios(string user, string password);
 	bool agregarJuego(int id);
 	bool eliminarJuego(int id);
 	void setPassword(string password);
 	string getUser();
 	string getPassword();
 	bool passwordValida(string user, string password);
 	string toString()const;
};