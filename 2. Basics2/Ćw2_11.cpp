#include <iostream>

using namespace std;

int main()
{
	int n; 
	cout << "Prosze podac liczbe by sprawdzic czy jest wielokrotnoscia dowolnego wyrazu ciagu: " << endl;
	cin >> n;
	int ciag=2;
	int m=1;
	while(ciag<=n)
	{
		while(m*ciag<=n)
		{
			
			if(m*ciag==n)
			cout << "Liczba ta jest wielokrotnoscia wyrazu ciagu rownego " << ciag <<  endl;
			m++;
		}
		ciag=3*ciag+1;
		m=1;
	}
	
	
	
	
	system("pause");
	return 0;
}
