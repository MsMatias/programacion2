#include <iostream>
#include<conio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <windows.h> 

using namespace std;

#define LARGO_NOMBRE 20

/********************************************
**************** CLASE FECHA ****************
*********************************************/

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
	
/********************************************
*************** CLASE PERSONA ***************
*********************************************/

class persona{
	private:
		long DNI;
		char* Nombre;
		char* Apellido;
		long tel_fijo;
		long tel_movil;
		
	public:
		persona();
		void sDNI(long);
		void sNombre(const char* p);
		void sApellido(const char* p);
		void stel_fijo(long);
		void stel_movil(long);
		
		long gDNI();
		char* gNombre();
		char* gApellido();
		long gtel_fijo();
		long gtel_movil();
		
};

persona::persona(){}

void persona::sDNI(long a){
	long DNI = a;
}

void persona::sNombre(const char* p){
	int n = strlen(p);
	Nombre = new char[n];
	for(int i=0;i<n;i++){
		for(int i = 0;i<LARGO_NOMBRE;i++){
		if(i < n)
			*(Nombre+i) = *(p+i);
		else
			*(Nombre+i) = '\0';
	}
	}
}

void persona::sApellido(const char* p){
	int n = strlen(p);
	Apellido = new char[n];
	for(int i = 0;i<LARGO_NOMBRE;i++){
		if(i < n)
			*(Apellido+i) = *(p+i);
		else
			*(Apellido+i) = '\0';
	}
}

void persona::stel_fijo(long fijo){
	long tel_fijo = fijo;
}

void persona::stel_movil(long movil){
	long tel_movil = movil;
}

long persona::gDNI(){
	return DNI;
}

char* persona::gNombre(){
	return Nombre;
}

char* persona::gApellido(){
	return Apellido;
}

long persona::gtel_fijo(){
	return tel_fijo;
}

long persona::gtel_movil(){
	return tel_movil;
}

/********************************************
************** CLASE PRESTAMO ***************
*********************************************/

class prestamo {
	private:
		int nPrestamo;
		persona solicitante;
		float Valor;
		float TasaInteres;
		int nCuotas;
		fecha fAutorizacion;
		fecha fEntrega;
		fecha* fPagos;
	
	public:
		prestamo(persona _solicitante);	
		void snPrestamo(int n);
		int gnPrestamo();
		void sValor(float v);
		float gValorSinInteres();
		float gValorInteres();
		void sTasaInteres(float i);
		float gTasaInteres();
		void snCuotas(int c);
		int gnCuotas();
		void definirFechas(int d, int m, int a);
		fecha gfAutorizacion();
		fecha gfEntrega();
		void ejecutarCuotas();
		void VerCuotas();
		
};

prestamo::prestamo(persona _solicitante){	
	solicitante = _solicitante;
}

void prestamo::snPrestamo(int n){
	if(n > 0){
		nPrestamo = n;
		cout<<"Numero asignado!"<<endl;
	}else{
		cout<<"El numero del prestamo debe ser mayor a 0"<<endl;
	}
}

int prestamo::gnPrestamo(){
	return nPrestamo;
}

void prestamo::sValor(float v){
	if(v > 0){
		Valor = v;
		cout<<"Valor aisgnado!"<<endl;
	}else{
		cout<<"El valor del pretamos debe ser mayor a 0"<<endl;
	}
}

float prestamo::gValorSinInteres(){
	return Valor;
}

float prestamo::gValorInteres(){
	return Valor+(Valor*TasaInteres/10);
}

void prestamo::sTasaInteres(float i){
	TasaInteres = i;
	cout<<"Tasa asiganda!"<<endl;
}

float prestamo::gTasaInteres(){
	return TasaInteres;
}

void prestamo::snCuotas(int c){
	if(c > 0){
		nCuotas = c;		
		cout<<"Cuotas asignadas!"<<endl;
	}else{
		cout<<"El numero de cuotas debe ser mayor a 0"<<endl;
	}
}

int prestamo::gnCuotas(){
	return nCuotas;
}

void prestamo::definirFechas(int d, int m, int a){	
	fAutorizacion.setdia(d);
	fAutorizacion.setmes(m);
	fAutorizacion.setanio(a);
	
	fEntrega = fAutorizacion;
	fEntrega = fEntrega + 7;
}

fecha prestamo::gfAutorizacion(){
	return fAutorizacion;
}

fecha prestamo::gfEntrega(){
	return fEntrega;
}

void prestamo::ejecutarCuotas(){
	
	fPagos = new fecha[nCuotas];
	
	for(int c = 0; c < nCuotas; c++){
		fPagos[c] = fEntrega;
		fPagos[c] = fPagos[c] + (30*(c+1));
	}
	
	cout<<"Cuotas ejecutadas"<<endl;
}

void prestamo::VerCuotas(){
	
	float monto = gValorInteres()/nCuotas;
	
	for(int c = 0; c < nCuotas; c++){
		cout<<"Cuota N "<<(c+1)<<endl;
		cout<<"Valor: "<<monto<<endl;
		cout<<"Fecha de Pago: "<<fPagos[c].getdia()<<"/"<<fPagos[c].getmes()<<"/"<<fPagos[c].getanio()<<endl;
		cout<<"---------------------------"<<endl;
	}
	
}

void cabecera();

int main(int argc, char** argv) {
	
	persona solicitante;
	char* nombre;
	char* apellido;
	long dni;
	long tFijo;
	long tMovil;
	char verificacion;
	int nPrestamo;
	float Valor;
	float TasaInteres;
	int nCuotas;
	int dia, mes, anio;
	
	do{
	
	system("CLS");
	
	cabecera();	
	
	nombre = (char *) malloc(LARGO_NOMBRE);
	apellido = (char *) malloc(LARGO_NOMBRE);		
		
	cout<<"Defina los datos del solicitante"<<endl;
	cout<<"Apellido: ";
	cin>>apellido;
	solicitante.sApellido(apellido);
	cout<<"Nombre: ";
	cin>>nombre;
	solicitante.sNombre(nombre);
	cout<<"DNI: ";
	cin>>dni;
	solicitante.sDNI(dni);
	cout<<"Telefono Fijo: ";
	cin>>tFijo;
	solicitante.stel_fijo(tFijo);
	cout<<"Telefono Movil: ";
	cin>>tMovil;
	solicitante.stel_movil(tMovil);
	
	system("CLS");
	
	cabecera();
	
	cout<<"Datos del solicitante ingresados:"<<endl;
	cout<<"Apellido: "<<apellido<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"DNI: "<<dni<<endl;
	cout<<"Telefono Fijo: "<<tFijo<<endl;
	cout<<"Telefono Movil: "<<tMovil<<endl;
	cout<<"Los datos estan correctos? S/N: ";
	
	if((verificacion = getch()) == 's' || (verificacion = getch()) == 'S'){
		break;
	}
	
	
	}while((verificacion = getch()) == 'n' || (verificacion = getch()) == 'N');	
	
	prestamo prestamo1(solicitante);	
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese el numero de indentificacion de prestamo: ";
		cin>>nPrestamo;		
	}while(nPrestamo < 1);	
	
	prestamo1.snPrestamo(nPrestamo);
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese el valor del prestamo: ";
		cin>>Valor;
	}while(Valor < 1);
	
	prestamo1.sValor(Valor);
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese la tasa de interes: ";
		cin>>TasaInteres;
	}while(TasaInteres < 1);
	
	prestamo1.sTasaInteres(TasaInteres);
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese la cantidad de cuotas: ";
		cin>>nCuotas;
	}while(nCuotas < 1);
	
	prestamo1.snCuotas(nCuotas);
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese el DIA de la autorizacion: ";
		cin>>dia;
	}while(dia < 1 || dia > 31);
		
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese el MES de la autorizacion: ";
		cin>>mes;
	}while(mes < 1 || mes > 12);	
	
	do{
		system("CLS");
		cabecera();
		cout<<"Ingrese ANIO de la autorizacion: ";
		cin>>anio;
	}while(anio < 1 || anio > 9999);
	
	prestamo1.definirFechas(dia, mes, anio);
	
	system("CLS");
	
	cabecera();
	
	cout<<"-Datos del prestamo: "<<endl;
	cout<<"-Numero de prestamo: "<<nPrestamo<<endl;
	cout<<"-Valor del prestamo: $"<<Valor<<endl;
	cout<<"-Tasa de interes: "<<TasaInteres<<"%"<<endl;
	cout<<"-Fecha de Autorizacion: "<<prestamo1.gfAutorizacion().getdia()<<"/"<<prestamo1.gfAutorizacion().getmes()<<"/"<<prestamo1.gfAutorizacion().getanio()<<endl;
	cout<<"-Fecha de Entrega: "<<prestamo1.gfEntrega().getdia()<<"/"<<prestamo1.gfEntrega().getmes()<<"/"<<prestamo1.gfEntrega().getanio()<<endl<<endl;
	cout<<"-Presione Enter para ejecutar las cuotas"<<endl<<endl;	
	
	while((verificacion = getch()) != 13);
	
	prestamo1.ejecutarCuotas();
	prestamo1.VerCuotas();
	
	return 0;
}

void cabecera(){
	system("color 17");
	cout<<"======================================"<<endl;
	cout<<"== Sistema de prestamos financieros =="<<endl;
	cout<<"======================================"<<endl<<endl;
}
