#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int NA (int, int);

int main() {
	
	int n1, n2;
	
	cin>>n1;
	cin>>n2;
	
	cout<<NA(n1, n2);
				
	system("PAUSE()");
}

int NA (int a, int b){
	int p1 = 1;
	int p2 = 1;	
	int s1 = 0;
	int s2 = 0;
		
	do{
		
		if(a%p1 == 0){
			s1 += p1;
		}
		p1++;	
		
	}while((a/p1) > 1);
	
	do{
		
		if(b%p2 == 0){
			s2 += p2;
		}
		p2++;	
		
	}while((b/p2) > 1);
	
	if(s1 == b && s2 == a){
		return 1;
	}
	
	return 0;
}
