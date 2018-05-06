#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main12() {
	
	int numero;
	int decena = 0;
	int unidad = 0;
	float promedio = 0.0;
	
	cout<<"Ingrese un valor:\n";
	
	cin>>numero;
	
	if((numero / 10) < 10){
		unidad = (numero%10);		
		if(unidad%2 == 0){			
			decena = (numero - unidad)/10;
			if(decena%2 == 0){
				
				cout<<"decena: "<<decena<<"\n";
				cout<<"unidad: "<<unidad<<"\n";
				promedio = decena + unidad;
				promedio /= 2;
				
				cout<<"El promedio es: "<<promedio<<"\n";
	
			}else{
				cout<<"La decena no es par\n";
			}
		}else{
			cout<<"La unidad no es par\n";
		}
	}else if(numero > 1){
		cout<<"El numero ingresado tiene mas de dos digitos\n";
	}else if(numero == 0){
		cout<<"El numero ingresado tiene menos de dos digitos\n";
	}
	
	system("PAUSE()");
}


