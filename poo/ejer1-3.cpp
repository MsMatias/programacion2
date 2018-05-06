#include <iostream>
#include <iomanip>
/* Realizar una clase que permita representar un número complejo.
? Definir los datos miembros de la clase.
? Definir si fuera necesario funciones de carga y muestra de los datos miembro.
? Definir uno o más constructores para inicializar los datos miembro.
? Definir la sobrecarga de los operadores +, - y * para efectuar estas operaciones entre complejos.
? Definir una función miembro para calcular el conjugado de un complejo.
? Realizar un programa primcipal que haga uso de la clase. */

using namespace std;

class complejo {
	private:
		int r; //Real
		int i; //Imaginario
	
	public:
		complejo();
		complejo(int, int);
		void ver();
		complejo operator+(complejo);
		complejo operator-(complejo);
		complejo operator*(complejo);
		void conjugado();
};

complejo::complejo(){
	r = 0;
	i = 0;
}

complejo::complejo(int a, int b){
	r = a;
	i = b;
}

void complejo::	ver(){
	cout<<"El numero imaginario es: "<<r<<" + "<<i<<"i"<<endl;
}

complejo complejo::operator+(complejo c){
	complejo temp;
	
	temp.r = r + c.r;
	temp.i = i + c.i;
	
	return temp;
}

complejo complejo::operator-(complejo c){
	complejo temp;
	
	temp.r = r - c.r;
	temp.i = i - c.i;
	
	return temp;
}

complejo complejo::operator*(complejo c){
	complejo temp;
		
	temp.r = (r*c.r)-(i*c.i);
	temp.i = (r*c.i)+(i*c.r);
	
	return temp;
}

int main() {
	
	complejo c1(1, 2);	
	complejo c2(3, 10);
	complejo c3;
	
	c1.ver();
	
	c2.ver();
	
	c3 = c1 + c2;
	
	c3.ver();
	
	c3 = c1 - c2;
	
	c3.ver();
	
	c3 = c1 * c2;
	
	c3.ver();
					
	system("PAUSE()");
	
	return 0;
}

