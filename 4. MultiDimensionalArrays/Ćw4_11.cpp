#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int czynnik[10];

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

int binar(int a) {
	int tab[10];
	int liczba = 0;
	for(int i=0;i<10;i++) tab[i] = 0;
	while(a>0) {
		tab[a%10] = 1;
		a/=10;
	}
	for(int i=0;i<10;i++){
		if(tab[i]==1) liczba+=czynnik[i];
	}
	return liczba;
}

void zamiana(int t[MAX][MAX],int t2[MAX][MAX]) {
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t2[i][j] = binar(t[i][j]);
}

bool sasiadki(int t2[MAX][MAX],int w,int k) {
	if(w-1>=0 and k-1>=0 and t2[w-1][k-1]!=t2[w][k]) return false;
	if(w-1>=0 and t2[w-1][k]!=t2[w][k]) return false;
	if(w-1>=0 and k+1<MAX and t2[w-1][k+1]!=t2[w][k]) return false;
	if(k-1>=0 and t2[w][k-1]!=t2[w][k]) return false;
	if(k+1<MAX and t2[w][k+1]!=t2[w][k]) return false;
	if(w+1<MAX and k-1>=0 and t2[w+1][k-1]!=t2[w][k]) return false;
	if(w+1<MAX and t2[w+1][k]!=t2[w][k]) return false;
	if(w+1<MAX and k+1<MAX and t2[w+1][k+1]!=t2[w][k]) return false;
	return true;
}


int zadanie(int t2[MAX][MAX]) {
	int ilosc = 0;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			if(sasiadki(t2,i,j)) ilosc++;
		}
	}
	return ilosc;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	int t2[MAX][MAX];
	czynnik[0] = 1;
	for(int i=1;i<10;i++) czynnik[i]=czynnik[i-1]*2;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = rand()%10;
	} 
	wypisz(t);
	zamiana(t,t2);
	cout << endl << endl;
	wypisz(t2);
	cout << zadanie(t2) << endl;
}
