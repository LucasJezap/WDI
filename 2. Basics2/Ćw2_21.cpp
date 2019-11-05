#include <iostream>

using namespace std;

int main()
{
	int a0,a1,an,b0,b1,bn;
	a0=0,a1=1,b0=2,b1=2;
	int n;
	an=a1-b1*a0;
	bn=b1+2*a1;
	while(true)
	{
	cout << "Prosze podac pewna liczbe typu integer: " << endl;
	cin >> n;
	if(n==an)
	cout << "Liczba odpowiadajaca temu wyrazowi to: " << bn << endl;
	
	a0=a1;
	a1=an;
	b0=b1;
	b1=bn;
	} while (n==an);
	
	
	
	
	system("pause");
	return 0;
}
