#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 10;

void nka(int t[N],int iloczyn,int poczatek,int n, int &licznik, string a) {
    if(n==1) {
        for(int i=poczatek;i<N;i++)
            if(t[i]==iloczyn) {a+=to_string(t[i]); cout << a << endl; licznik++; }
    }
    else
      for(int i=poczatek;i<N;i++) {
            if(iloczyn%t[i]==0) nka(t,iloczyn/t[i],i+1,n-1,licznik,a+to_string(t[i])+" ");
      }
}

int main() {
	srand(time(NULL));
	int t[N];
	for(int i=0;i<N;i++) {
		t[i] = 1+rand()%14;
		cout << t[i] << " ";
	}
	cout << endl;
	int licznik = 0;
	nka(t,20,0,3,licznik,"");
	cout << "ILOSC " <<  licznik << endl;
}
