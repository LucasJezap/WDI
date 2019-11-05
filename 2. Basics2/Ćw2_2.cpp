#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "Prosze podac liczbe naturalna: " << endl;
	cin >> x;
	int wynik=0;
	for(int n=1;n<=x;n++)
	{
		wynik =n*n+n+1;
		for(int m=1;m<=x;m++)
		{
			if(m*wynik==x)
			cout << "Liczba " << x << " jest wielokrotnoscia liczby " << wynik << endl; 
		}
			
	}
	 
	
	
	system("pause");
	return 0;
}
