#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool tasamadata(int tab1[], int MAX)
{
	int i=0,j=1;
	while(i<MAX-1)
	{
		while(j<MAX)
		{
			if(tab1[i] == tab1[j])
			return true;
			
			j++; 
		}
	i++;
	j=i+1;
	}
	
	return false;
	
}



int main()
{
	srand(time(NULL));
	const int MAX = 23;
	double udane = 0;
	double ilosc = 999999;
	int z=0;
	while(z<ilosc)
	{
	int dzien[MAX];
	for(int i=0;i<MAX;i++)
	{
		dzien[i] = (rand()%365)+1;
		//cout << dzien[i] << endl;
		
	}
	if(tasamadata(dzien,MAX))
	udane++;
	
	z++;
	}
	
	cout << udane << " " << ilosc << endl;
	double wynik = udane/ilosc;
	cout << wynik << endl;
}
