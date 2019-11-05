#include <iostream>

using namespace std;

int main()
{
	int n; 
	cout << "Prosze podac liczbe naturalna: " << endl;
	cin >> n;
	int x=n;
	int i=1; // i - liczba cyfr
	while(x>=10)
	{
		x/=10;
		i++;
	}
	while(n>0)
	{
		if(n%10==i)
		break;
		else
		n/=10;
	}
	if(n%10 == i)
	cout << "Jedna z cyfr tej liczby jest rowna ilosci cyfr tej liczby " << endl;
	else
	cout << "Zadna z cyfr tej liczby nie jest rowna ilosci cyfr tej liczby " << endl;
	
	
	
	
	
	system("pause");
	return 0;
}
