#include <iostream>
#include <iomanip>
#include <string.h>

/* Se pide crear un programa que pida una serie de n�meros al usuario y halle el
m�ximo, el m�nimo y la media aritm�tica de ellos. Para ello se debe crear una
variable puntero tipo float, pedir al usuario que introduzca el n�mero de datos, y
sucesivamente los datos a cargar en el arreglo. Recordar que se debe reservar
memoria de forma din�mica. */

using namespace std;

int main() {
	
	float *numeros;
	int n, maximo, minimo, media;
	
	maximo = 0;
	minimo = 0;
	media = 0;
		
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>n;
	
	numeros = new float[n];
	
	cout<<"ingrese los elementos: "<<endl;
	for(int i = 0; i < n; i++){
		cin>>numeros[i];
		if(*(numeros+i) > maximo || i == 0){
			maximo = *(numeros + i);
		}
		
		if(*(numeros+i) < minimo || i == 0){
			minimo = *(numeros + i);
		}
		
		media += *(numeros + i);
	}
	
	media /= n;
	
	cout<<"Maximo: "<<maximo<<endl;
	cout<<"Minimo: "<<minimo<<endl;
	cout<<"Media: "<<media<<endl;
			
	system("PAUSE()");
}
