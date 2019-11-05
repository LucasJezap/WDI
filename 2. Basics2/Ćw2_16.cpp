#include <iostream>
#include <math.h>
using namespace std;

bool pierwsza(int n) {
	if(n==1) return false;
	if(n==2 or n==3) return true;
	if(n%2==0 or n%3==0) return false;
	int b=5;
	while(b<=sqrt(n)) {
		if(n%b==0) return false;
		b+=2;
		if(n%b==0) return false;
		b+=4;
	}
	return true;
}

int zadanie(int a, int b, int liczba, int mnoznik) {
    int suma = 0;
    if(a==0 and b==0 and pierwsza(liczba)) { cout << liczba << endl; suma = 1;}
    if(a>0) suma+=zadanie(a/10,b,a%10*mnoznik+liczba,mnoznik*10);
    if(b>0) suma+=zadanie(a,b/10,b%10*mnoznik+liczba,mnoznik*10);
    return suma;
}


int main() {
	int a,b;
	cin >> a >> b;
	cout << endl << "Jest ich " << zadanie(a,b,0,1) << endl;
}
