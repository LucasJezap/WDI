#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 5;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

void zadanie(int t[MAX][MAX]) {
	int max_kolumna = 0;
	int min_wiersz = 1e10;
	int w,k,suma_w,suma_k;
	for(int i=0;i<MAX;i++) {
		suma_w=0,suma_k=0;
		for(int j=0;j<MAX;j++) {
			suma_w+=t[i][j];
			suma_k+=t[j][i];
		} 
		if(suma_w<min_wiersz) { min_wiersz = suma_w, w=i; }
		if(suma_k>max_kolumna) { max_kolumna = suma_k, k=i; }
	}
	cout << "(" << w << "," << k << ")" << endl;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%25;
	} 
	wypisz(t);
	zadanie(t);
}
