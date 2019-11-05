#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 5;
const int MAX2 = MAX*MAX;

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool singleton(int a,int t1[MAX][MAX]) {
	int ilosc = 0;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			if(t1[i][j] == a) ilosc++;
		}
	}
	if(ilosc>1) return false;
	return true;	
}

void zadanie(int t1[MAX][MAX],int t2[MAX2]) {
	int pom;
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			if(singleton(t1[i][j],t1)) {
				pom = 0;
				while(t1[i][j]>t2[pom] and pom<MAX2) pom++;
				for(int k=0;k<pom-1;k++) t2[k]=t2[k+1];
				t2[pom-1] = t1[i][j];
			}
		}
	}
}


int main() {
	srand(time(NULL));
	int t1[MAX][MAX];
	int t2[MAX2];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t1[i][j] = 1+rand()%100;
	} 
	for(int i=0;i<MAX2;i++) t2[i] = 0;
	wypisz(t1);
	zadanie(t1,t2);
	for(int i=0;i<MAX2;i++) cout << t2[i] << " ";
	cout << endl;
}
