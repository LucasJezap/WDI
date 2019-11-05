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

bool warunek(int a){
	while(a>0) {
		if((a%10)%2==0) return true;
		a/=10;
	}
	return false;
}

bool zadanie(int t[MAX][MAX]) {
	bool parzysta;
	for(int i=0;i<MAX;i++) {
		parzysta = true;
		for(int j=0;j<MAX;j++) {
			if(!warunek(t[i][j])) parzysta = false;
		}
		if(parzysta) {
			cout << "To wiersz " << i << endl;
			return true;
		}
	}
	return false;
}

int main() {
	srand(time(NULL));
	int t[MAX][MAX];
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) t[i][j] = 1+rand()%25;
	} 
	wypisz(t);
	if(zadanie(t)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
