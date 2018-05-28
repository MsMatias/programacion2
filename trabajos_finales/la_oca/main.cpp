#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#include <conio.h>
#include <string.h>

#define MIN_JUGADORES 2
#define MAX_JUGADORES 5
#define LARGO_NOMBRE 20

using namespace std;

class jugador{
	private:
		char *nombre;
		int posicion;
		int jugadas;
		
	public:
		jugador(){ posicion = 0; jugadas = 0; };
		void sNombre(const char*);
		char* gNombre();
		int posTablero();
		int jugar();
		void sPosicion(int);
		void operator++(int);
		int gJugadas();
		
};

void jugador::sNombre(const char* _nombre){
	int n = strlen(_nombre);
	nombre = new char[n];
	for(int i = 0;i<LARGO_NOMBRE;i++){
		if(i < n)
			*(nombre+i) = *(_nombre+i);
		else
			*(nombre+i) = '\0';
	}
}

char* jugador::gNombre(){
	return nombre;
}

int jugador::posTablero(){
	return posicion;
}

int jugador::jugar(){
	
	/* Inicializamos random */
	srand(time(NULL));
	
	int random;
	
	random = rand() % 6 + 1;
	
	return random;
	
}

void jugador::sPosicion(int p){
	posicion = p;
}

void jugador::operator++(int){
	jugadas++;
}

int jugador::gJugadas(){
	return jugadas;
}

//CLASE CELDA
class celdas{
	private:
		int accion;
		
	public:
		celdas(){ accion = 0; };
		void sAccion(int);
		int gAccion();
};

void celdas::sAccion(int a){
	accion = a;
}

int celdas::gAccion(){
 return accion;
}

//CLASE OCA
class oca {
	
	private:
		celdas* celdasOca; //Puntero de tipo int para guardar las celdas del tablero con sus respectivas acciones
		int nCeldas; //Cantindad de celdas
		int nJugadores; //Cantidad de jugadores
		jugador* jugadores; //Puntero de tipo jugador para guardar los jugadores del juego
		
	public:	
		oca(){};	
		oca(int);
		int iniciarJugadores(int);
		int iniciar();
		jugador gJugador(int);
};

oca::oca(int c){
	
	if(c > 0){
	
	/* Inicializamos random */
	srand(time(NULL));
	
	int random;

	/* Guardamos la cantidad de celdas del tablero */
	nCeldas = c;	
	
	/* Asignamos espacio de memoria a celdas */
	celdasOca = new celdas[nCeldas];	
	
	/* Asignamos a cada celda una accion */
	for(int i = 1; i < nCeldas-1; i++){
		random = rand() % 8 - 3;
		celdasOca[i].sAccion(random);
	}
	
	cout<<"Se creo el tablero con "<<nCeldas<<" celdas"<<endl;	
	
	}else{
		cout<<"Debe ser un numero mayor a 0";
	}
		
}

int oca::iniciarJugadores(int j){
	if(j > 1){
		
		char* nombre;
		char caracter;
		nJugadores = j;		
		jugadores = new jugador[nJugadores];
		int c;
		
		nombre = (char *) malloc(LARGO_NOMBRE);
				
		/* Guardamos los nombres de cada jugador */
		for(int i = 0; i < nJugadores; i++){
			cout<<"Ingrese el nombre del jugador N"<<(i+1)<<": "<<endl;
			cin>>nombre;
            jugadores[i].sNombre(nombre);
		}
		
		cout<<" Todos los jugadores definidos!"<<endl;
		
	}else{
		cout<<"Debe ser un numero mayor a 1";
	}
}

int oca::iniciar(){	
	
	//Verificamos que existan mas de 3 celdas en el tablero para iniciar
	if(nCeldas < 3){
		cout<<"Debe definir las celdas antes de imprimir"<<endl;
		return 0;
	}
	
	//Verificamos que existan al menos dos jugadores
	if(nJugadores < MIN_JUGADORES){
		cout<<"Debe definir al menos "<<MIN_JUGADORES<<" jugadores"<<endl;
		return 0;
	}
	
	int turno = 0;
	int dado = 0;
	int posActual = 0;
	int accion = 0;
	char k;
	
	do{		
	
	system("CLS");
	system("color 47");
	
	cout<<"============================"<<endl;
	cout<<"==== Tabla de jugadores ===="<<endl;
	cout<<"============================"<<endl<<endl;
	
	/* Imprimimos a los jugadores */
	for(int i = 0; i < nJugadores; i++){
		cout<<(i+1)<<")- "<<jugadores[i].gNombre()<<" cantidad de tiros: "<<jugadores[i].gJugadas()<<endl;
	}
	
	cout<<endl;
	
	cout<<"=========================="<<endl;
	cout<<"==== Tablero de juego ===="<<endl;
	cout<<"=========================="<<endl<<endl;
	
	/* Imprimimos el tablero con los jugadores en sus respectivas posiciones */
	for(int i = 0; i < nCeldas; i++){
		for(int j = 0; j < nJugadores; j++){
			if(jugadores[j].posTablero() == i){
				cout<<(j+1)<<" ";
			}
		}
		cout<<"| ";
	}
	
	/* Verificamos si existe un jugador en la ultima celda del tablero */
	for(int j = 0; j < nJugadores; j++){
		if(jugadores[j].posTablero() == (nCeldas-1)){
			return j;
		}
	}
	
	cout<<endl;
	
	cout<<"Turno de "<<jugadores[turno].gNombre()<<" Presiona enter para tirar el dado"<<endl;
	
	posActual = jugadores[turno].posTablero();
	
	if((k = getch()) == 13){
		
		//Incrementa una jugada
		jugadores[turno]++;
		
		dado = jugadores[turno].jugar();
		
		cout<<"El jugador se mueve  "<<dado<<" posiciones"<<endl;
		posActual += dado;
		
		if(posActual < 0){
			posActual = 0;
		}else if(posActual > (nCeldas-1)){
			posActual = (nCeldas-1);
		}
		
		/* Verificamos que accion existe en la celda que se desplazo el jugador */
		accion = celdasOca[posActual].gAccion();
		if(accion > 0)
			cout<<"En esta celda dice: Avanza "<<accion<<" posiciones"<<endl;
		else if(accion < 0)
			cout<<"En esta celda dice: Retrocede "<<(accion*(-1))<<" posiciones"<<endl;
		else
			cout<<"En esta celda dice: Manten la misma posicion"<<endl;

		posActual += accion;
		
		if(posActual < 0){
			posActual = 0;
		}else if(posActual > (nCeldas-1)){
			posActual = (nCeldas-1);
		}
			
		jugadores[turno].sPosicion(posActual);
			
		if(turno < (nJugadores-1))
			turno++;
		else
			turno = 0;
			
		getch();	
	}
	
	
	}while(1);
	
	return 0;
}

jugador oca::gJugador(int i){
	return jugadores[i];
}

int main(int argc, char** argv) {
	
	int c,j;
	
	system("color 17");
	
	cout<<"========================================"<<endl;
	cout<<"==== Bienvenidos al juego de la OCA ===="<<endl;
	cout<<"========================================"<<endl<<endl;	
	
	do{	
		cout <<'\r';
		cout<<"Ingrese la cantidad de celdas que va a tener el tablero: ";
		cin>>c;
	}while(c < 2 || c > 40);
	
	cout << "%" << '\r';
				
	oca juego(c);
	
	do{	
		cout <<'\r';
		cout<<"Ingrese la cantidad de jugadores (min 2 - max 5): ";
		cin>>j;
	}while(j < MIN_JUGADORES || j > MAX_JUGADORES);
	
	cout << "%" << '\r';
	
	juego.iniciarJugadores(j);
	
	int nJugador = juego.iniciar();	
	jugador ganador = juego.gJugador(nJugador);
	
	system("CLS");	
	system("color 17");	
	
	cout<<"========================="<<endl;
	cout<<"==== Juego de la OCA ===="<<endl;
	cout<<"========================="<<endl<<endl;	
	
	cout<<"El ganador es "<<ganador.gNombre()<<" Felicitaciones!!!!"<<endl;
	
	system("PAUSE");
	return 0;
}

