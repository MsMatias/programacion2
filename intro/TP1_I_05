/*
TP1-I-05:
La fecha de Pascua corresponde al primer domingo después de la primera 
luna llena que sigue al equinoccio de primavera, y se calcula con 
las siguientes expresiones:
A = año mod 19
B = año mod 4
C = año mod 7
D = (19*A + 24) mod 30
E = (2*B + 4*C + 6*D + 5) mod 7
N = (22 + D + E)
En el que N indica el número del día de marzo (o Abril si N > 31) 
correspondiente al domingo de Pascua. Realizar un programa que 
dado un año calcule esa fecha.
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int ano;
	int A, B, C, D, E, N;	

	cout<<"Exprese el anio\n";
	
	do{
		cin>>ano;
		if(ano < 0 ||ano > 9999){
			cout<<"Exprese un anio comprendido entre 0 a 9999\n";
		}
	}while(ano < 0 || ano > 9999);	
	
		
	A = ano % 19;
	B = ano % 4;
	C = ano % 7;
	D = (19*A + 24) % 30;
	E = (2*B + 4*C + 6*D + 5) % 7;
	N = (22 + D + E);
	
	if(N > 31){
		cout<<"La fecha de pascuas es: "<<(N-31)<<" de abril del "<<ano<<"\n";
	}else{
		cout<<"La fecha de pascuas es: "<<N<<" de marzo del "<<ano<<"\n";
	}
	getch();
	return 0;
}
