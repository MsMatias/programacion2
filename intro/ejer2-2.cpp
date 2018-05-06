#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int Digitos (int);

int main() {
	
	int n1;
	
	cin>>n1;
	
	cout<<Digitos(n1)<<"\n";
				
	system("PAUSE()");
}

int Digitos (int a){
	int c = 1;
	
	while(a > 10){
		a = a/10;;
		c++;
	}
	
	return c;
}
