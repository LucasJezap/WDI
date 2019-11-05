#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

void dosun(int tab[MAX][MAX], int tab2[MAX][MAX], int i, int rozmiar) {
	for(int j=0;j<rozmiar-1;j++) {                       // dosuwanie wierszy
		for(int k=0;k<rozmiar;k++) tab2[j][k]=tab[j+1][k];
	}
	for(int j=i;j<rozmiar-1;j++) {                      // dosuwanie kolumn
		for(int k=0;k<rozmiar-1;k++) tab2[k][j] = tab2[k][j+1];
	}
}


int wyznacznik(int tab[MAX][MAX],int rozmiar) {
	int tab2[MAX][MAX];
	if(rozmiar==1) return tab[0][0];
	int s=0;
	int zn=1;
	for(int i=0;i<rozmiar;i++) {
		dosun(tab,tab2,i,rozmiar);
		s+=tab[0][i]*wyznacznik(tab2,rozmiar-1)*zn;
		zn*=-1;
	}
	return s;
}


int main() {
    srand(time(NULL));
	int tab[MAX][MAX];
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++) {
			//cout << "Wiersz " << i << " Kolumna " << j << ":" << endl;
			//cin >> tab[i][j];
			tab[i][j] = rand()%30;
		}
	wypisz(tab);
	cout << endl << wyznacznik(tab,MAX) << endl;
}
