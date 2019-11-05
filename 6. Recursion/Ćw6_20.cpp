#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void wypisz(int tab[8][8]) {
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool poszukiwania(int t[8][8], int suma, bool kolumny[8],int poczatek) {
    if(suma==0) return true;
    if(poczatek == 8 or suma <0) return false;
    for(int i=0;i<8;i++) {
        if(!kolumny[i]) {
            kolumny[i] = true;
            if(poszukiwania(t,suma-t[poczatek][i],kolumny,poczatek+1)) { cout << t[poczatek][i] << " + "; return true; }
            kolumny[i] = false;
        }
        if(poszukiwania(t,suma,kolumny,poczatek+1)) return true;
    }
    return false;
}

bool zadanie(int t[8][8],int suma) {
    bool kolumny[8];                            // czy kolumna jest zajeta
    for(int i=0;i<8;i++) kolumny[i] = false;
    return poszukiwania(t,suma,kolumny,0);
}



int main() {
    srand(time(NULL));
    int t[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++) t[i][j] = 1+rand()%15;
    wypisz(t);
    if(zadanie(t,45)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
