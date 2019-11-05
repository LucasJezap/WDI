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

bool pociecie(int t[N],int liczba,int dlugosc,int poczatek) {
    if(pierwsza(liczba) and dlugosc<30) { liczba = 0; dlugosc = 0;}
    if(dlugosc>30) return false;
    if(poczatek == N and dlugosc == 0) return true;
    if(t[poczatek]==1) return(pociecie(t,liczba*2+1,dlugosc+1,poczatek+1));
    else return(pociecie(t,liczba*2,dlugosc+1,poczatek+1));
}

int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = rand()%2;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    if(pociecie(t,0,0,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
