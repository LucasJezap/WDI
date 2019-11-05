#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int n;
	int * tablica;
	cout << "Ile elementow ma zawierac tablica? " << endl;
	cin >> n;
	tablica = new int[n];
	for(int i=0;i<n;i++)
	{
		tablica[i] = rand() % 101;
		//cout << tablica[i] << endl;
	}
	
	
	
	
	bool czymozna = true;
	
	for(int i=2;i<n;i++)
	{
		if(n%i == 0)
		czymozna = false;
	}
	if(tablica[0]%n != 0)
	czymozna = false;
	
	
	if(czymozna)
	cout << "A no mozna" << endl;
	else 
	cout << "A no nie mozna" << endl;
	
	
	return 0;
}
