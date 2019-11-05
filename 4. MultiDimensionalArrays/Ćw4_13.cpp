#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

const int MAX = 5;

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

void wypisz(int tab[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool komplementarne(int t[MAX][MAX],int a) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) if(pierwsza(a+t[i][j])) return true;
	}
	return false;
}

void zadanie(int t[MAX][MAX],int t2[MAX][MAX]) {
	for(int i=0;i<MAX;i++) {
		for(int j=0;j<MAX;j++) {
			if(!komplementarne(t,t[i][j])) t2[i][j] = 0;
			else t2[i][j] = t[i][j];
		}
	}
}

int f(int n) {
    if(n<2) return n;
    return abs(n%2-f(n/2));
}

int main() {
    for(int i=1;i<10;i++) {
        cout << i << "->" << f(i) << endl;
    }
    cout << endl << endl;
	srand(time(NULL));
	int t[MAX][MAX];
	int t2[MAX][MAX];
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++) t[i][j] = 100+rand()%20;
	wypisz(t);
	zadanie(t,t2);
	cout << endl << endl;
	wypisz(t2);
}
