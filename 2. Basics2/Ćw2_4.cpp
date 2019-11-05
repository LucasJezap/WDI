#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj pewna liczbe naturalna: " << endl;
	cin >> n;
	int a=n;
	int c=1;
	int i=1;
	int x=0;
	while(a>c)
	{
		x=i;
		while(i%2==0)
		{
		i/=2;	
		}
		while(i%3==0)
		{
		i/=3;	
		}	
		while(i%5==0)
		{
		i/=5;
		}
	if(i==1)
	{
	cout << "Liczba " << x << " jest liczba dwu-trzy-piatkowa " << endl;
	}
	i=1;
	i=i+c;
	c++;
	
	}

	
	
	
	
	
	
	
	
	system("pause");
	return 0;
}
