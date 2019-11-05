#include <iostream>
#include <math.h> 
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 20;

struct ulamek {
	int l; // licznik
	int m; // mianownik > 0
};
int nwd(int a,int b) {
	while(a!=b) {
		if (a>b) a=a-b;
		else b=b-a;
	}
	return a;
}
void skracanie(ulamek &a) {
	if(a.l == 0 or a.m ==0) return;
	if(a.l<0 and a.m<0) { a.l=abs(a.l);a.m=abs(a.m); }
	if(a.m<0 and a.l>0) { a.l*=-1; a.m=abs(a.m); }
	int x = nwd(abs(a.l),abs(a.m));
	a.l/=x;
	a.m/=x;
}
void odejmowanie(ulamek a, ulamek b,ulamek &c) {
	skracanie(a);
	skracanie(b);
	c.l = a.l*b.m-b.l*a.m;
	c.m = a.m*b.m;
	skracanie(c);
}
void dzielenie(ulamek a,ulamek b,ulamek &c) {
	skracanie(a);
	skracanie(b);
	c.l = a.l*b.m;
	c.m = a.m*b.l;
	skracanie(c);
}
int ile_aryt(ulamek tab[]) {
	ulamek a,b;
	int dlugosc = 2;
	int max_dlugosc = 2;
	
	for(int i=2;i<N;i++) {
		odejmowanie(tab[i],tab[i-1],a);
		odejmowanie(tab[i-1],tab[i-2],b);
		if((a.l==b.l and a.m == b.m) or (a.l==0 and b.l==0)) dlugosc++;
		else dlugosc = 2;
		if(max_dlugosc<dlugosc) max_dlugosc = dlugosc;
	}
	
	if(max_dlugosc == 2) return 0;
	else return max_dlugosc;
}
int ile_geom(ulamek tab[]) {
	ulamek a,b,c;
	int dlugosc = 2;
	int max_dlugosc = 2;
	
	for(int i=2;i<N;i++) {
		dzielenie(tab[i],tab[i-1],a);
		dzielenie(tab[i-1],tab[i-2],b);
		if(a.l == b.l and a.m == b.m) dlugosc++;
		else dlugosc = 2;
		if(max_dlugosc<dlugosc) max_dlugosc = dlugosc;
	}
	if(max_dlugosc == 2) return 0; 
	return max_dlugosc;
}
int czego_wiecej(ulamek tab[]) {
	int LA = ile_aryt(tab);
	int LG = ile_geom(tab);
	if(LA>LG) return 1;
	if(LA<LG) return -1;
	if(LA==LG) return 0;
}

int main() {
	srand(time(NULL));
	ulamek tab[N];
	for(int i=0;i<N;i++) {
		tab[i].l = 1+rand()%5;
		tab[i].m = 1+rand()%5;
		cout << "(" << tab[i].l << "/" << tab[i].m << ")" << endl;
	}
	cout << czego_wiecej(tab) << endl;
}
