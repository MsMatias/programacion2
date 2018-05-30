/*
TP1_I_10:
Obtener un programa que muestre la serie de Fibonacci 0, 1, 1, 2, 3, 5, 8, 13, 21,…
Los primeros términos son 0 y 1, los siguientes son la suma de los dos anteriores.
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main(){
	int n,x=0,y=1,z=1;
	
	do{
		cout<<"Digite la cantidad de digitos de la serie: ";
		cin>>n;
	}while(n<=0);
	
	cout<<"1 ";
	for(int i=1;i<n;i++){
		z = x + y;
		cout<<z<<" ";
		x = y;
		y = z;		
	}
	getch();
	return 0;
}
