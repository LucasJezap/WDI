#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int roznica(int tab[], int MAX)
{
	int min = tab[0],max = tab[0];
	for(int i=1;i<MAX;i++)
	{
		if(tab[i]<min)
		min=tab[i];
		if(tab[i]>max)
		max=tab[i];
	}
	int wynik = max-min;
	return wynik;
}
int main()
{
	srand(time(NULL));
	const int MAX = 2000;
	int tab[MAX];
	for(int i=0;i<MAX;i++)
	{
		tab[i] = rand();
	}
	cout << roznica(tab,MAX) << endl;
	
	
	
	return 0;
}
