#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 10;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

int zadanie(int t[MAX][MAX]) {
	int dlugosc;
	int max_dlugosc = 2;
	for(int i=0;i<MAX-2;i++) {
		dlugosc = 2;
		for(int j=0;j<MAX-2;j++) {
			if(1.0*t[i+1][j+1]/t[i][j]==1.0*t[i+2][j+2]/t[i+1][j+1]) dlugosc++;
			else dlugosc = 2;
			if(dlugosc>max_dlugosc) max_dlugosc = dlugosc;
		}
	}
	if(max_dlugosc>2) {
		cout << "Znaleziono taki ciag o dlugosci " << endl;
		return max_dlugosc;
	}
	cout << "Nie znaleziono takiego ciagu " << endl;
	return 0;
}

int f (int n) {
    if(n<2) return n;
    return abs(n%2-f(n/2));
}


int main() {
    for(int i=1;i<50;i++) {
        cout << i << " -> " << f(i) << endl;
    }
    cout << endl << endl;
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%20;
	}

	wypisz(t);
	cout << zadanie(t) << endl;
}
