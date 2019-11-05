#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cout << "Podaj dwa poczatkowe wyrazy twojego ciagu Fibonacciego: " << endl;
	cin >> a;
	cin >> b;
	double iloraz=1;
	int ilosc = 1;
	while(ilosc<10000)
	{
	c=a+b;
	iloraz=a/b;
	a=b;
	b=c;
	ilosc++;
	}
	cout << "Iloraz dwoch kolejnych wyrazow zmierza do " << iloraz << endl;
	
	
	
	system("pause");
	return 0;
}
