#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 8;

void zadanie(int t[N],int suma_el,int suma_in,int poczatek,int liczebnosc,int &min_liczebnosc, int &szukana_suma) {
    if(suma_el == suma_in and liczebnosc<min_liczebnosc and liczebnosc>0) {min_liczebnosc = liczebnosc; szukana_suma = suma_el;}
    if(poczatek == N)  return;
    if(poczatek<N) {
        zadanie(t,suma_el+t[poczatek],suma_in+poczatek,poczatek+1,liczebnosc+1,min_liczebnosc,szukana_suma);
        zadanie(t,suma_el,suma_in,poczatek+1,liczebnosc,min_liczebnosc,szukana_suma);
    }
}

int poszukiwania(int t[N]) {
    int szukana_suma = 0;
    int min_liczebnosc = N+1;
    zadanie(t,0,0,0,0,min_liczebnosc,szukana_suma);
    return szukana_suma;
}

int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = rand()%10;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    cout << poszukiwania(t) << endl;

}
