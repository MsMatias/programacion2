/*
TP1-I-01:
Dada una medida de tiempo expresada en horas, minutos y segundos
con valores arbitrarios, obtenga un programa que transforme 
dicha medida en una expresión correcta. 
Por ejemplo, dada la medida 3h 118m 195s, el programa deberá 
obtener como resultado 5h 1m 15s.
*/

#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int h,m,s;
	cout<<"Ingrese el tiempo "<<endl;
	cout<<"Horas     "; cin>>h;
	cout<<"Minutos:  "; cin>>m;
	cout<<"Segundos: "; cin>>s;
	s=s+(m*60)+(h*3600);
	m=s/60;
	s=s%60;
	h=m/60;
	m=m%60;
	cout<<"El tiempo correctamente expresado:"<<endl;
	cout<<h<<"(hs) "<<m<<"(min) "<<s<<"(seg)";
	getch();
	return 0;
}
