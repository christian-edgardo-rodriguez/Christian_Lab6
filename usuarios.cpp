#include "usuarios.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Usuarios::Usuarios(string user, string password):user(user), password(password){

}
string Usuarios::toString()const{
	stringstream ss;
	ss<<"Usuario: "<<user<<"\n"
		<<"Password"<<password<<"\n";
	return ss.str();
}