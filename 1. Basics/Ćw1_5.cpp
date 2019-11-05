#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "Podaj x:" << endl;
	cin >> x;
	
	int n,k,suma;
	k=1;
	n=0;
	suma=0;
	while(suma <= x)
	{
		suma+=k;
		k+=2;
		n++;
	}
	cout << (n-1) << endl;
	
	system("pause");
	return 0;
}
