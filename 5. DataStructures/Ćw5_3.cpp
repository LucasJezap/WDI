#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 15;

struct hetman {
	int w; // wiersz
	int k; // kolumna
};
hetman tab[N];

bool szachowanko(hetman tab[N]) {
	for(int i=0;i<N;i++) {
		for(int j=i+1;j<N;j++) {
			if(tab[i].w == tab[j].w or tab[i].k == tab[j].k or abs(tab[i].w - tab[i].k) == abs(tab[j].k-tab[j].w)) {
				cout << endl << i << " " << j << endl;
				return false;
			}
		}
	}
	return true;
}


int main() {
	srand(time(NULL));
	for(int i=0;i<N;i++) {
		int x=rand()%100;
		tab[i].w = x;
		x=rand()%100;
		tab[i].k = x;
		cout << "(" << tab[i].w << "," << tab[i].k << ")" << endl;
	}
	if(szachowanko(tab)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
