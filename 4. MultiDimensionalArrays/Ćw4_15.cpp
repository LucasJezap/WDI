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

bool cyfra_pierwsza(int a) {
	int x;
	while(a>0) {
		x=a%10;
		if(x==2 or x==3 or x==5 or x==7) return true;
		a/=10;
	}
	return false;
}

bool zadanie(int t[MAX][MAX]) {
	bool wiersz;
	for(int i=0;i<MAX;i++) {
		wiersz = true;
		for(int j=0;j<MAX;j++) {
			if(!cyfra_pierwsza(t[i][j])) wiersz = false;
		}
		if(wiersz) return true;
	}	
	return false;
}


int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) t[i][j] = 10+rand()%20;
	wypisz(t);
	if(zadanie(t)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
