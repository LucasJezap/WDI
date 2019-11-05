#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int suma_sumie(int tab[],int N)
{
	int max_dlug = 1;
	int dlugosc = 1;
	int i = 1;
	int suma_indeksow=0;
	int suma_tablic=0;
	suma_indeksow=i-1;
	suma_tablic=tab[i-1];
	while(i<=N)
	{
		
	if(tab[i]>tab[i-1])
	{	
		dlugosc++;
		suma_indeksow+= i;
		suma_tablic+= tab[i];
	}
	else
	{
	if(suma_indeksow==suma_tablic and max_dlug < dlugosc)	
	max_dlug = dlugosc;
	
	suma_indeksow = i;
	suma_tablic = tab[i];
	dlugosc = 1;
	} 
	i++;
	
	
	}
	
	return max_dlug;
	
}


int main()
{
	srand(time(NULL));
	const int N=10;
	int tab[N];
	for(int i=0;i<N;i++)
	tab[i]=rand()%N;
	
	for(int i=0;i<N;i++)
	cout << tab[i] << endl;
	
	cout << endl;
	cout << suma_sumie(tab,N) << endl;
	
	
	
	
	
	return 0;
}
