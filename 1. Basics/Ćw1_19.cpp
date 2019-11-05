#include <iostream>

using namespace std;



int main()
{
	double silnia=1;
	double liczba=1;
	double e=0;
	int i=1;
	while(liczba!=0)
	{
		liczba=1/silnia;
		silnia=silnia*i;
		i++;
		e=e+liczba;
	}
	cout << e*1000 << endl;
	
	
	cout << "Wartoscia liczby e jest: " << e << endl;
	
	system("pause");
	return 0;
}
