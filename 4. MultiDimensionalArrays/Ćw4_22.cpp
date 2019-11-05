#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 6;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

int zadanie(int t[MAX][MAX]) {
	int max_dlugosc = 1;
	int dlugosc;
	int p;
	int w;
	for(int i=0;i<MAX;i++) {
		p=0;
		while(p<MAX) {
			dlugosc = 1;
			for(int j=p;j<MAX-1;j++) {
				if(t[i][j]==t[i][j+1]) dlugosc++;
				else dlugosc = 1;
				if(dlugosc>max_dlugosc) {
					max_dlugosc = dlugosc;
					w=i;
				}
			}
			p++;
		}
	}
	if(max_dlugosc == 1) {
		cout << "Brak takiego przypadku" << endl;
		return 0;
	}
	cout << "Jest to wiersz ";
	return w;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%15;
	wypisz(t);
	cout << zadanie(t) << endl;
}
