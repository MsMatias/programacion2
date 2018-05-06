#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int MCDw (int, int);
int MCDr (int, int);

int main() {
	
	int n1, n2;
	
	cin>>n1;
	cin>>n2;
	
	cout<<MCDw(n1, n2)<<"\n";
	cout<<MCDr(n1, n2)<<"\n";
				
	system("PAUSE()");
}


int MCDw(int a, int b){
	int r = b;	
	
	if(b > a){
		r = a;
		a = b;
	}
	
	do{		
		b = r;		
		r = a%b;		
		a = b;			
	}while(r != 0);
	
	return b;
}


int MCDr(int a, int b){
	int r = b;	
	
	if(b > a){
		r = a;
		a = b;
	}
			
	
	b = r;
	r = a%b;
	a = b;
	
	if(r != 0)	
		return	MCDr(a, r);
	else	
		return b;
}
