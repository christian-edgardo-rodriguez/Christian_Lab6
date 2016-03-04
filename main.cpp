#include <iostream>
#include <vector>
#include "usuarios.h"
#include "juegos.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int menu();

int main(int argc, char const *argv[]){
	
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