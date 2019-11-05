#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool max_min(int tablica[], int n)
{
	int max=tablica[0],min=tablica[0];
	int sumamin=0,sumamax=0;
	for(int i=1;i<n-1;i++)
	{
		if(tablica[i]>max)
		max = tablica[i];
		if(tablica[i]<min)
		min = tablica[i];	
	}
	for(int i=0;i<n;i++)
	{
		if(tablica[i] == max)
		sumamax++;
		if(tablica[i] == min)
		sumamin++;
	}
	if(sumamax == 1 && sumamin == 1)
	return true;
	
	
	return false;
}

int main()
{
	srand(time(NULL));
	int n;
	cout << "Ile elementow powinna zawierac tablica? " << endl;
	cin >> n;
	int * tablica;
	tablica = new int [n];
	for(int i=0;i<n;i++)
	{
		tablica[i] = rand()-rand();
		//cout << tablica[i] << endl;
	}
	if(max_min(tablica, n))
	cout << "Ta tablica zawiera tylko jedna najwieksza i najmniejsza wartosc" << endl;
	else
	cout << "Ta tablica zawiera wiele najwiekszych i najmniejszych wartosci" << endl;
	
	
	return 0;
}
