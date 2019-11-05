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

bool zadanie(int t[N],int poczatek) {
    if(poczatek == N-1) return true;
    if(poczatek>N-1) return false;
    for(int i=2;i+poczatek<N;i++) {
        if(pierwsza(i) and t[poczatek]%i==0 and t[poczatek]>i) {
            if(zadanie(t,poczatek+i)) return true;
        }
    }
    return false;
}
int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = 10+rand()%30;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    if(zadanie(t,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
