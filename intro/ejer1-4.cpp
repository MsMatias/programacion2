#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main14() {
	
	int horas, minutos, segundos;
	
	cout<<"Exprese horas, minutos, segundos\n";
	
	do{
		cin>>horas;
	}while(horas < 0);
	
	do{
		cin>>minutos;
	}while(minutos < 0);
	
	do{
		cin>>segundos;
	}while(segundos < 0);
	
	cout<<"Ingreso "<<horas<<"h "<<minutos<<"m "<<segundos<<"s\n";
	
	cout<<"Nueva salida 15 segundos despues: \n";
	
	segundos += 15;
	
	while(segundos >= 60){
		segundos -= 60;
		minutos++;
	}
	
	while(minutos >= 60){
		minutos -= 60;
		horas++;
	}
	
	cout<<"Ingreso "<<horas<<"h "<<minutos<<"m "<<segundos<<"s\n";
	
	system("PAUSE()");
}
