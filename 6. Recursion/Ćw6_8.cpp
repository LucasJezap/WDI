#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int N = 8;

void wypisz(int tab[8][8]) {
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

void poszukiwania(int t[N][N],int wiersz,int kolumna,int suma,int &min_suma) {
    suma+=t[wiersz][kolumna];
    if(wiersz == N-1 and min_suma>suma) min_suma = suma;
    if(wiersz<N-1) {
        if(kolumna+1<N) poszukiwania(t,wiersz+1,kolumna+1,suma,min_suma);
        if(kolumna-1>=0) poszukiwania(t,wiersz+1,kolumna-1,suma,min_suma);
        poszukiwania(t,wiersz+1,kolumna,suma,min_suma);
    }
}

int zadanie(int t[N][N],int k) {
    int min_suma = 1e6;
    poszukiwania(t,0,k,0,min_suma);
    return min_suma;
}


int main() {
    srand(time(NULL));
    int t[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) t[i][j] = 1+rand()%15;
    wypisz(t);
    cout << zadanie(t,3) << endl;
}
