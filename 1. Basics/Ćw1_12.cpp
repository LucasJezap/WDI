#include <iostream>

using namespace std;

int podzielniki(int n)
{
	int wynik=0;
	for(int i=1;2*i<=n;i++)
	{
		if(n%i == 0)
		wynik+=i;
	}
	return wynik;
}


int main()
{
	cout << "Liczby doskonale mniejsze od miliona to: ";
	for(int i=1;i<=1000000;i++)
	{
		if(podzielniki(i) == i)
		cout << i << ",";
	}
	system("pause");
	return 0;
}
