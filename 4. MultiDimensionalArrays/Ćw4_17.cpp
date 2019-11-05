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

int suma(int t[MAX][MAX],int w,int k) {
	int ile = 0;
	if(w-1>=0 and k-1>=0) ile+=t[w-1][k-1];
	if(w-1>=0 ) ile+=t[w-1][k];
	if(w-1>=0 and k+1<MAX) ile+=t[w-1][k+1];
	if(k-1>=0) ile+=t[w][k-1];
	if(k+1<MAX) ile+=t[w][k+1];
	if(w+1<MAX and k-1>=0) ile+=t[w+1][k-1]; 
	if(w+1<MAX) ile+=t[w+1][k];
	if(w+1<MAX and k+1<MAX) ile+=t[w+1][k+1]; 
	return ile;
}


void zadanie(int t[MAX][MAX],int &w,int &k) {
	int max_suma = 0;
	int sumka;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			sumka = suma(t,i,j);
			if(sumka>max_suma) {
				max_suma = sumka;
				w = i;
				k = j;
			} 
		}
	}
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%99;
	wypisz(t);
	int w,k;
	zadanie(t,w,k);
	cout << "(" << w << "," << k << ")" << endl;
	
}
