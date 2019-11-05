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

int sumuj(int t[MAX][MAX],int w,int k) {
	int suma = 0;
	for(int i=0;i<MAX;i++) {
		suma+=t[w][i];
		suma+=t[i][k];
	}
	suma-=(2*t[w][k]);
	return suma;
}

void zadanie(int t[MAX][MAX],int &w1,int &k1,int &w2,int &k2) {
	int max_suma1 = 0;
	int max_suma2 = 0;
	int x;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			x=sumuj(t,i,j);
			if(x>max_suma1) {
				max_suma1 = x;
				w1 = i;
				k1 = j;
			}
			if(x<max_suma1 and x>max_suma2) {
				max_suma2 = x;
				w2 = i;
				k2 = j;
			}	
		}
	}
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%15;
	wypisz(t);
	int w1,w2,k1,k2;
	zadanie(t,w1,k1,w2,k2);
	cout << "(" << w1 << "," << k1 << ")" << endl;
	cout << "(" << w2 << "," << k2 << ")" << endl;
	
}
