#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
const int N = 10;

struct punkt {
    float x,y;
};

double odleglosc(punkt p) {
    return sqrt(p.x*p.x+p.y*p.y);
}

bool poszukiwania(punkt t[N], double r, punkt p, int poczatek, int liczebnosc, int k) {
    punkt z;
    z.x = p.x/liczebnosc;
    z.y = p.y/liczebnosc;
    if(liczebnosc<k and liczebnosc>0 and odleglosc(z)<=r and liczebnosc%3==0) return true;
    if(poczatek == N) return false;
    punkt x;
    if(liczebnosc!=0) {
        x.x=(p.x+t[poczatek].x);
        x.y=(p.y+t[poczatek].y);
    }
    else x = t[poczatek];
    return(poszukiwania(t,r,x,poczatek+1,liczebnosc+1,k) or poszukiwania(t,r,p,poczatek+1,liczebnosc,k));
}

bool zadanie(punkt t[N], double r, int k) {
    punkt p;
    p.x=p.y=0;
    return poszukiwania(t,r,p,0,0,k);
}

int main() {
	//srand(time(NULL));
	punkt t[N];
	for(int i=0;i<N;i++) {
        t[i].x = rand()%50;
        t[i].y = rand()%50;
        cout << "(" << t[i].x << "," << t[i].y << ")" << endl;
	}
	double r,k;
	cout << "Jaka odleglosc minimalna? ";
	cin >> r;
	cout << "Jakie ograniczenie? ";
	cin >> k;
	if(zadanie(t,r,k)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
