#include <iostream>

using namespace std;

int wielokrotnosc(int a, int b)
{
	int pom;
	int x=a,y=b;
	while(b!=0)
	{
		pom=b;
		b=a%b;
		a=pom;
	}
	return 	(x*y)/a;
}
int main()
{
	int a,b,c;
	cout << "Podaj 3 liczby a program znajdzie ich NWW: " << endl;
	cin >> a >> b >> c;
	int wynik = wielokrotnosc(wielokrotnosc(a,b),c);
	
	cout << "Ta wielokrotnosc to " << wynik << endl;
	
	
	system("pause");
	return 0;
}
