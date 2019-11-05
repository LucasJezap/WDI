#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

const int N = 10;

struct punkt{
    float x,y;
};

double odleglosc_punktow(punkt a, punkt b) {
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

void zadanie(punkt t[N],int poczatek, punkt s1, punkt s2, int rozmiar1,int rozmiar2, double &min_odleglosc) {
    punkt z1,z2;
    z1.x=s1.x/rozmiar1;
    z1.y=s1.y/rozmiar1;
    z2.x=s2.x/rozmiar2;
    z2.y=s2.y/rozmiar2;
    double odleglosc = odleglosc_punktow(z1,z2);
    if(odleglosc<min_odleglosc and rozmiar1!=0 and rozmiar2!=0) min_odleglosc = odleglosc;
    if(poczatek == N) return;
    punkt p;
    if(rozmiar1==0) {
        p = t[poczatek];
    }
    else {
        p.x = (s1.x+t[poczatek].x);
        p.y = (s1.y+t[poczatek].y);
    }
    zadanie(t,poczatek+1,p,s2,rozmiar1+1,rozmiar2,min_odleglosc);            // dolaczam punkt do 1 podzbioru
    if(rozmiar2==0) {
        p = t[poczatek];
    }
    else {
        p.x = (s2.x+t[poczatek].x);
        p.y = (s2.y+t[poczatek].y);
    }
    zadanie(t,poczatek+1,s1,p,rozmiar1,rozmiar2+1,min_odleglosc);
}

double odleglosc(punkt t[N]) {
    punkt p1,p2;
    p1.x=p2.x=p1.y=p2.y=0;
    double min_odleglosc = 1e6;
    zadanie(t,0,p1,p2,0,0,min_odleglosc);
    return min_odleglosc;
}


int main() {
	srand(time(NULL));
	punkt t[N];
	for(int i=0;i<N;i++) {
		t[i].x = 1+rand()%14;
		t[i].y = 1+rand()%14;
		cout << "(" << t[i].x << "," << t[i].y << ")  ";
	}
	cout << endl << odleglosc(t) << endl;
}
