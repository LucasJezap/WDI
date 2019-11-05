#include <iostream>
#include <math.h>
using namespace std;
const double eps =0.0000001;
int main()
{
	double a=4;
	while(abs(exp(a*log(a))-2018)>eps)
	{
		a=a-(exp(a*log(a))-2018)/(exp(a*log(a)*(log(a)+1)));
	}
	
		cout << "Rozwiazaniem jest " << a << endl;
	
	
	
	system("pause");
	return 0;
}
