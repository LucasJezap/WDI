#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 8;

void nka(int t[N], int n, int suma, int poczatek, int &licznik, string a) {
    if(suma == 0 and n==0) {licznik++, cout << a << endl; return;}
    if(poczatek == N or suma<0) return;
    nka(t,n-1,suma-t[poczatek],poczatek+1,licznik,a+"  " + to_string(t[poczatek]));
    nka(t,n,suma,poczatek+1,licznik,a);
}

int zadanie(int t[N], int n, int suma) {
    int licznik = 0;
    nka(t,n,suma,0,licznik,"");
    return licznik;
}

int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = 1+ rand()%15;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    int n,suma;
    cout << "Ile elementow? ";
    cin >> n;
    cout << "Jaka suma? ";
    cin >> suma;
    cout << "Takich sum jest " <<  zadanie(t,n,suma) << endl;
}
