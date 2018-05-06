#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int main15() {
	
	int ano;
	int A, B, C, D, E, N;	

	cout<<"Exprese el año\n";
	
	do{
		cin>>ano;
		if(ano < 0 ||ano > 9999){
			cout<<"Exprese un año comprendido entre 0 a 9999\n";
		}
	}while(ano < 0 || ano > 9999);	
	
		
	A = ano % 19;
	B = ano % 4;
	C = ano % 7;
	D = (19*A + 24) % 30;
	E = (2*B + 4*C + 6*D + 5) % 7;
	N = (22 + D + E);
	
	if(N > 31){
		cout<<"La fecha de pascuas es: "<<(N-31)<<" de abril del "<<ano<<"\n";
	}else{
		cout<<"La fecha de pascuas es: "<<N<<" de marzo del "<<ano<<"\n";
	}
	
	system("PAUSE()");
}


