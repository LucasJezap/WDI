#include <iostream>
#include <math.h>
using namespace std;

struct zespolona {
	double re,im;
};
void wypisywanie(zespolona a) {
	cout << "(";
	if(a.re == 0) cout << a.im << "i";
	if(a.im == 0) cout << a.re;
	if(a.im > 0 and a.re!=0) cout << a.re << "+" << a.im << "i";
	if(a.im < 0 and a.re!=0) cout << a.re << a.im << "i";
	cout << ")";
}
void wczytywanie(zespolona &a) {
	cout << "Prosze podac czesc rzeczywista ";
	cin >> a.re;
	cout << "Prosze podac czesc urojona ";
	cin >> a.im;
}
void odejmowanie(zespolona a,zespolona b,zespolona &c) {
	c.re = a.re - b.re;
	c.im = a.im - b.im;
}
void mnozenie(zespolona a, zespolona b,zespolona &c) {
	c.re = a.re*b.re - a.im*b.im;
	c.im = a.re*b.im + a.im*b.re;
}
void dzielenie(zespolona a, zespolona b) {
	zespolona c;
	c.re = (a.re*b.re + a.im*b.im)/(b.re*b.re+b.im*b.im);
	c.im = (a.im*b.re-a.re*b.im)/(b.re*b.re+b.im*b.im);
	wypisywanie(c);
}
int main() {
	zespolona tab[2][3];
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) wczytywanie(tab[i][j]);
	}
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
	zespolona W,Wx,Wy;
	zespolona a,b;
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
