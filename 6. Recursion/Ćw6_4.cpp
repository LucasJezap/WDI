#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

const int N = 8;

bool pierwsza(int n) {
	if(n==1) return false;
	if(n==2 or n==3) return true;
	if(n%2==0 or n%3==0) return false;
	int b=5;
	while(b<=sqrt(n)) {
		if(n%b==0) return false;
		b+=2;
		if(n%b==0) return false;
		b+=4;
	}
	return true;
}

int waga_liczby(int a) {
    int ilosc = 0;
    for(int i=2;a!=1;i++) {
        if(a%i==0) ilosc++;
        while(a%i==0) a/=i;
    }
    return ilosc;
}

void zamiana(int t[N],int waga[N]) {
    for(int i=0;i<N;i++) waga[i] = waga_liczby(t[i]);
}

bool zadanie(int waga[N],int poczatek,int s1,int s2,int s3) {
    if(poczatek == N) return(s3==s2==s1);
    return(zadanie(waga,poczatek+1,s1+waga[poczatek],s2,s3) or zadanie(waga,poczatek+1,s1,s2+waga[poczatek],s3) or zadanie(waga,poczatek+1,s1,s2,s3+waga[poczatek]));
}

bool poszukiwania(int waga[N]) {
    int suma_wag = 0;
    for(int i=0;i<N;i++) suma_wag+=waga[i];
    if(suma_wag%3!=0) return false;             //jezeli suma wag jest niepodzielna przez 3 to nie da sie podzielic na 3 podzbiory o rownych wagach
    return zadanie(waga,0,0,0,0);
}

int main() {
    srand(time(NULL));
    int t[N];
    int waga[N];
    for(int i=0;i<N;i++) { t[i] = 1+rand()%25; waga[i] = 0; }
    for(int i=0;i<N;i++) cout << t[i] << " ";                       //oryginalna tablica
    cout << endl;
    zamiana(t,waga);
    for(int i=0;i<N;i++) cout << waga[i] << " ";                    //tablica z wagami;
    cout << endl;
    if(poszukiwania(waga)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
