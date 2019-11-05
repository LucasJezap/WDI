#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 3;
const int MAX2 = 5;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

void wypisz2(int tab[MAX2][MAX2]) {
	for(int i=0;i<MAX2;i++) {
		for(int j=0;j<MAX2;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool zgodne(int a, int b) {
	int ilosc1 = 0,ilosc2 = 0;
	while(a>0){
		if(a%2==1) ilosc1++;
		a/=2;
	}
	while(b>0){
		if(b%2==1) ilosc2++;
		b/=2;
	}
	return (ilosc1==ilosc2);
}

bool poszukiwania(int tab3[MAX2][MAX2],int w,int k) {
	for(int i=0;i<MAX2;i++) {
		for(int j=0;j<MAX2;j++) if(zgodne(tab3[w][k],tab3[i][j]) and (i!=w or j!=k)) return true;
	}
	return false;	
}

bool ulozenie(int tab1[MAX][MAX],int tab2[MAX2][MAX2],int w,int k) {
	int tab3[MAX2][MAX2];
	for(int i=0;i<MAX2;i++) 
		for(int j=0;j<MAX2;j++) tab3[i][j] = tab2[i][j];
	int p=0,z=0;
	for(int i=w;i<w+MAX;i++) {
		for(int j=k;j<k+MAX;j++) tab3[i][j] = tab1[p][z++];
		p++,z=0;
	}                                                               // do tego momentu podmiana tablicy
	int ilosc = 0;
	for(int i=0;i<MAX2;i++) {
		for(int j=0;j<MAX2;j++) if(poszukiwania(tab3,i,j)) ilosc++;
	}
	if(1.0*ilosc/(MAX2*MAX2)>0.33) return true;
	else return false;
}

bool zadanie(int tab1[MAX][MAX], int tab2[MAX2][MAX2]) {
	for(int i=0;i<=MAX2-MAX;i++) {
		for(int j=0;j<=MAX2-MAX;j++) {
			if(ulozenie(tab1,tab2,i,j)) {
				cout << "(" << i << "," << j << ")" << endl;
				return true;
			}
		}
	}
	return false;
}


int main() {
	srand(time(NULL));
	int tab1[MAX][MAX];
	int tab2[MAX2][MAX2];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) tab1[i][j] = 1+rand()%100;
	for(int i=0;i<MAX2;i++)
		for(int j=0;j<MAX2;j++) tab2[i][j] = 1+rand()%100;
	wypisz(tab1);
	cout << endl;
	wypisz2(tab2);
	cout << endl;
	if(zadanie(tab1,tab2)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
