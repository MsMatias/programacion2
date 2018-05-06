#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int main16() {
	
	double pi;
	double suce = 1;
	
	for(double i = 5.0; i < 99.0; i += 4.0){		
		suce -= (double)1.0/(i-2.0);
		suce += (double)1.0/(i); 
		
	}	
	
	pi = (double)4.0 * suce;
	
	cout<<setprecision(50)<<fixed;
	cout<<pi<<"\n";
			
	system("PAUSE()");
}


