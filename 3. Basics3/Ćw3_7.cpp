#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int main()
{
	int MAX = 200;
	int tab[MAX];
	srand (time(NULL));
	int score = 0;
	for(int i=0;i<MAX;i++)
	tab[i] = (rand() % 1001);
	int i=0;
	while(i<MAX)
	{
	while(tab[i]>0)
		{
		if((tab[i]%10)%2 == 1)
		{
		score++;
		break;
		}
		tab[i]/=10;
		}
	i++;
	}
	if(score == MAX)
	cout << "Kazda liczba posiada conajmniej 1 cyfre nieparzysta" << endl;
	else
	cout << "Kazda liczba nie posiada conajmniej 1 cyfry nieparzystej" << endl;
	return 0;
}
