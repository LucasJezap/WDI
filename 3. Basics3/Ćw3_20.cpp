#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool czypierwsza(int a)
{
	for(int i=2;2*i<=a;i++)
	{
		if( a%i == 0 && a != 2)
		return false;
	}
	return true;
}

void suma_poprawna(int t1[],int t2[], int n, int i, int suma, int &count)
{
	if(i==n and czypierwsza(suma)) {
        count++;
        cout << count << " suma jest " << suma << endl;
        return;
	}
	if(i==n) return;
	suma_poprawna(t1,t2,n,i+1,suma+t1[i],count);
    suma_poprawna(t1,t2,n,i+1,suma+t2[i],count);
    suma_poprawna(t1,t2,n,i+1,suma+t1[i]+t2[i],count);
}


int main() {
	int t1[] = {1,3,2,4};
	int t2[] = {9,7,4,8};
	int count=0;
    suma_poprawna(t1,t2,4,0,0,count);
    cout << "Takich sum jest "  << count << endl;



	return 0;
}
