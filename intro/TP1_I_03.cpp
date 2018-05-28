/*-------------------------------------------------------
TP1-I-03:
Validar el día, mes y el año para una fecha suministrada 
sabiendo que los años van desde 1960 hasta 2021. 
-------------------------------------------------------*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int dia, mes, ano;
	cout<<"Exprese dia, mes y anio\n";
	do{
		cout<<"Dia: ";cin>>dia;
		if(dia < 0 || dia > 31){
			cout<<"Exprese un dia comprendido entre 1 a 31\n";
		}
	}while(dia < 0 || dia > 31);
	do{
		cout<<"Mes: ";cin>>mes;
		if(mes < 0 || mes > 12){
			cout<<"Exprese un mes comprendido entre 1 a 12\n";
		}
	}while(mes < 0 || mes > 12);	
	do{
		cout<<"Anio: ";cin>>ano;
		if(ano < 1960 ||ano > 2021){
			cout<<"Exprese un anio comprendido entre 1960 a 2021\n";
		}
	}while(ano < 1960 || ano > 2021);	
	cout<<"\nUsted ingreso  Dia:"<<dia<<"  Mes:"<<mes<<"  Anio:"<<ano<<"\n";
	getch();
	return 0;
}
