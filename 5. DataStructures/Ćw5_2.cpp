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

void skracanie(ulamek &a) {
	if(a.l<0 and a.m<0) { a.l=abs(a.l);a.m=abs(a.m); }
	if(a.m<0 and a.l>0) { a.l*=-1; a.m=abs(a.m); }
	int x = nwd(abs(a.l),abs(a.m));
	a.l/=x;
	a.m/=x;
}
void wypisywanie(ulamek a) {
	skracanie(a);
	if(a.l%a.m==0) cout << a.l/a.m;
	else cout <<  a.l << "/" << a.m;
}
void odejmowanie(ulamek a, ulamek b,ulamek &c) {
	
	c.l = a.l*b.m-b.l*a.m;
	c.m = a.m*b.m;
	skracanie(c);
	//wypisywanie(c);
}
void mnozenie(ulamek a,ulamek b,ulamek &c) {

	c.l = a.l*b.l;
	c.m = a.m*b.m;
	skracanie(c);
    //wypisywanie(c);
}
void dzielenie(ulamek a,ulamek b) {
	ulamek c;
	c.l = a.l*b.m;
	c.m = a.m*b.l;
	skracanie(c);
	wypisywanie(c);
}


int main() {
	ulamek tab[2][3];
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) {
			cout << "Licznik ";
			cin >> tab[i][j].l;
			cout << "Mianownik ";
			cin >> tab[i][j].m;
		}
	}
	cout << endl;
	wypisywanie(tab[0][0]);
	cout << "x +";
	wypisywanie(tab[0][1]);
	cout << "y =";
	wypisywanie(tab[0][2]);
	cout << endl;
	wypisywanie(tab[1][0]);
	cout << "x +";
	wypisywanie(tab[1][1]);
	cout << "y =";
	wypisywanie(tab[1][2]);
	cout << endl;
	ulamek a,b;
	ulamek W,Wx,Wy;
	mnozenie(tab[0][0],tab[1][1],a);
	mnozenie(tab[0][1],tab[1][0],b);
	odejmowanie(a,b,W);
	mnozenie(tab[0][2],tab[1][1],a);
	mnozenie(tab[1][2],tab[0][1],b);
	odejmowanie(a,b,Wx);
	mnozenie(tab[0][0],tab[1][2],a);
	mnozenie(tab[0][2],tab[1][0],b);
	odejmowanie(a,b,Wy);
	cout << endl << "x=";
	dzielenie(Wx,W);
	cout << endl << "y=";
	dzielenie(Wy,W);
	
		
}
