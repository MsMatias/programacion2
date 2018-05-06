#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctime>
/* Representar mediante una clase la gestion de la informacion relativa a una persona.
Dicha informacion consiste en:
? Apellido
? Nombre
? Fecha de nacimiento.
? DNI
Se deben definir los datos miembro necesarios y las funciones de carga y
visualizacion de los mismos.
Definir ademas los metodos para:
Calcular la edad.
Mostrar los datos personales.
Mediante un mecanismo de herencia definir la clase alumno sabiendo que la unica
informacion que se agrega es el curso que frecuenta.
Determiar los metodos a definir para la clase derivada.
Determinar los metodos a redefinir si los hubiera. */

using namespace std;

class persona {
	
	private:
		char* Apellido;
		char* Nombre;
		struct fNacimiento {
			int dia;
			int mes;
			int ano;
		};		
		fNacimiento fn;
		int dni;
		
	public:
		persona();
		void sApellido(const char* p);
		void sNombre(const char* p);
		void sfNacimiento(int, int, int);
		void sDNI(int);
		char* gApellido();
		char* gNombre();
		int gfNacimiento_dia();
		int gfNacimiento_mes();
		int gfNacimiento_ano();
		int gDNI();
		int gEdad();		
};

persona::persona(){
	
}

void persona::sApellido(const char* p){
	
    int n = strlen(p);
		
	Apellido = new char[n];
	
	for(int i = 0; i < n; i++){
		*(Apellido+i) = *(p+i);		
	}
		
}

void persona::sNombre(const char* p){
	int n = strlen(p);
		
	Nombre = new char[n];
	
	for(int i = 0; i < n; i++){
		*(Nombre+i) = *(p+i);		
	}
}

void persona::sfNacimiento(int d, int m, int a){
	fn.dia = d;
	fn.mes = m;
	fn.ano = a;
}

void persona::sDNI(int a){
	dni = a;
}

char* persona::gApellido(){
	return Apellido;
}

char* persona::gNombre(){
	return Nombre;
}

int persona::gfNacimiento_dia(){
	return fn.dia;
}

int persona::gfNacimiento_mes(){
	return fn.mes;
}

int persona::gfNacimiento_ano(){
	return fn.ano;
}

int persona::gDNI(){
	return dni;
}

int persona::gEdad(){
	time_t t = time(0);
    tm* now = localtime(&t);
    
    int na = now->tm_year + 1900;
    int ma = now->tm_mon + 1;
    int da = now->tm_mday;
		
	if ((fn.mes == ma) && (fn.dia > da)) {
    	na=(na-1);
    }
  
    if (fn.mes > ma) {
    	na=(na-1);
    }

    return (na-fn.ano);
	
}

class alumno : public persona {
	
	private:
		int curso;
		
	public:
		alumno();
		void sCurso(int);
		int gCurso();
};

alumno::alumno(){
	
}

void alumno::sCurso(int c){
	curso = c;
}

int alumno::gCurso(){
	return curso;
}


int main() {

	alumno A;
	
	A.sApellido("Miranda");	
	A.sNombre("Matias");
	A.sfNacimiento(19, 8, 1994);
	A.sDNI(38411250);
	A.sCurso(2);
	
	cout<<A.gApellido()<<endl;
	cout<<A.gNombre()<<endl;
	cout<<A.gDNI()<<endl;
	cout<<A.gfNacimiento_dia()<<"/"<<A.gfNacimiento_mes()<<"/"<<A.gfNacimiento_ano()<<endl;
	cout<<A.gCurso()<<endl;
	cout<<A.gEdad()<<endl;
				
	system("PAUSE()");
}

