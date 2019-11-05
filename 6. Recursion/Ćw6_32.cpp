#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
const int N = 10;

struct punkt {
    float x,y,z;
};

double odleglosc(punkt p) {
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

bool poszukiwania(punkt t[N], double r, punkt p, int poczatek, int liczebnosc) {
    punkt z;
    z.x=p.x/liczebnosc;
    z.y=p.y/liczebnosc;
    z.z=p.z/liczebnosc;
    if(liczebnosc>2 and odleglosc(z)<=r) return true;
    if(poczatek == N) return false;
    punkt x;
    if(liczebnosc!=0) {
        x.x=(p.x+t[poczatek].x);
        x.y=(p.y+t[poczatek].y);
        x.z=(p.z+t[poczatek].z);
    }
    else x = t[poczatek];
    return(poszukiwania(t,r,x,poczatek+1,liczebnosc+1) or poszukiwania(t,r,p,poczatek+1,liczebnosc));
}

bool zadanie(punkt t[N], double r) {
    punkt p;
    p.x=p.y=p.z=0;
    return poszukiwania(t,r,p,0,0);
}

int main() {
	//srand(time(NULL));
	punkt t[N];
	for(int i=0;i<N;i++) {
        t[i].x = rand()%50;
        t[i].y = rand()%50;
        t[i].z = rand()%50;
        cout << "(" << t[i].x << "," << t[i].y << "," << t[i].z << ")" << endl;
	}
	double r;
	cout << "Jaka odleglosc minimalna? ";
	cin >> r;
	if(zadanie(t,r)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
