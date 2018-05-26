/*

*/

#include<iostream>
#include<conio.h>
#include <string.h>

using namespace std;

class persona{
	private:
		int DNI;
		char* Nombre;
		char* Apellido;
		int tel_fijo;
		int tel_movil;
		
	public:
		persona();
		void sDNI(int);
		void sNombre(const char* p);
		void sApellido(const char* p);
		void stel_fijo(int);
		void stel_movil(int);
		
		int gDNI();
		char* gNombre();
		char* gApellido();
		int gtel_fijo();
		int gtel_movil();
		
};

persona::persona(){}

void persona::sDNI(int a){
	int dni = a;
}

void persona::sNombre(const char* p){
	int n = strlen(p);
	Nombre = new char[n];
	for(int i=0;i<n;i++){
		*(Nombre+i) = *(p+i);
	}
}

void persona::sApellido(const char* p){
	int n = strlen(p);
	Apellido = new char[n];
	for(int i=0;i<n;i++){
		*(Apellido+i) = *(p+i);
	}
}

void persona::stel_fijo(int fijo){
	int tel_fijo = fijo;
}

void persona::stel_movil(int movil){
	int tel_movil = movil;
}

/*int persona::gDNI(int _dni){
	return _dni;
}*/

char* persona::gNombre(){
	return Nombre;
}

char* persona::gApellido(){
	return Apellido;
}

int persona::gtel_fijo(){
	return tel_fijo;
}

int persona::gtel_movil(){
	return tel_movil;
}







int main(){

	getch();
	return 0;
}
