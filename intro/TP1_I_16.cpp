/*
TP1-I-16:
El número mágico de una persona puede considerarse como la suma de las cifras de
su día de nacimiento, repitiendo el proceso hasta que la suma de las cifras devuelva
un número menor de 10. Leer la fecha de nacimiento de una persona, utilizando el
formato aaaammdd (utilizando un único entero) y calcular su número mágico.
*/

#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int f;
	int s = 0;
	do{
		cout<<"Ingrese fecha de nacimiento en formato: aaaammdd: ";cin>>f;	
	}while(f<19000101||f>20180601||((f%10000)/100)<1||((f%10000)/100)>12)||f%100<1||f%100>30;
	do{
		s = s + f%10;  // 0+0     - 0+2    - 2+8     || 0+1     - 1+2    - 3+8
		f = f/10;      // 1981082 - 198108 - 198110  || 1981082 - 198108   19810
	}while(s<10&&f!=0);
	cout<<"\nEl numero magico es: "<<s<<endl;
	getch();
	return 0;
}
