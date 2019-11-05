#include <iostream>
#include <math.h> 
using namespace std;

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

void wczytywanie(ulamek &a) {
	cout << "Prosze podac licznik ";
	cin >> a.l;
	cout << "Prosze podac mianownik(wiekszy od 0) ";
	cin >> a.m;
}
void skracanie(ulamek &a) {
	if(a.l<0 and a.m<0) { a.l=abs(a.l);a.m=abs(a.m); }
	if(a.m<0 and a.l>0) { a.l*=-1; a.m=abs(a.m); }
	int x = nwd(abs(a.l),abs(a.m));
	a.l/=x;
	a.m/=x;
}
void wypisywanie(ulamek a) {
	skracanie(a);
	if(a.l%a.m==0) cout << a.l/a.m << endl;
	else cout <<  a.l << "/" << a.m << endl;
}
void dodawanie(ulamek a, ulamek b) {
	ulamek c;
	c.l = a.l*b.m+b.l*a.m;
	c.m = a.m*b.m;
	skracanie(c);
	wypisywanie(c);
}
void odejmowanie(ulamek a, ulamek b) {
	ulamek c;
	c.l = a.l*b.m-b.l*a.m;
	c.m = a.m*b.m;
	skracanie(c);
	wypisywanie(c);
}
void mnozenie(ulamek a,ulamek b) {
	ulamek c;
	c.l = a.l*b.l;
	c.m = a.m*b.m;
	skracanie(c);
	wypisywanie(c);
}
void dzielenie(ulamek a,ulamek b) {
	ulamek c;
	c.l = a.l*b.m;
	c.m = a.m*b.l;
	skracanie(c);
	wypisywanie(c);
}
void potegowanie(ulamek a,int potega) {
	int x = a.l;
	int y = a.m;
	for(int i=1;i<potega;i++) {
		a.l*=x;
		a.m*=y;
		skracanie(a);
	}
	wypisywanie(a);
}



int main() {
	ulamek a,b;
	wczytywanie(a);
	wypisywanie(a);
	wczytywanie(b);
	wypisywanie(b);
	skracanie(a);
	skracanie(b);
	dodawanie(a,b);
	odejmowanie(a,b);
	mnozenie(a,b);
	dzielenie(a,b);
	potegowanie(a,3);
	potegowanie(b,3);
}
