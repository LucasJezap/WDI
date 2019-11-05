#include <iostream>
#include <math.h>
using namespace std;

bool pierwsza(int n)
{
	if(n==2 or n==3)	return true;
	if(n==1) 	return false;
	if(n%2 == 0 or n%3 == 0) return false;
	int p = sqrt(n);
	int b = 5;
	while(b<=p)
	{
		if(n%b == 0) return false;
		b+=2;
		if(n%b == 0) return false;
		b+=4;
	}
	return true;
}

int suma_cyfr(int a)
{
	int suma = 0;
	while(a>0)
	{
		suma+=a%10;
		a/=10;
	}
	return suma;
}

int suma_czynnikow(int a)
{
	int suma = 0;
	int i = 2;
	while(a>1)
	{
		while(a%i == 0)
		{
			suma+=suma_cyfr(i);
			a/=i;
		}
		i++;
	}
	return suma;
}


int main()
{
	for(int i=1;i<1000;i++)
	{
		if(!pierwsza(i))
		{
			if(suma_cyfr(i) == suma_czynnikow(i))
				cout << i << endl;
		}
	}
	
	return 0;
}
