#include <iostream>

using namespace std;

int dzielnik(int a, int b)
{
	int pom;
	
	while(b!=0)
	{
		pom=b;
		b=a%b;
		a=pom;
	}
	return a;
}

int main()
{
	long long a,b,c;
	cout << "Podaj 3 dowolne liczby naturalne a program poda ci NWD: " << endl;
	cin >> a >> b >> c;
	int wynik = dzielnik(dzielnik(a,b),c);
	cout << "Ten dzielnik to " << wynik << endl;
	
		
	
	
	
	
	
	system("pause");
	return 0;
}


