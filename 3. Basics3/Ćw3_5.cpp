#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace ::std;

int main(){
    int prec;
    cin >> prec;
	// wynikowa liczba, przy za³o¿eniu ¿e po pierwszym elemencie ustawiamy przecinek
	// tj. wynikowo bêdzie zawieraæ [2,7,1,...]
    int e[prec+1]; 
    int part[prec+1]; // kolejny sk³adnik szeregu
    for(int i = 0; i <= prec; ++i){ // zerowanie
        e[i] = part[i] = 0;
    }
    e[0] = 1;
    part[0] = 1;

    int fact = 1; // liczba w mianowniku

    int pos = 0;
    while(pos <= prec){
        // szukanie pierwszej niezerowej cyfry w zapisie u³amka
        while(!part[pos]) ++pos; 

        // dzielenie pisemne
        int n = 0;
        for(int i = pos; i <= prec; ++i){
            n = n * 10 + part[i];
            part[i] = n / fact;
            n = n%fact;
        }

        // dodawanie do wyniku
        int overflow = 0;
        for(int i = prec; i >= 0; --i){
            e[i] = e[i] + part[i] + overflow;
            overflow = e[i] / 10;
            e[i] = e[i] % 10;
        }

        ++fact;
    }

    // wypisanie e
    cout << e[0] << ".";
    for(int i = 1; i <= prec; ++i){
        cout << e[i];
    }
    cout << endl;

}

