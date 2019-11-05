#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int MAX = 1000;
	double tab[MAX];
	for(int i=0;i<MAX;i++)
	{
		tab[i] = (rand() % MAX)+1;
	}
	int dlugosc = 1;
	int maxdlug = 1;
	int i=2;
	double c = tab[1]/tab[0];
	

	while(i<=MAX)
	{
		if(tab[i]/tab[i-1] == c)
		dlugosc++;
		else
		{
			if(dlugosc > maxdlug)
			{
				maxdlug = dlugosc;
				dlugosc = 1;
			}		
		}
		c=tab[i]/tab[i-1];
		i++;
	}
	cout << maxdlug << endl;
		
	
	
	return 0;
}
