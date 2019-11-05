#include <iostream>

using namespace std;

int main()
{
	int a,b,c,n,wynik;
	cout << "Prosze podac liczbe by sprawdzic czy jest ona suma spojnego podciagu ciagu Fibonacciego: " << endl;
	cin >> n;
	a=0;
	b=1;
	wynik=1;
	while(n>wynik)
	{
		c=a+b;
		wynik+=c;
		a=b;                   
		b=c;
	}
	if(wynik==n)
	{
	cout << "Istnieje taki podciag ze jego suma jest rowna " << n << endl;
	return 0;
	}
	a=0;
	b=1;
	wynik-=1;
	while(wynik>n)
	{
	c=a+b;
	wynik-=c;
	a=b;
	b=c;
	}
	if(wynik == n)
	cout << "Istnieje taki podciag ze jego suma jest rowna " << n << endl;
	else 
	cout << "Nie istnieje taki podciag ze jego suma jest rowna " << n << endl;
	
	
	
	
	system("pause");
	return 0;
}
