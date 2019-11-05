#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int N = 8;

void wypisz(int tab[8][8]) {
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool mozliwy_ruch(int a,int b) {
    int ostatnia = a%10;
    int pierwsza;
    while(b>0) { pierwsza = b%10; b/=10; }
    if(ostatnia<pierwsza) return true;
    else return false;
}

bool prawy_dolny(int t[N][N],int w,int k) {
    if(w==7 and k==7) return true;
    if(w+1<8 and k+1<8 and prawy_dolny(t,w+1,k+1) and mozliwy_ruch(t[w][k],t[w+1][k+1])) return true;     // na ukos
    if(w+1<8 and prawy_dolny(t,w+1,k) and mozliwy_ruch(t[w][k],t[w+1][k])) return true;                // w dol
    if(k+1<8 and prawy_dolny(t,w,k+1) and mozliwy_ruch(t[w][k],t[w][k+1])) return true;                // w prawo
    return false;
}



int main() {
    srand(time(NULL));
    int t[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) t[i][j] = 1+rand()%99;
    wypisz(t);
    if(prawy_dolny(t,0,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
