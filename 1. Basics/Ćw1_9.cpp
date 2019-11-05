#include <iostream>
#include <math.h>
using namespace std;

/*int silnia(int a)
{
	int i=1;
	int wynik=1;
	while(i<=a)
	{
	wynik*=i;
	i++;
	}
return wynik;
}
*/
int main()
{
	double x;
	cout << "Podaj argument x, dla ktorego chcesz policzyc wartosc funkcji cos(x): " << endl;
	cin >> x;
	
	double wynik=1;
	double potega=1;
	int zmiennik=-1;
	double siln = 2;
	int i=1;
	while(i<200)
	{
	potega*=x*x;
	wynik+=zmiennik*(potega)/siln;
	siln=siln*(i+2)*(i+3);
	zmiennik*=-1;
	i+=2;
	}
	cout << "Wynik to " << wynik << endl;
	
	
	system("pause");
	return 0; 
	
}
