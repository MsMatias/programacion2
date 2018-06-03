/*
TP1-I-09
Obtener un programa que lea un número natural y diga si es o no es triangular.
A saber: un número N es triangular si, y solamente si, es la suma de los primeros M
números naturales, para algún valor de M.
Ejemplo: 6 es triangular pues 6 = 1 + 2 + 3.
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main(){

	int numero, triangular, i=0;
	
	cout<<"\nIngrese el numero que desea comprobar si es Triangular o no: "; cin>>numero;
	
	do{
		i++;
		triangular = (i*(i+1)/2);
	}while(numero > triangular);
	
	if(numero == triangular){
		cout<<"\nEl numero: "<<numero<<" ingresado es triangular.";	
	}
	else{
		cout<<"\nEl numero: "<<numero<<" ingresado no es triangular";
	}
	getch();
	return 0;
}
