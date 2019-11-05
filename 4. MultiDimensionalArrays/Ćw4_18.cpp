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
	int max_suma = 0;
	int suma_w,suma_k;
	int dlugosc,p;
	int w,k;
	for(int i=0;i<MAX;i++) {
		p=0;
		while(p<MAX) {
			suma_w=0;
			suma_k=0;
			for(int j=p;j<MAX;j++) {
				suma_w+=t[i][j];
				suma_k+=t[j][i]; 
				if(suma_w>max_suma) { max_suma = suma_w, w=i; } 
				if(suma_k>max_suma) { max_suma = suma_k, k=i; } 
			}
			p++;
		}
	}
	cout << "Wiersz " << w << " lub kolumna " << k << endl;
	return max_suma;
}


int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = rand()%30-rand()%30;
	wypisz(t);
	cout << zadanie(t) << endl;
}
