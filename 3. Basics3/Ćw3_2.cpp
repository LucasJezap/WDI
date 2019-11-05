#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cout << "Prosze podac 2 liczby naturalne by sprawdzic czy wystepuja w nich te same cyfry: " << endl;
	cin >> a;
	cin >> b;
	c=a;
	d=b;
	if((int)log10(a) != (int)log10(b))
	{
	cout << "Liczba cyfr jest rozna" << endl;
	return 0;
	}
	int ilosc = (int)log10(a)+1;
	
	int tab1[ilosc];
	int tab2[ilosc];


	for(int i=0;i<ilosc;i++)
	{
		tab1[i] = c%10;
		tab2[i] = d%10;
		c/=10;
		d/=10;
	}
	
	int wynik=0;
	
	for(int i=0;i<ilosc;i++)
	{
		
		for(int j=0;j<ilosc;j++)
		{
			if(tab1[i] == tab2[j])
			{
			wynik++;
			break;
			}
		}
	}
	
	if(wynik == ilosc)
	cout << "Liczby te sa zlozone z tych samych cyfr" << endl;
	else 
	cout << "Liczby te nie sa zlozone z tych samych cyfr" << endl;
	
	
	
	return 0;
}
