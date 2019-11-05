#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int MAX = 1000;
	int tab[MAX];
	for(int i=0;i<MAX;i++)
	{
		tab[i] = rand() % MAX;
	}
	int dlugosc = 1;
	int maxdlug = 1;
	int i=1;
	
	
	while(i<=MAX)
	{
		if(tab[i]>tab[i-1])
			dlugosc++;
		else
		{
		if(dlugosc > maxdlug)
			
			maxdlug = dlugosc;
			
			dlugosc = 1;
		}
	i++;	
	}
	

	
	cout << maxdlug << endl;
	
	
	
	return 0;
}
