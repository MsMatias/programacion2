#include <iostream>
#include <iomanip>
#include <string.h>

/* Realizar un programa que ingrese una cadena de caracteres de m�ximo 50
elementos y la envie como par�metro a una funci�n que maneje punteros
de modo que la funci�n invierta la cadena. */

using namespace std;

void reversible(char *p){
	int n = strlen(p);
	char c;
		
	for(int i = 0; i < (n/2); i++){
		c = *(p+i);
		*(p+i) = *(p+n-i-1);
		*(p+n-i-1) = c;
	}
}

int main() {
	
	char cadena[50];
	
	cout<<"Ingrese la cadena de caracteres: ";
	gets(cadena);
	
	reversible(cadena);
	
	cout<<cadena<<endl;
				
	system("PAUSE()");
}
