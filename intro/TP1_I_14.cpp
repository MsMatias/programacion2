/*
TP1-I-14:
Escribir un programa que lea un número entero y una posición dentro de este
número, y muestre la cifra que corresponde a la posición (suponiendo que en la
posición 1 se encuentran las unidades).
*/
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numUSO, digUSO;
	bool esta = false;
	int reves = 0;
	int numDig = 0;
	cout<<"Introduce un numero: ";cin>>numUSO;
	cout<<"Introduce una posicion: ";cin>>digUSO;
	int numBasura = numUSO;
	//Determino la cantidad digitos que tiene el numero ingresado.
	while(numBasura > 0){
		reves = ((reves*10)+(numBasura%10));
		numBasura /= 10;
		numDig++;
	}
	//Calculo posicion:
	int dig, pos;
	for(pos = 1; pos <= numDig ; pos++){
		dig = numUSO%10;
		numUSO /=10;
		if(digUSO == pos){
			esta = true;
			cout<<"\nEn la posicion "<<digUSO<<" esta el numero "<<dig<<" contando de izquierda a derecha.";
		}
	}
	if(esta == false){
		cout<<"\nEn la posicion "<<digUSO<<" no existe ningun numero digitado inicialmente.";
	}
	getch();
	return 0;
}
