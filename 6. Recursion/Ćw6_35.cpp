#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 10;


bool zadanie(int t[N],int poczatek, int s1, int s2, int moc1, int moc2, int k) {
    if(s1==s2 and moc1==moc2 and moc1==k) return true;
    if(poczatek == N) return false;
    if(poczatek<N) {
        return(zadanie(t,poczatek+1,s1+t[poczatek],s2,moc1+1,moc2,k) or zadanie(t,poczatek+1,s1,s2+t[poczatek],moc1,moc2+1,k) or zadanie(t,poczatek+1,s1,s2,moc1,moc2,k));
    }
}

bool poszukiwania(int t[N], int k) {
    return zadanie(t,0,0,0,0,0,k);
}

int main() {
	srand(time(NULL));
	int t[N];
	for(int i=0;i<N;i++) {
		t[i] = 1+rand()%20;
		cout << t[i] << " ";
	}
	cout << endl;
	int k;
	cout << "Jaka moc podzbiorow? ";
	cin >> k;
	if(poszukiwania(t,k)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
