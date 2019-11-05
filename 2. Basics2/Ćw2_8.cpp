#include <iostream>

using namespace std;

int main()
{
	int a,b,n;
	cout << "Jakie liczby chcesz podzielic i z jaka dokladnoscia? " << endl << "Liczbe: " ;
	cin >> a;
	cout << "Przez liczbe: ";
	cin >> b;
	cout << "Z jaka dokladnoscia (ile miejsc po przecinku)? ";
	cin >> n;
	int calosc,niecalosc[n],i=0,z=0;
	
	calosc = a/b;
	a-=calosc*b;
	while(i < n)
	{
	a*=10;
	niecalosc[i]=a/b;
	a-=niecalosc[i]*b;
	i++;
	}
	
	
	
	cout << "Wynik to " << calosc << ",";
	while(z< n)
	{
		cout << niecalosc[z];
		z++;
	}
	cout << endl;
	
	system("pause");
	return 0;
}
