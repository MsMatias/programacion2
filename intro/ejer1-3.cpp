#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int main13() {
	
	int dia, mes, ano;
	
	cout<<"Exprese dia, mes y año\n";
	
	do{
		cin>>dia;
		if(dia < 0 || dia > 31){
			cout<<"Exprese un dia comprendido entre 1 a 31\n";
		}
	}while(dia < 0 || dia > 31);
	
	do{
		cin>>mes;
		if(mes < 0 || mes > 12){
			cout<<"Exprese un mes comprendido entre 1 a 12\n";
		}
	}while(mes < 0 || dia > 12);
	
	do{
		cin>>ano;
		if(ano < 1960 ||ano > 2021){
			cout<<"Exprese un año comprendido entre 1960 a 2021\n";
		}
	}while(ano < 1960 || ano > 2021);	
	
	cout<<"Ingreso dia: "<<dia<<" mes:"<<mes<<" año:"<<ano<<"\n";
	
	system("PAUSE()");
}


