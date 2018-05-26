/*
que tenga un constructor que la pida el nombre, 
- metodo jugar para que tire el dado y se mueva de casillas,
- metodo para que te devuelva el nombre, 
- metodo que te devuelva el numero de jugador, 
- metodo que te devuelva la posicion en el tablero
*/

#include<iostream>
#include<conio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

class jugador{
	private:
		char *nombre;
		
		
	public:
		jugador();
		void sNombre(const char* );
		int jugar();
		int sPosicion();
	//	char nombre(char nombreJugador);
	
		
};

jugador::jugador(){}

void jugador::sNombre(const char* _nombre){
	int n = strlen(_nombre);
	nombre = new char[n];
	for(int i;i<n;i++){
		*(nombre+i) = *(_nombre+i);
	}
}

int jugador::jugar(){
	int valor = rand() % 6 + 1;
	return valor;
}


int jugador::sPosicion(){
		
}




int main(){

	getch();
	return 0;
}
