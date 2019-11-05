#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj liczbe naturalna: " << endl;
	cin >> n;
	cout << "Liczby: ";
	for(int i=1;2*i<=n;i++)
	{
		if(n%i==0)
		cout << i << ",";
		
	}
	cout << " sa podzielnikami liczby " << n << endl;
	
	
	
	
	system("pause");
	return 0;
}
