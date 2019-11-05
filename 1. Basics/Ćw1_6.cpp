#include <iostream>

using namespace std;

bool czypierwsza(int n)
{
	if(n<2)
	return false;
	
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		return false;
	
	return true;	
}
int main()
{
	int a;
	cout << "Podaj pewna liczbe naturalna: " << endl;
	cin >> a;
	if(czypierwsza(a) == 1)
	cout << "Jest to liczba pierwsza!" << endl;
	else
	cout << "To nie jest liczba pierwsza!" << endl;
	
	system("pause");
	return 0;
	
}
