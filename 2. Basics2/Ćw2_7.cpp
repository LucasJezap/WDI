#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cout << "Prosze podac liczbe a program rozlozy ja na iloczyn dwoch liczb o najmniejszej roznicy:" << endl;
	cin >> n;
	int a=1,b,wynik,x=n,z=n,t1,t2;
	while(2*a<=n)
	{
	if(n%a == 0)
	{
		b= z/a;	
		wynik = abs(a-b);
	}
	if(wynik<x)
	{
		x=wynik;
		t1=a;
		t2=b;
	}
	a++;
	z=n;
    }
    cout << "Ten iloczyn to iloczyn liczb " << t1 << " oraz " << t2 << endl;
	
	
	
	
	
	
	system("pause");
	return 0;
}
