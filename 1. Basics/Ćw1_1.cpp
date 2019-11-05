#include <iostream>

using namespace std;

int main()
{
	long long a=0,b=1;
	cout << a << endl << b << endl;
	for(int i=0;i>=0;i++)
	{
		long long c;
		while(true)
		{
		c=a+b;
		if (c>1000000)
		break;
			
		cout << c << endl;
			a=b;
			b=c;
		}
	}
	system("pause");
	return 0;
}
