#include <iostream>
#include <math.h>
using namespace std;
const double eps =1e-10;
int main()
{
	double y,a,b,c;
	a=2.0;
	b=3.0;
	while((b-a)>eps)
	{
	c=(a+b)/2;
	y=exp(exp(c*log(c))*log(c));
	if(y>2018)
	b=c;
	else
	a=c;
	}
	cout << c << endl;
	system("pause");
	return 0;
}
