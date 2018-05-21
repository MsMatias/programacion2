#include <iostream>
#include <iomanip>
#include <math.h>

#define _USE_MATH_DEFINES

# define M_PI           3.14159265358979323846  /* pi */

/* Se desea obtener un sistema de representacion de figuras geometricas. Toda figura
geometrica posee un centro (coordenada x y coordenada y) y posee ademas una
formula para calcular su perimetro y su area.
Es posible definir tambien la razon superficie/perimetro.
Teniendo en cuenta estas cosideraciones obtenga un mecanismo de herencia que a
partir de una clase abstracta FIG_GEO permita generar las clases derivadas para
representar un punto, un círculo y un poligono regular.
Realice las pruebas de las clases creadas mediante un programa principal. */

using namespace std;

class FIG_GEO {
	
	protected:
		int x;
		int y;
		
	public:
		virtual float gPerimetro();
		virtual float gArea();
		int gRazon(){ return gArea()/gPerimetro();}
		
};

class Punto : public FIG_GEO {
			
	public:
		Punto(int x, int y):FIG_GEO(x, y){};	
		float gPerimetro(){ return 0;}
		float gArea(){ return 1;}
};

class Circulo : public FIG_GEO {
	
	private:
		int radio;
		
	public:
		Circulo(int, int, int);
		float gPerimetro();
		float gArea();
};

Circulo::Circulo(int _x, int _y, int _r){	
	x = _x;
	y = _y;
	radio = _r;		
}

float Circulo::gPerimetro(){
	return M_PI*2*radio;
}

float Circulo::gArea(){
	return M_PI*(radio*radio);
}

class Poligono : public FIG_GEO {
	
	private:
		int lados;
		int largo;
		
	public:
		Poligono(int, int, int, int);	
		float gPerimetro();
		float gArea();
};

Poligono::Poligono(int _x, int _y, int _n, int _l){	
	x = _x;
	y = _y;
	lados = _n;	
	largo = _l;		
}

float Poligono::gPerimetro(){
	return lados*largo;
}

float Poligono::gArea(){
	int angulo = (360/lados)/2;	
	double radianes = angulo * (M_PI/180);
	int perimetro = lados*largo;
	int cateto = largo/2;
	double tangente = tan(radianes);
	double apotema = cateto/tangente;
	
	return (apotema*perimetro)/2;
}

int main() {
	
	Circulo circ(0, 0, 10);
	Poligono poli(0, 0, 5, 2);
	
	cout<<"Perimetro del circulo: "<<circ.gPerimetro()<<", Area del circulo: "<<circ.gArea()<<endl;
	cout<<"Perimetro del poligono: "<<poli.gPerimetro()<<", Area del poligono: "<<poli.gArea()<<endl;
					
	system("PAUSE()");
}

