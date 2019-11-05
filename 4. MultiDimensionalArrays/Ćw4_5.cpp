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
	int max_kolumna_dodatnia = 0;
	int min_wiersz_dodatni = 1e10;
	int max_kolumna_ujemna = 0;
	int min_wiersz_ujemny = -1e10;
	int w1,k1,w2,k2,suma_w,suma_k;
	for(int i=0;i<MAX;i++) {
		suma_w=0,suma_k=0;
		for(int j=0;j<MAX;j++) {
			suma_w+=t[i][j];
			suma_k+=t[j][i];
		} 
		if(suma_w<min_wiersz_dodatni and suma_w>0) { min_wiersz_dodatni = suma_w, w1=i; }
		if(suma_k>max_kolumna_dodatnia and suma_k>0) { max_kolumna_dodatnia = suma_k, k1=i; }
		if(suma_w>min_wiersz_ujemny and suma_w<0) { min_wiersz_ujemny = suma_w, w2=i; }
		if(suma_k<max_kolumna_ujemna and suma_k<0) { max_kolumna_ujemna = suma_k, k2=i; }
	}
	
	if(1.0*max_kolumna_dodatnia/min_wiersz_dodatni>1.0*max_kolumna_ujemna/min_wiersz_ujemny) cout << "(" << w1 << "," << k1 << ")" << endl;
	else cout << "(" << w2 << "," << k2 << ") UJEMNE" << endl;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%25-rand()%25;
	} 
	wypisz(t);
	zadanie(t);
}
