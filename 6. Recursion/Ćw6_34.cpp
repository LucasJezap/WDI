#include <iostream>
#include <math.h>
using namespace std;

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

void suma(int pom[20],int p,int poczatek, int iloczyn,int &szukana_suma,int liczebnosc) {
    if(poczatek == p and liczebnosc>0) { szukana_suma+=iloczyn; return; }
    if(poczatek<p) {
        suma(pom,p,poczatek+1,iloczyn*pom[poczatek],szukana_suma,liczebnosc+1);
        suma(pom,p,poczatek+1,iloczyn,szukana_suma,liczebnosc);
    }
}

int zadanie(int a) {
    int pom[20];
    for(int i=0;i<20;i++) pom[i] = 0;
    int p = 0;
    for(int i=2;a!=1;i++) {
        if(a%i==0) pom[p++]=i;
        while(a%i==0) a/=i;
    }
    int szukana_suma = 0;
    suma(pom,p,0,1,szukana_suma,0);
    return szukana_suma;
}

int main() {
    int a;
    cin >> a;
    cout << zadanie(a) << endl;
}
