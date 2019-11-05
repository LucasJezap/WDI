#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,podstawa;
	cout << "Prosze podac liczbe, ktora chcesz zamienic na inny system: " << endl;
	cin >> n;
	cout << "Na jaka podstawe? (2-16)?" << endl;
	cin >> podstawa;
	
	
	string wynik;

	
	while(n!=0)
	{
		int cyfra = n%podstawa;
		
		char znak;
		if(cyfra < 10)
			znak = '0' + cyfra;
		else
			znak = cyfra - 10 + 'a';


		wynik = znak + wynik;
		
		n/=podstawa;
	
	}
	cout << wynik << endl;
	
	return 0;
}
