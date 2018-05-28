/*TP1-I-04:
Escriba un programa, que dada una hora del día en Horas, Minutos y Segundos
calcule la hora correspondiente 15 segundos después. 
(Validar la entrada de datos).*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int horas, minutos, segundos;
	
	cout<<"Exprese horas, minutos, segundos\n";
	
	do{
		cout<<"Horas: ";cin>>horas;
		if(horas < 0) cout<<"Ingrese un valor mayor o igual a 0.\n";
	}while(horas < 0);
	
	do{
		cout<<"Minutos: ";cin>>minutos;
		if(minutos < 0) cout<<"Ingrese un valor mayor o igual a 0.\n";
	}while(minutos < 0);
	
	do{
		cout<<"Segundos: ";cin>>segundos;
		if(segundos < 0) cout<<"Ingrese un valor mayor o igual a 0.\n";
	}while(segundos < 0);
	
	cout<<"Usted ingreso "<<horas<<"h "<<minutos<<"m "<<segundos<<"s";
	cout<<" mas 15 segundos despues: \n";
	
	segundos += 15;
	
	while(segundos >= 60){
		segundos -= 60;
		minutos++;
	}
	
	while(minutos >= 60){
		minutos -= 60;
		horas++;
	}
	
	cout<<"El tiempo final es: "<<horas<<"h "<<minutos<<"m "<<segundos<<"s.\n";
	getch();
	return 0;
}
