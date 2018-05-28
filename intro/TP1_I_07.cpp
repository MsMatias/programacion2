/*
TP1-I-07:
Obtener un programa que calcule el factorial de un número n
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numero;
	unsigned long long factorial=1;
	cout<<"\nIngrese un numero: ";cin>>numero;
	for(int i = 1; i <= numero; i++){
		factorial = factorial * i;
	}
	cout<<"\nEl factorial de: "<<numero<<"! = "<<factorial<<endl;	
	getch();
	return 0;
}
