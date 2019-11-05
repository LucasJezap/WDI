#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int const MAX = 32000;
	int tab[MAX];
	for(int i=0;i<MAX;i++)
	{
		tab[i] = (rand()%900)+100;
		cout << tab[i] << endl;
	}
	
	int dlugosc=1;
	int max_dlugosc = 1;
	int i = 0;
	int j = 1;
	int pierwszaliczba = 0, ostatnialiczba = 0;
	while(i<MAX)	
	{
		while(j<=MAX)
		{
			if(tab[j] == tab[i])
			{
			
				int m = i, n = j;
				while(tab[m+1]==tab[n-1] and n-m>2)
				{
					dlugosc++;
					m++;
					n--;
				}
				if(dlugosc > max_dlugosc)
				{
					max_dlugosc = dlugosc;
					pierwszaliczba = i;
					ostatnialiczba = j;
				}
				dlugosc = 0;
			}
			j++;
		}
		
		i++;
		j=i+1;	
	}
	
	cout << "Maksymalna dlugosc palindormu cyfr to " << max_dlugosc  << endl;
	cout << pierwszaliczba << " " <<  ostatnialiczba << endl;
	return 0;
}
