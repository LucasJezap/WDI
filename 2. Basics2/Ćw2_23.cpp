#include <iostream>
#include <string>
using namespace std;
string zamiana(int n, int podstawa)
{
	string liczba;
	int cyfra;
	char znak;
	while(n>0)
	{
		cyfra = n%podstawa;
		n/=podstawa;
		if(cyfra<10)
		{
			znak = 48 + cyfra;
			liczba = znak + liczba;
		}
		else
		{
			znak =	87 + cyfra;
			liczba = znak + liczba;
		}
	}
	return liczba;
}

bool porownanie(string a, string b)
{
	int dlugosc1 = a.size();
	int dlugosc2 = b.size();	 
	
	for(int i=0;i<dlugosc1;i++)
	{
		for(int j=0;j<dlugosc2;j++)
		{
			if(a[i] == b[j])
			return false;
		}
	}
	
	
	
	return true;
}

int main()
{
	int a,b;
	cin >> a >> b;
	string liczba1,liczba2;
	bool prawda = false;
	for(int i=2;i<17;i++)
	{
		liczba1 = zamiana(a,i);
		liczba2 = zamiana(b,i);
		if(porownanie(liczba1,liczba2))
		{
			cout << "Podstawa ta to " << i << endl;
			prawda = true;
			break; 
		}
	}
	if(!prawda)		
		cout << "Nima" << endl;
	
	
	return 0;
}
