#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj liczbe ktorej obliczymy silnie: " << endl;
	cin >> n;
	
	char tab[70000];
	int c,d;
	
	c=1;
	tab[0] = '1';
	
	for(int i=2;i<=n;i++)
	{
		d=0;
			for(int j=0;j<c;j++)
			{
				d=((tab[j]-48)*i)+d;
				tab[j] = (d%10)+48;
				d=d/10;
			}
		
		while(d>0)
		{
			tab[c]=(d%10)+48;
			d=d/10;
			c++;
			}	
	}
	int z;
	z=c;
	
	for(int i = z-1;i>=0;i--)
	cout << tab[i];
	
	
	
	
	
	
	
	return 0;
}
