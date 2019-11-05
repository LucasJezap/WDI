#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 10;

bool odwazenie(int t[N], int suma, int poczatek) {
	if(suma == 0) return true;
	if(suma<0 or poczatek == N) return false;
	return (odwazenie(t,suma-t[poczatek],poczatek+1) or odwazenie(t,suma,poczatek+1));
}

int main() {
	srand(time(NULL));
	int t[N];
	for(int i=0;i<N;i++) {
		t[i] = 1+rand()%20;
		cout << t[i] << " ";
	}
	cout << endl;
	if(odwazenie(t,49,0)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
