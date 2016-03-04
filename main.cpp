#include <iostream>
#include <vector>
#include <string>
#include "usuarios.h"
#include "juegos.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int menu();
int menuModificar();
bool revisarUser(string usuario, vector<Usuarios> users);
bool login(string usuario, string password, vector<Usuarios> users);
int loginGuardar(string password, vector<Usuarios> users);
bool revisarId(int id, vector<Juegos> games);

int main(int argc, char const *argv[]){
	int opcion=menu();
	string user, password, newPassword, nombre, creadores, genero;
	int id, year;
	vector<Usuarios> users;
	vector<Juegos> games;
	do{
		if (opcion==1){
			cout<<"Ingrese el nombre del usuario: ";
			cin>>user;
			if (revisarUser(user, users)==true){
				cout<<"Ingrese el password del usuario: ";
				cin>>password;
				Usuarios newUser(user,password);
				users.push_back(newUser);
				cout<<"Usuario creado. "<<endl;
			}
			cout<<endl;
			opcion=menu();
		}else if (opcion==2){
			cout<<"Ingrese el nombre del usuario: ";
			cin>>user;
			cout<<"Ingrese el password del usuario: ";
			cin>>password;
			if (login(user,password,users)==true){
				int posicion=loginGuardar(password,users);
				int opcionMod=menuModificar();
				if (opcionMod==1){
					cout<<"Ingrese el id del juego: ";
					cin>>id;
					for (int i = 0; i < games.size(); ++i){
						if (games[i].getId()==id){
							users[posicion].agregarJuego(id);
							cout<<"El juego ha sido agregado al usuario"<<endl;
						}
					}
				}else if (opcionMod==2){
					cout<<"Ingrese el id del juego: ";
					cin>>id;
					for (int i = 0; i < games.size(); ++i){
						if (games[i].getId()==id){
							users[posicion].eliminarJuego(id);
							cout<<"El juego ha sido eliminado al usuario"<<endl;
						}
					}
				}else if (opcionMod==3){
					cout<<"Ingrese la nueva contraseña: ";
					cin>>newPassword;
					users[posicion].setPassword(newPassword);
					cout<<"Contraseña cambiada."<<endl;
				}
			}else
				cout<<"Usuario incorrecto."<<endl;
			cout<<endl;
			opcion=menu();
		}else if (opcion==3){
			cout<<"Ingrese el nombre del usuario: ";
			cin>>user;
			for (int i = 0; i < users.size(); ++i){
				if (users[i].getUser()==user){
					users.erase(users.begin()+i);
					cout<<"Usuario eliminado."<<endl;
				}
			}
			cout<<"El usuario no existe."<<endl;
			cout<<endl;
			opcion=menu();
		}else if (opcion==4){
			cout<<"Ingrese el id del juego: ";
			cin>>id;
			if (revisarId(id, games)==true){
				cout<<"Ingrese el nombre del juego: ";
				cin>>nombre;
				cout<<"Ingrese el year del juego: ";
				cin>>year;
				cout<<"Ingrese el creador del juego: ";
				cin>>creadores;
				cout<<"Ingrese el genero del juego: ";
				cin>>genero;
				Juegos newGame(id,nombre,year,creadores,genero);
				games.push_back(newGame);
				cout<<"Juego creado."<<endl;
			}
			cout<<endl;
			opcion=menu();
		}else if (opcion==5){
			cout<<"Ingrese el id del juego: ";
			cin>>id;
			for (int i = 0; i < games.size(); ++i){
				if (games[i].getId()==id){
					games.erase(games.begin()+i);
					cout<<"Juego eliminado."<<endl;
				}
			}
			cout<<endl;
			opcion=menu();
		}else if (opcion==6){
			if (users.size()>0){
				for (int i = 0; i < users.size(); ++i){
					cout<<users[i].toString()<<endl;
				}
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de usuarios esta vacia"<<endl;
				cout<<endl;
				opcion=menu();
			}
		}else if (opcion==7){
			if (games.size()>0){
				for (int i = 0; i < games.size(); ++i){
					cout<<games[i].toString()<<endl;
				}
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de juegos esta vacia"<<endl;
				cout<<endl;
				opcion=menu();
			}
		}
	}while(opcion!=8);
	return 0;
}
int menu(){
	int opc;
	cout<<"1. Agregar Usuario"<<endl;
	cout<<"2. Modificar Usuario"<<endl;
	cout<<"3. Eliminar Usuario"<<endl;
	cout<<"4. Agregar Juego"<<endl;
	cout<<"5. Eliminar Juego"<<endl;
	cout<<"6. Listar Usuarios"<<endl;
	cout<<"7. Listar Juegos"<<endl;
	cout<<"8. Salir"<<endl;
	cout<<"Escoja su opcion: ";
	cin>>opc;
	if (opc<1&&opc>8){
		return 0;
	}else{
		return opc;
	}
}
int menuModificar(){
	int opc;
	cout<<"1. Agregar Juego"<<endl;
	cout<<"2. Eliminar Juego"<<endl;
	cout<<"3. Cambiar Password"<<endl;
	cout<<"Escoja su opcion: ";
	cin>>opc;
	if (opc<1&&opc>3){
		return 0;
	}else{
		return opc;
	}
}
bool revisarUser(string usuario, vector<Usuarios> users){
	for (int i = 0; i < users.size(); ++i){
		if (users[i].getUser()==usuario){
			cout<<"El usuario ya esta tomado."<<endl;
			return false;
		}
	}
	return true;
}
bool login(string usuario, string password, vector<Usuarios> users){
	for (int i = 0; i < users.size(); ++i){
		if (users[i].getUser()==usuario&&users[i].getPassword()==password){
			return true;
		}
	}
	return false;
}
int loginGuardar(string password, vector<Usuarios> users){
	for (int i = 0; i < users.size(); ++i){
		if (users[i].getPassword()==password){
			return i;
		}
	}
	return -1;
}
bool revisarId(int id, vector<Juegos> games){
	for (int i = 0; i < games.size(); ++i){
		if (games[i].getId()==id){
			cout<<"El id ya esta tomado."<<endl;
			return false;
		}
	}
	return true;
}