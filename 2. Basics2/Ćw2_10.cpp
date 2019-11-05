#include <iostream>

using namespace std;

int main()
{
	int lewy = 1;
	int prawy,liczba;
	double z;
	cout << "Policzymy pole pod wykresem funkcji 1/x w przedziale od 1 do k, prosze podac k: " << endl;
	cin >> prawy;
	cout << "Na ile prostokatow podzielic dany przedzial? " << endl;
	cin >> liczba;
	double szerokosc=(prawy-lewy)/liczba;
	double wynik=0;
	z=1+szerokosc;
	while(z<=prawy)
	{
		wynik=wynik+((1/z)*szerokosc);
		z+=szerokosc;
	}
	cout << "Pole to " << wynik << endl;
	
	
	
	
	
	system("pause");
	return 0;
}
