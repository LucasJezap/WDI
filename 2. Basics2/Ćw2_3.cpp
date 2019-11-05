#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long int n;
	cout << "Prosze podac liczbe naturalna by sprawdzic czy jest palindromem: " << endl;
	cin >> n;
	int i=1;
	long long int a=n;
	while(a>=10)
	{
		a/=10;
		i++;
	}             // wszystko dobrze i-liczba cyfr
	int k=0;
	while(k+1<=i)
{
	int t1=(n/(int)pow(10,k))%10;
	int t2=(n/(int)pow(10,i-1))%10;
	if(t1!=t2)
	break; 
	k++;
	i--;  
}
	if(k+1>i)
	cout << "Liczba jest palindromem w systemie dziesietnym" << endl;
	else
	cout << "Liczba nie jest palindromem w systemie dziesietnym" << endl;
	
	
	a=n;
	i=log2(a)+1;
	k=0;
		while(k+1<=i)
{
	int t1=(n/(int)pow(2,k))%2;
	int t2=(n/(int)pow(2,i-1))%2;
	if(t1!=t2)
	break; 
	k++;
	i--;  
}
	if(k+1>i)
	cout << "Liczba jest palindromem w systemie dwojkowym " << endl;
	else
	cout << "Liczba nie jest palindromem w systemie dwojkowym " << endl;
	
	
	
	
	
	
	
	system("pause");
	return 0;
}
