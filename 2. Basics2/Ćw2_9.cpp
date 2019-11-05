#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	n++;
	int tab[15];
	int a=1,b=1;
	tab[0] = 1;
	tab[1] = 1;
	for(int i=2;i<15;i++)
	{
		tab[i]=a+b;
		a=b;
		b=tab[i];	
	}
	int suma=0,i=0,k=0;
	while(n<=1000)
	{
		
		while(i<15 && suma < n)
		{
		suma+=tab[i];
		while(n<suma)
		{
		suma-=tab[k];
		k++;	
		}
		i++;
		if(suma==n)
		{
			n++;
			suma=0;
			i=0;
			k=0;
		}
		}
		cout << n << endl;
		break;
		
		
	}
	
	
	return 0;
}
