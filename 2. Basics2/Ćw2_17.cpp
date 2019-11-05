#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Prosze wpisac liczbe naturalna by sprawdzic czy jest ona liczba Armstronga: " << endl;
	cin >> n;
	int i=1; // i - liczba cyfr
	int x=n;
	int y=n;
	while(x>=10)
	{
		x/=10;
		i++;
	}
	//cout << i << endl;
	int wynik=0;
	int mnoznik=1;
	int z=1;
	while(n>0)
	{
		int a = n%10;
		while(z<=i)
		{
			mnoznik*=a;
			z++;
		}
		
		wynik+=mnoznik;
		mnoznik=1;
		z=1;
		n/=10;
	}
 	
 	if(wynik == y )
	cout << "Liczba " << y << " jest liczba Armstronga" << endl;
	else 
	cout << "Liczba " << y << " nie jest liczba Armstronga" << endl;
	
	
	
	system("pause");
	return 0;
}
