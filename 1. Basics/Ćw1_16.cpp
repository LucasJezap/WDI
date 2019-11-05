#include <iostream>

using namespace std;

int main()
{
	int wynik=0;
	int x=0;
	for(int i=2;i<=10000;i++)
	{
		int ilosc=0;
		int n=i;
		while(n!=1)
		{
			n=(n%2)*(3*n+1)+(1-(n%2))*(n/2);
			ilosc++;
		}
		if(ilosc>wynik)
		{
		wynik=ilosc;
		x=i;
		}
	}
	cout << "Liczba poczatkowa, dzieki ktorej osiagniecie 1 wymaga najwiecej krokow to " << x << endl;
	cout << "Ilosc krokow to " << wynik << endl;
	
	
	
	
	system("pause");
	return 0;
}
