#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool czyzlozona(int a)
{
	for(int i=2;2*i<=a;i++)
	{
		if( a % i == 0 and a != 2)
		return true;
	}
	return false;
}
bool czypierwsza(int a)
{
	for(int i=2;2*i<=a;i++)
	{
		if( a%i == 0 && a != 2)
		return false;
	}
	return true;
}

bool czyfibonacci(int a, int limit)
{
	int x,y,z;
	x = 1;
	y = 1;
	if(a == 1)
	return true;
	while(z<limit)
	{
	  z = x+y;
	  if(a == z)
	  return true;
	  x=y;
	  y=z;
	}
	return false;
}



int main()
{
	srand(time(NULL));
	int const MAX = 10000;
	int tab[MAX];
	int pierwsze = 0;
	bool odpowiedz=true;
	
	for(int i=0;i<MAX;i++)
	{
		tab[i] = (rand()%MAX)+1;
		//cout << tab[i] << endl;
	}
	
	
	for(int i=0;i<MAX;i++)
	{
		if(czyfibonacci(i,MAX))
		{
		if(czyzlozona(tab[i]) == 0)
		odpowiedz = false;	
		}
		else
		{
			if(czypierwsza(tab[i]))
			pierwsze++;
		}
		
	}
	if(pierwsze == 0)
	odpowiedz = false;
	
	if(odpowiedz)
	cout << "Warunek zostal spelniony" << endl;
	else
	cout << "Warunek nie zostal spelniony" << endl;
	
	return 0;
}




