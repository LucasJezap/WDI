#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x=sqrt(0.5); // x=0.7
	double y=x;    //y=0.7
	double z=1;
	double pi,a;

	while(z!=0)
	{
		y=sqrt(0.5+0.5*y);
		a=x*y;
		z = a-x;
		x= a;
	}
	pi = 2/x;
	cout << pi << endl;





	system("pause");
	return 0;
}
