/*
TP1-I-06:
Calcular el valor de PI aplicando la fórmula:
PI = 4*(1 - 1/3 + 1/5 - 1/7 + ... - 1/99)
*/

#include<iostream>
#include<conio.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	double pi=0;
	
	for(int n=0;n<=99;n++){
		pi = pi + 4*(pow(-1,n)/(2*n+1));
	}
	cout<<"PI = 4*(1 - 1/3 + 1/5 - 1/7 + ... - 1/99)"<<endl;
	cout<<setprecision(10)<<fixed;
    cout<<"El valor de PI es: "<<pi<<endl;
    getch();
	return 0;
}
