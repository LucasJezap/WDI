#include <iostream>
#include <math.h>
using namespace std;

bool zlozona(int n) {
	if(n==1) return false;
	if(n==2 or n==3) return false;
	if(n%2==0 or n%3==0) return true;
	int b=5;
	while(b<=sqrt(n)) {
		if(n%b==0) return true;
		b+=2;
		if(n%b==0) return true;
		b+=4;
	}
	return false;
}

void poszukiwania(int a, int b, int liczba, int &licznik) {
    if(a==0 and b==0 and zlozona(liczba)) { cout << liczba << endl; licznik++; }
    if(a>0) poszukiwania(a-1,b,liczba*2+1,licznik);
    if(b>0) poszukiwania(a,b-1,liczba*2,licznik);
}

int zadanie(int a, int b) {
    int licznik = 0;
    poszukiwania(a-1,b,1,licznik);
    return licznik;
}

int main() {
    int a,b;
    cout << "Ile jedynek? ";
    cin >> a;
    cout << "Ile zer? ";
    cin >> b;
    cout << zadanie(a,b) << endl;
}
