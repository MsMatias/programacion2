#include <iostream>
#include <iomanip>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct Equipo {
	char nombre[20];
	int gf;
	int gc;
};

int main() {
	
	int n = 0;

	cout<<"Ingrese la cantidad de equipos: ";
	do{
		cin>>n;
	}while(n < 1);
	
	cout<<"\nCantidad de equipos: "<<n;
	
	Equipo *equipos = new Equipo[n];

	for(int i = 0; i < n; i++){		
		cout<<"\nIngrese los datos del equipo"<<(i+1)<<": ";
		cout<<"\n-Nombre del equipo: ";	
		cin>>equipos[i].nombre;
		cout<<"\n-Goles a favor del equipo: ";
		cin>>equipos[i].gf<<endl;
		cout<<"\n-Goles en contra del equipo: ";
		cin>>equipos[i].gc;
	}
	
	for(int i = 0; i < n; i++){	
		if(equipos[i].gf > equipos[i].gc){
			cout<<"\n-Nombre del equipo: ";	
			cout<<equipos[i].nombre;
			cout<<"\n-Goles a favor del equipo: ";
			cout<<equipos[i].gf;
			cout<<"\n-Goles en contra del equipo: ";
			cout<<equipos[i].gc<<endl;
			cout<<"-------------------------------"<<endl;
		}
	}
				
	system("PAUSE()");
}

