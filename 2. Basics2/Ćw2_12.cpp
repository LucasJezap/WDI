#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Prosze wpisac liczbe naturalna: " << endl;
	cin >> n; 
	while(n>10)
	{
		while(n%10>(n/10)%10)
		{
		n/=10;
		}
		if(n>=10)
		{
		cout << "Cyfry tej liczby nie sa ciagiem rosnacym" << endl;
		n=1;
		}
		else
		cout << "Cyfry tej liczby sa ciagiem rosnacym" << endl;
	}
	
	
	
	
	system("pause");
	return 0;
}
