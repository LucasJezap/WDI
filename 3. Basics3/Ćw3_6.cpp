#include <iostream>

using namespace std;

int main()
{
	const int MAX = 100;
	int tab[MAX];
	int ilosc = 0;
	cout << "Prosze podawac kolejne liczby naturalne ( conajmniej 10), proces zakonczyc wpisaniem 0" << endl;
	for(int i=0;i<MAX;i++)
	{
		cin >> tab[i];
		if(tab[i] == 0)
		break; 
		
		int m = i;
		while(tab[m]<tab[m-1] and m>0)
		{
			int temp = tab[m-1];
			tab[m-1] = tab[m];
			tab[m] = temp;
			m--;
		}
		ilosc++;
		
	}
	
	cout << "10 najwieksza liczba w tym ciagu jest " << tab[ilosc-10] << endl;
	
	return 0;
}
