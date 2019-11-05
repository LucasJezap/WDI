#include <iostream>

using namespace std;

int main()
{
	int a,b,c,n;
	cout << "Podaj liczbe: " << endl;
	cin >> n;
	a=0;
	b=1;
	while(c<=n)
	{
		c=a+b; 
		if(b*c==n)
		cout << "Wpisana liczba jest iloczynem kolejnych liczb ciagu Fibonacciego " << b << " oraz " << c << endl;
 		a=b;
		b=c;
	}
	
	
	
	system("pause");
	return 0;
}
