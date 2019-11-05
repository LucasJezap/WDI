
#include <iostream>

using namespace std;

int main()
{
	long long int a=1,b=1,c=1,N,i=0;
	cout << "Do jakiej liczby chcesz szukac trojek pitagorejskich? " << endl;
	cin >> N;
	
	while(a<=N)
	{
		
		while(b<=N)
		{
		
			while(c<=N)
			{
				
				if(a*a+b*b == c*c)
				{
				cout << "Liczby " << a << " " << b << " " << " oraz " << c << " tworza trojke pitagorejska" << endl;
				i++;
				}	
				c++;
				
			}
			b++;
			c=1;
		}
		a++;
		b=1;
	}
	
	cout << "Jest " << i << " takich trojek" << endl;
	
	
	
	
	system("pause");
	return 0;
}
