#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned long long N;
	while(true)
	{
	cout << "Prosze podac liczbe n a program poda ostatnia niezerowa cyfre wyrazenia n!  : " << endl;
	
	while(cin >> N)
	{
	unsigned long long a=1;
	for(unsigned long long n=2;n<=N;n++)
	{
		a*=n;
		while(a%10 == 0)
		a/=10;
		a=a%1000000;
	}
	cout << "Ostatnia niezerowa cyfra to " << a%10 << endl;
	}
	}
	
	
	
	
	system("pause");
	return 0;
}
