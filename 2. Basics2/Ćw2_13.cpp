#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 15;

int srednia_arytmetyczna(int tab[N])
{
	int ilosc = 0;
	if(4*tab[0] == tab[1] + tab[2] + tab[3] + tab[4])
	ilosc++;
	if(4*tab[1] == tab[0] + tab[2] + tab[3] + tab[4])
	ilosc++;
	if(4*tab[N-1] == tab[N] + tab[N-2] + tab[N-3] + tab[N-4])
	ilosc++;
	if(4*tab[N] == tab[N-1] + tab[N-2] + tab[N-3] + tab[N-4])
	ilosc++;
	for(int i=2;i<N-1;i++)
	{
		if(4*tab[i] == tab[i+1] + tab[i+2] + tab[i-1] + tab[i-2])
		ilosc++;
		
	}
	return ilosc;
}


int main()
{
	srand(time(NULL));
	int tab[N];
	for(int i=0;i<N;i++)
	{
		tab[i] = rand()%25;
		cout << tab[i] << endl;
	}
	cout << endl << srednia_arytmetyczna(tab) << endl;
}
