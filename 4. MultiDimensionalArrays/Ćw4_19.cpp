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

int zadanie(int t[MAX][MAX],int wartosc) {
	int ilosc = 0;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			if(i+1<MAX and j+2<MAX and t[i][j]*t[i+1][j+2]==wartosc) ilosc++;
			if(i+1<MAX and j-2>=0 and t[i][j]*t[i+1][j-2]==wartosc) ilosc++;
			if(i+2<MAX and j+1<MAX and t[i][j]*t[i+2][j+1]==wartosc) ilosc++;
			if(i+2<MAX and j-1<MAX and t[i][j]*t[i+2][j-1]==wartosc) ilosc++;
		}
	}
	return ilosc;
}



int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%15;
	wypisz(t);
	cout << zadanie(t,20) << endl;
}
