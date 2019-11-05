#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c,t1,t2,wynik=2018;
	for(int i=1;i<1009;i++)
	{
		for(int j=2;j<1009;j++)
		{
			a=i;
			b=j;
			while(c<2018)
			{
				c=a+b;
				a=b;
				b=c;
			}
			if(c==2018 && wynik>j+i)
				{
				wynik = j+i;
				t1=i;
				t2=j;
				}
			c=0;


		}

	}
	cout << "Takie liczby to: " << t1 << " oraz " << t2 << endl;
	return 0;
}
