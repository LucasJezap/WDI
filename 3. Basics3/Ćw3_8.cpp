#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int MAX = 10;
	int tab[MAX];
	srand (time(NULL));
	for(int i=0;i<MAX;i++)
	tab[i] = (rand() % 1001);
	int i=0;
	while(i<MAX)
	{
		while(tab[i]>0)
		{
			if((tab[i]%10)%2 == 1)
			{
			tab[i]/=10;
			} 	
			else
			break;	
		}
	if(tab[i] == 0)
	{
		cout << "Istnieje liczba o samych nieparzystych cyfrach" << endl;
		break;
	}
	i++;	
	}
	return 0;
}
