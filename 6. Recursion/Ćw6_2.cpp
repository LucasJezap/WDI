#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

const int N = 10;

bool odwazenie(int t[N], int suma, int poczatek, string a) {
	if(suma == 0) {
		cout << a << endl;
		return true;
	}
	if(poczatek == N) return false;
	ostringstream x;
	x << t[poczatek];
	a+= x.str();
	return (odwazenie(t,suma-t[poczatek],poczatek+1,a+" + ") or odwazenie(t,suma,poczatek+1,a+ " ") or odwazenie(t,suma+t[poczatek],poczatek+1,a+" - "));
}

int main() {
	srand(time(NULL));
	int t[N];
	for(int i=0;i<N;i++) {
		t[i] = 1+rand()%20;
		cout << t[i] << " ";
	}
	cout << endl;
	if(odwazenie(t,49,0,"")) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
