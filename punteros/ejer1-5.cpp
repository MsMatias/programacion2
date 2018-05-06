#include <iostream>
#include <iomanip>
#include <string.h>

/* Obtener una función copia que utilize punteros para copiar una cadena en otra. */

using namespace std;

char copiar(char *p, char *c){
	int n = strlen(p);
		
	for(int i = 0; i < n; i++){
		*(c+i) = *(p+i);
	}		
}

int main() {
	
	char cadena[50];
	char cadena2[50];
	
	cout<<"Ingrese la cadena de caracteres: ";
	gets(cadena);
	
	copiar(cadena, cadena2);
	
	cout<<cadena<<endl;
	cout<<cadena2<<endl;
				
	system("PAUSE()");
}
