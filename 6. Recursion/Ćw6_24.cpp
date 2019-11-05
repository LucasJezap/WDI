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

void zadanie(int a,int liczba, int mnoznik, int wykreslone) {
    if(a==0 and wykreslone>0 and pierwsza(liczba)) cout << liczba << endl;
    if(a>0) {
        zadanie(a/10,liczba,mnoznik,wykreslone);
        zadanie(a/10,a%10*mnoznik+liczba,mnoznik*10,wykreslone+1);
    }
}

int main() {
    int a;
    cin >> a;
    zadanie(a,0,1,0);
}
