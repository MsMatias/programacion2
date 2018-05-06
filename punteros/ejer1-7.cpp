#include <iostream>
#include <iomanip>
#include <string.h>

/* Definir un vector de N compnentes enteras de modo que la gestion de menoria sea
dinamica utilizando new. Ingresar los datos en el vector. Mostrar el contenido del
vector en dos modos: usando notacion vectorial y luego usando aritmetica de
punteros. */

using namespace std;

int main() {
	
	int *numeros;
	int n;
		
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>n;
	
	numeros = new int[n];
	
	cout<<"ingrese los elementos: "<<endl;
	for(int i = 0; i < n; i++){
		cin>>numeros[i];
	}	
	
	for(int i = 0; i < n; i++){
		cout<<numeros[i]<<endl;
	}
	
	for(int i = 0; i < n; i++){
		cout<<*(numeros + i)<<endl;
	}
			
	system("PAUSE()");
}
