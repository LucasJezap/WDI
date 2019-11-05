#include <iostream>

using namespace std;

int dzielniki(int a)
{
	int suma = 0;
	for(int i=1;2*i<=a;i++)
	{
		if(a%i == 0)
		suma+=i;
	}
	return suma;
}

bool sprawdzenie(int a, int b)
{
	if(a == b)
	return true;
	
	return false;
}

int main()
{
	for(int i=1;i<1000000;i++)
	{
		int suma = dzielniki(i);
		
		if(sprawdzenie(i,dzielniki(suma)) and suma != i and i>suma)
		cout << suma << " " << i << endl;
	}
	
	
	return 0;
}
