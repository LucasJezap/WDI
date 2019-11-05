#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "W przedziale od 1 do n program wypisze liczby pierwsze, prosze podac n: " << endl;
	cin >> n;
	int tab[n];
	for(int i=0;i<n;i++)
	{
		tab[i] = true;
	}
	tab[0] = false;
	tab[1] = false;
	for(int i=2;i<n;i++)
	{
		if(tab[i] == true)
		for(int j=i*i;j<n;j+=i)
			tab[j] = false;
	}
	int i=0,ilosc=0;
	cout << "Liczby pierwsze te to: " << endl;
	while(i<n)
	{
		if(tab[i] == true)
		{
		cout << i << endl;
		ilosc++;
		}
		i++;
	}
	
	cout << "Liczb pierwszych w danym przedziale jest " << ilosc << endl;
	
	
	return 0;
}
