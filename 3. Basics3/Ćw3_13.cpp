#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int n;
	int * tablica;
	cout << "Ile elementow ma miec tablica? " << endl;
	cin >> n;
	tablica = new int[n];
	for(int i=0;i<n;i++)
	{
		tablica[i] = 2;
		while(tablica[i]%2 == 0)
		tablica[i] = (rand() % 99)+1;
	}
	int dlug_dodatnia = 1;
	int dlug_ujemna  = 1;
	int max_dodatnia = 1;
	int max_ujemna = 1;
	int i = 2;
	int c=tablica[1]-tablica[0];
	while(i<=n)
	{
		if(tablica[i]-tablica[i-1] == c and c < 0)
		dlug_ujemna++;
		else
		dlug_ujemna = 1;
		if(tablica[i]-tablica[i-1] == c and c > 0)
		dlug_dodatnia++;
		else
		dlug_dodatnia = 1;
		if(dlug_ujemna > max_ujemna)
		{
			max_ujemna = dlug_ujemna;
		}
		
		if(dlug_dodatnia > max_dodatnia)
		{
			max_dodatnia = dlug_dodatnia;
		}
		
		
		i++;
	}
	cout << "Taka roznica to " << max_dodatnia - max_ujemna << endl;
	
	
	return 0;
}
