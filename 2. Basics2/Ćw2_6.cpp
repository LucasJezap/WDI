#include <iostream>


using namespace std;

int funkcja(int n, int i)
{
	int wynik=0;
	int zm1 = n % i, zm2 = n / (10*i);
	zm2*=i;
	int liczba = zm1+zm2;
	
	if(liczba % 7 == 0 and liczba != 0)
	wynik ++;
	
	if( i < liczba)
		wynik+= funkcja(liczba,i);
	if( i*10 < n)
	{
		wynik+= funkcja(n,i*10);
	}
		
	return wynik;		
	
}


int main()
{
	int n;
	cout << "Prosze podac liczbe naturalna o unikalnych cyfrach roznych od zera: " << endl;
	cin >> n;
	
	cout << funkcja(n,1) << endl;
	
	
	
	
	
	return 0;
}
