#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x,y;
	double dokladnosc;
	cout << "Pierwiastek kwadratowy z jakiej liczby chcesz znalezc? " << endl;
	cin >> x;
	cout << "Z jaka dokladnoscia?" << endl;
	cin >> dokladnosc;
	y=x/2;
	
	while(abs(x/y-y)>dokladnosc)
	{
		y=(x/y+y)/2;
		
	}
	cout << "Wartosc ta wynosi: ";
	cout << y;
	system("pause");
	return 0;
	
}
