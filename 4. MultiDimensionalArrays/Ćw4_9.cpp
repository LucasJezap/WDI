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

void zadanie(int t[MAX][MAX],int k) {
	int szerokosc = 3;
	while(szerokosc<MAX) {
		for(int i=0;i<=MAX-szerokosc;i++) {
			for(int j=0;j<=MAX-szerokosc;j++) {
				if(t[i][j]*t[i+szerokosc-1][j]*t[i][j+szerokosc-1]*t[i+szerokosc-1][j+szerokosc-1]==k)  {
					cout << "Szerokosc: " << szerokosc << " (" << (2*i+szerokosc-1)/2 << "," << (2*j+szerokosc-1)/2 << ")" << endl;
				}
			}
		}
		szerokosc+=2;
	}
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%10;
	} 
	
	wypisz(t);
	zadanie(t,20);
}
