#include <iostream>
#include <math.h>
using namespace std;
const double eps = 1e-15;

int main()
{
	long double y,z;
	int a;
	cout << "Podaj liczbe, ktorej pierwiastek trzeciego stopnia chcesz obliczyc: " << endl;
	cin >> a;
	y=a/2;
	
	while(abs(a/(y*y)-y)>eps)
	{
	y=(y+(a/(y*y)))/2;
	
	}
	cout << "Wynikiem pierwiastkowania jest " << y << endl;	
	
	
	
	
	
	system("pause");
	return 0;
}
