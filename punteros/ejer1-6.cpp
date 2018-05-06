#include <iostream>
#include <iomanip>
#include <string.h>

/* Realice un programa que permita ingresar una cadena de caracteres de máximo 50
elementos, la envie como parametro a una función que utilizando punteros y retorne
el número de vocales minúsculas que contiene la cadena. */

using namespace std;

int vocales(char *p){
	int n = strlen(p);
	int c = 0;
		
	for(int i = 0; i < n; i++){
		if(*(p+i) == 'a' || *(p+i) == 'e' || *(p+i) == 'i' || *(p+i) == 'o' || *(p+i) == 'u'){
			c++;
		}
	}	
	
	return c;	
}

int main() {
	
	char cadena[50];
	char cadena2[50];
	
	cout<<"Ingrese la cadena de caracteres: ";
	gets(cadena);
	
	cout<<vocales(cadena)<<endl;
				
	system("PAUSE()");
}
