/*
TP1-I-15
Escribir un programa que sume las cifras de un número entero positivo.
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numero, resto, sumador = 0;
	do{
		cout<<"Ingresar un numero: ";cin>>numero;
	}while(numero < 0);
	int N = numero;
	do{
	resto = numero%10;
	numero /= 10;
	sumador += resto;		
	}while(numero != 0);
	cout<<"\nLa suma de las cifras que componen el n "<<N<<" es igual a: "<<sumador;	
	getch();
	return 0;
}
