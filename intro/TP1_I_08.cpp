/*
TP1-I-08:
Obtener un programa que calcule y muestre e^x
utilizando la serie: 
e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int contador=1;
    int nTerminos;

    double total=1;
    double s=1;
    double m=1;
    double x;
	
    cout <<"Ingres el valor de x: ";
    cin >> x;
    cout <<"Ingrese los 'n' terminos de la serie: ";
    cin >> nTerminos;

    while (contador <= nTerminos)
    {
        s *= x;
        m *= contador;
        total += (s/m);
        contador++;
    }
	cout<<"e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!"<<endl;
    cout << "e^"<<x<<" = " << total;

    getch();
    return 0;
}
