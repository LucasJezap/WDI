#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Prosze podac pewna wartosc a program sprawdzi czy jest to iloczyn dowolnych dwoch elementow ciagu Fibonacciego: " << endl;
	cin >> n;
	int a=1,b=1,c,d=1,e=1,f=1;
	while(n>=b)
	{
		c=a+b;
		while(n>=f)
		{
			if((f*c)== n)
			{
				cout << "Wartosc ta jest iloczynem " << f << " oraz " << c << endl;
			}
			f=d+e;
			d=e;
			e=f;
		}
		a=b;
		b=c;
		d=1;
		e=1;
		f=1;
	}
	
	
	
	
	system("pause");
	return 0;
}
