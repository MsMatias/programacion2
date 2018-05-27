#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#include <conio.h>
#include <string.h>

class fecha {
	private: //no podran ser modificado
		int d;
		int m;
		int a;
	public: //valores modificables
	fecha();
	fecha (int,int,int);//constructor
		void setdia (int d); //retorno setdia. modifica
		int getdia(); //para mostrar dato
		void setmes (int m); //set (sentencia)
		int getmes();
		void setanio (int a);//int referencia
		int getanio();
		int valida(); //devuelve un dato para saber si esta bien
		//sobrecarga de operadores
		void operator++ (); //pasar a la fecha siguiente 
		//el retorno lo elije uno
		//ahora se puede hacer f++
		void operator-- ();
		fecha operator +(int dd);//a una fecha sumarle dias con parametros
		fecha operator -(int dd);
	};//declaramos el prototipo
	fecha::fecha(){
		d=1;
		m=1;
		a=1900;//estos son los valores que le ponemos por defecto al objeto
	}
	fecha::fecha(int dia,int mes,int anio){
		d=dia;
		m=mes;
		a=anio;
	}

void fecha::setdia(int dia)
	{ d=dia;}
void fecha::setmes(int mes)
	{ m=mes;}
void fecha::setanio(int anio)
	{a=anio;}
int fecha::getdia()
	{return d;}
int fecha::getmes()
	{return m;}
int fecha::getanio()
	{return a;}

	int fecha:: valida ()
		{
			if(d<1||d>31||m<1||m>12)
			return 0;//el return sale de la funcio
			if(d>30&&(m==4||m==6||m==9||m==11))
			return 0;
			if (m==2 && (d>29||(d>28 && a%4!=0)))
			return 0;
			return 1;//si llego hasta aca esta bien
		}
	void fecha::operator++ (){
		d++;
		if(!valida())//no es valido
		//para c cualquier cosa igual a 0 es invalido
		{
			d=1;
			m++;
			if(!valida()){
				m=1;
				a++;
			}
		}
	}
		void fecha::operator-- (){
		d--;
		if(!valida())//no es valido
		//para c cualquier cosa igual a 0 es invalido
		{
			d=31;
			if (!valida())
			d--;
			if (!valida())
			d--;
			m--;
			if(!valida()){
				m=12;
				a--;
			}
		}
	}
	fecha fecha::operator+(int dd){
		fecha R(d,m,a);
		for (int i=0; i<dd;i++)
		++R; //++R preincremento o R++
		return R;//el valor de f1 sea R
	}
	fecha fecha:: operator-(int dd){
		fecha R(d,m,a);
		for(int i=0;i<dd;i++)
		{
			--R;
			return R;
		}
	} 
	
using namespace std;	
	
int main ()
{
	fecha* fasd;
	
	fasd = new fecha[20];
	
	int d1,m1,a1,dd;
	cout<<"ingrese dia"<<endl;
	cin>>d1;
	cout<<"ingrese mes"<<endl;
	cin>>m1;
	cout<<"ingrese anio"<<endl;
	cin>>a1;
	fecha f (d1,m1,a1);
	if (f.valida()==0)
	{
	cout<<"fecha no valida"<<endl;
	return 0;
	}
	cout<<"un dia extra"<<endl;
	++f;
	cout<<f.getdia()<<endl;
	cout<<f.getmes()<<endl;
	cout<<f.getanio()<<endl;
	--f;
	cout<<"cuantos dias va a agregar"<<endl;
	cin>>dd;
	fecha f1;
	f1=f+dd;
	cout<<f1.getdia()<<endl;//muestra los dias agregados
	cout<<f1.getmes()<<endl;
	cout<<f1.getanio()<<endl;
	cout<<"cuantos dias va a restar"<<endl;
	cin>>dd;
	fecha f2;
	f2=f-dd;
	cout<<f2.getdia()<<endl;//muestra los dias agregados
	cout<<f2.getmes()<<endl;
	cout<<f2.getanio()<<endl;
	
	/*/
	fecha f; //instanciar el objeto
	//f tiene dia, mes y año. son cosas privadas
	f.setdia(23);//objeto.metodo
	f.setmes(4);
	f.setanio(2018);
	cout<<f.getmes()<<"/"<<f.getanio(); //get para mostrar
	/*/
	system ("pause");
	return 0;
}


