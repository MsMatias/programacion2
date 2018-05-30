/*
TP1-I-11:
Desarrollar un programa en el cual introduzca un número entero 
positivo e invierta los dígitos del número. Mostrar en pantalla el número invertido.
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	char n[10];
	int largo;
	cout<<"Introduce un numero entero positivo: ";cin>>n;
	largo = strlen(n);
	cout<<"El numero invertido es:";
	do{
		cout<<n[largo];
		largo--;
	}while(largo >= 0);
		
	getch();
	return 0;
}
