#include <iostream>
#include <math.h>
using namespace std;
const double eps =1e-10;
int main()
{
	double a,b,c,d,wynik;
	cout << "Podaj dwie liczby by znalezc ich srednia geometryczno-arytmetyczna: " << endl;
	cin >> a >> b;
	c=2;
	d=1;
	while(abs(c-d)>eps)
	{
		c=sqrt(a*b);
		d=(a+b)/2;
	}
	wynik = (c+d)/2;
	cout << "Wynik to: " << wynik << endl;
	
	system("pause");
	return 0;
	
}
