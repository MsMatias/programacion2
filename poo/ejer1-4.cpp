#include <iostream>
#include <iomanip>
/* Realizar una clase que permita representar un cronometro. Dicho cronometro consta
de horas, minutos y segundos. Las horas no tienen límite en valor mientras que los
minutos y segundos llegan al maximo hasta 59.
o Definir los datos miembros de la clase.
o Definir si fuera necesario funciones de carga y muestra de los datos miembro.
o Definir un constructor que inicializa a cero el coronometro.
o Definir un metodo Reset que permita llevar a cero el cronometro.
o Definir la sobrecarga del operador ++ para producir el incremento del
cronometro en un seg.
o Realizar un programa primcipal que haga uso de la clase. */

using namespace std;

class cronometro {
	private:
		int horas;
		int minutos;
		int segundos;
		
	public:
		cronometro();
		void sHoras(int);
		void sMinutos(int);
		void sSegundos(int);
		int gHoras();
		int gMinutos();
		int gSegundos();
		void Reset();
		void operator++(int);
};

cronometro::cronometro(){
	horas = 0;
	minutos = 0;
	segundos = 0;
}

void cronometro::sHoras(int a){
	horas = a;
}

void cronometro::sMinutos(int b){
	
	int m = 0;
	
	if(b > 59){
		m = b/60;
		for(int i = 0; i < m; i++){
			horas++;
			b -= 60;
		}
		
	}
	
	minutos = b;
			
}

void cronometro::sSegundos(int c){
	
	int s = 0;
	
	if(c > 59){
		s = c/60;
		for(int i = 0; i < s; i++){
			minutos++;
			c -= 60;
		}
		
	}
	
	segundos = c;
			
}

int cronometro::gHoras(){
	return horas;
}

int cronometro::gMinutos(){
	return minutos;
}

int cronometro::gSegundos(){
	return segundos;
}

void cronometro::Reset(){
	horas = 0;
	minutos = 0;
	segundos = 0;
}

void cronometro::operator++(int){
	sSegundos(segundos+1);
}

int main() {
	
	cronometro c;
	
	c.sHoras(5);
	c.sMinutos(5);
	c.sSegundos(122);
	
	cout<<"El cronometro esta en "<<c.gHoras()<<":"<<c.gMinutos()<<":"<<c.gSegundos()<<"s"<<endl;
	
	c.Reset();
	
	cout<<"El cronometro esta en "<<c.gHoras()<<":"<<c.gMinutos()<<":"<<c.gSegundos()<<"s"<<endl;
	
	for(int i = 0; i < 10; i++){
		c++;
		cout<<"El cronometro esta en "<<c.gHoras()<<":"<<c.gMinutos()<<":"<<c.gSegundos()<<"s"<<endl;
	}
	
				
	system("PAUSE()");
}
