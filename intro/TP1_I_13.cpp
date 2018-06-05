#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int num, resto = 0,c = 0;
	cout<<"Ingrese un numero por favor "; cin>>num;
	do{
		resto = num%10;
		num = num/10;
		if(resto == 3)c++;
	}while(num != 0);
	if(c != 0){
		cout<<"\nEl numero ingresado tiene: "<<c<<" veces la cifra 3.";
		}
	else cout<<"\nEl numero ingresado no tiene la cifra 3.";
	getch();
	return 0;
}
