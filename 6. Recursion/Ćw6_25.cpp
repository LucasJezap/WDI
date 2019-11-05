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

void zadanie(int t[N],int poczatek,int skoki, int &min_skoki) {
    if(poczatek == N-1 and min_skoki>skoki) {min_skoki = skoki;}
    if(poczatek>=N-1) return;
    for(int i=2;i+poczatek<N;i++) {
        if(pierwsza(i) and t[poczatek]%i==0 and t[poczatek]>i) {
            zadanie(t,poczatek+i,skoki+1,min_skoki);
        }
    }
}

int skakanie(int t[N]) {
    int min_skoki =420;
    zadanie(t,0,0,min_skoki);
    if(min_skoki == 420) return -1;
    else return min_skoki;
}


int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = 10+rand()%30;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    cout << skakanie(t) << endl;
}
