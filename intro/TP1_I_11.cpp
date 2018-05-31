/*
TP1-I-11:
Desarrollar un programa en el cual introduzca un número entero 
positivo e invierta los dígitos del número. Mostrar en pantalla el número invertido.
*/
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int num,resto,numINV=0;
  	cout<<"Introduce un numero entero positivo: ";cin>>num;
 	while(num>0){
        resto=num%10;
    	num=num/10;
      	numINV=numINV*10+resto;
 	}
 	cout<<"\nEl numero invertido es: "<<numINV;
	getch();
	return 0;
}
