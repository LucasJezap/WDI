#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

const int MAX = 4;

bool zlozona(int n) {
	if(n==1) return false;
	if(n==2 or n==3) return false;
	if(n%2==0 or n%3==0) return true;
	int b=5;
	while(b<=sqrt(n)) {
		if(n%b==0) return true;
		b+=2;
		if(n%b==0) return true;
		b+=4;
	}
	return false;
}

void wypisz3d(int tab[MAX][MAX][MAX]) {
	for(int k=0;k<MAX;k++) {
		for(int i=0;i<MAX;i++) {
			for(int j=0;j<MAX;j++) 
				cout << setw(4) << tab[k][i][j] << "  ";	
			cout << endl;
		}
		cout << endl << endl;
	}
}
int ile_zlozonych(int t[MAX][MAX][MAX],int w,int k,int poziom) {
	int ilosc = 0;
	for(int i=w-1;i<w+2;i++) {
		for(int j=k-1;j<k+2;j++) {
			if(zlozona(t[poziom][i][j])) ilosc++;
		}
	}
	if(zlozona(t[poziom][w][k])) ilosc--;
	return ilosc;
}

int sasiedzi(int t[MAX][MAX][MAX], int poziom) {
	int ilosc = 0;
	for(int i=1;i<MAX-1;i++) {
		for(int j=1;j<MAX-1;j++) {
			if(ile_zlozonych(t,i,j,poziom)>5) ilosc++;
		}
	}
	return ilosc;
}

bool trzy_wymiary(int t[MAX][MAX][MAX]) {
	int x = sasiedzi(t,0);
	cout << x << endl;
	for(int k=1;k<MAX;k++) {
		if(sasiedzi(t,k)!=x) return false;
	}
	return true;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) 
			for(int k=0;k<MAX;k++) t[i][j][k] = 1+rand()%10;
			
	wypisz3d(t);
	if(trzy_wymiary(t)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
