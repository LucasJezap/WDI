#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void pisemne(int a, int b) {
	 int reszty[10];
	 cout << a/b << ".";
	 a=a%b;
	 int i=0;
	 while(i<10) {
	 	reszty[i] = a;
	 	a*=10;
	 	a=a%b;
	 	i++;
	 }
	 int poczatek=10,koniec=10;
	 bool okres = false;
	 for(int i=0;i<9;i++) {
	 	for(int j=i+1;j<10;j++) {
	 		if(reszty[i] == reszty[j] and reszty[i]!=0) {
	 			poczatek = i;
				koniec = j-1;
				okres=true;	
				break;
			} 
		 }
		 if(okres) break;
	 }
	 for(int i=0;i<poczatek;i++) cout << 10*reszty[i]/b;
	 if(okres) {
	 	cout << "(";
	 	for(int i=poczatek;i<=koniec;i++) cout << 10*reszty[i]/b;
	 	cout << ")";
	 }
}


int main() {
	int a,b;
	cin >> a >> b;
	pisemne(a,b);	
}
