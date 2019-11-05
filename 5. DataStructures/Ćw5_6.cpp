#include <iostream>
#include <math.h>
using namespace std;

struct zespolona {
	double re,im;
};
void wczytywanie(zespolona &a) {
	cout << "Prosze podac czesc rzeczywista ";
	cin >> a.re;
	cout << "Prosze podac czesc urojona ";
	cin >> a.im;
}
void wypisywanie(zespolona a) {
	if(a.re == 0) cout << a.im << "i" << endl;
	if(a.im == 0) cout << a.re << endl;
	if(a.im > 0 and a.re!=0) cout << a.re << "+" << a.im << "i" << endl;
	if(a.im < 0 and a.re!=0) cout << a.re << a.im << "i" << endl;
}
void dodawanie(zespolona a,zespolona b) {
	zespolona c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	wypisywanie(c);
}
void odejmowanie(zespolona a,zespolona b) {
	zespolona c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	wypisywanie(c);
}
void mnozenie(zespolona a, zespolona b) {
	zespolona c;
	c.re = a.re*b.re - a.im*b.im;
	c.im = a.re*b.im + a.im*b.re;
	wypisywanie(c);
}
void dzielenie(zespolona a, zespolona b) {
	zespolona c;
	c.re = (a.re*b.re + a.im*b.im)/(b.re*b.re+b.im*b.im);
	c.im = (a.im*b.re-a.re*b.im)/(b.re*b.re+b.im*b.im);
	wypisywanie(c);
}
void potegowanie(zespolona a, int potega) {
	zespolona tmp;
	zespolona pomocna;
	tmp.re = a.re;
	tmp.im = a.im;
	for(int i=1;i<potega;i++) {
		pomocna.re = a.re;
		pomocna.im = a.im;
		a.re = tmp.re*pomocna.re - pomocna.im*tmp.im;
		a.im = tmp.re*pomocna.im + tmp.im*pomocna.re;
	}
	wypisywanie(a);
}

int main() {
	zespolona a;
}
