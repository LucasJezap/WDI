#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 8;

int ile_jedynek(int a) {
    int ilosc = 0;
    while(a>0) {
        if(a%2==1) ilosc++;
        a/=2;
    }
    return ilosc;
}

void zamiana(int t[N], int pom[N]) {
    for(int i=0;i<N;i++)
        pom[i] = ile_jedynek(t[i]);
}

bool podzielenie(int pom[N], int poczatek, int s1, int s2 ,int s3) {
    if(poczatek == N and s1==s2 and s1==s3) return true;
    if(poczatek == N) return false;
    return(podzielenie(pom,poczatek+1,s1+pom[poczatek],s2,s3) or podzielenie(pom,poczatek+1,s1,s2+pom[poczatek],s3) or podzielenie(pom,poczatek+1,s1,s2,s3+pom[poczatek]));
}

int main() {
    srand(time(NULL));
    int t[N];
    int pom[N];
    for(int i=0;i<N;i++) t[i] = 1+ rand()%15;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    zamiana(t,pom);
    for(int i=0;i<N;i++) cout << pom[i] << " ";
    if(podzielenie(pom,0,0,0,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
