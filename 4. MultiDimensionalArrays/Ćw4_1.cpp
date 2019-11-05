#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 9;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

void spirala(int t[MAX][MAX]) {
	int licznik = 1;
	int p=0,k=MAX;
	while(p<k){
		for(int i=p;i<k;i++) t[p][i] = licznik++;
		for(int i=p+1;i<k;i++) t[i][k-1] = licznik++;
		for(int i=k-2;i>=p;i--) t[k-1][i] = licznik++;
		for(int i=k-2;i>=p+1;i--) t[i][p] = licznik++;
		p++;
		k--;
	}
}

int main() {
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 0;
	} 
	spirala(t);
	wypisz(t);
}
