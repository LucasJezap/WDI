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

bool zadanie(int t[MAX][MAX]) {
	bool kolumna,wiersz;
	for(int i=0;i<MAX;i++) {
		kolumna = false;
		wiersz = false;
		for(int j=0;j<MAX;j++) {
			if(t[i][j]==0) wiersz = true;
			if(t[j][i]==0) kolumna = true;
		}
		if(!wiersz or !kolumna) return false;
	}
	return true;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = rand()%10;
	} 
	
	wypisz(t);
	if(zadanie(t)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
