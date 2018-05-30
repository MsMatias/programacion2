/*
TP1-I-12:
Solicitar al usuario un valor entero y decir si es capicúa.
*/
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int num,aux,resto,numInv=0;
 	cout<<"Ingrese un numero: ";cin>>num;
 	aux=num;
	while(aux>0){
        resto=aux%10;
      	aux=aux/10;
		numInv=numInv*10+resto;
	}
 	if(numInv==num){cout<<"\nEl numero ingresado es capicua.";}
 	else{cout<<"\nEl numero ingresado no es capicua.";}
	getch();
	return 0;
}
