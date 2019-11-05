#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Prosze podac liczbe naturalna: " << endl;
	cin >> n;
	int z= n%10;
	n/=10;
	while(n%10 != z && n>=10)
	{
		
		n/=10;
	}
	if(n%10 != z)
	cout << "Ostatnia cyfra tej liczby naturalnej jest unikalna" << endl;
	else
	cout << "Ostatnia cyfra tej liczby naturalnej nie jest unikalna" << endl;
	
	
	
	
	
	system("pause");
	return 0;
}
