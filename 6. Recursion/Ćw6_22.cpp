#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 8;

int szeregowe(int r1, int r2) { return r1+r2; }
int rownolegle(int r1, int r2) {
    if(r1 == 0) return r2;
    return (r1*r2)/(r1+r2);
}

bool oporniki(int t[N],int opor,int wartosc,int licznik,int poczatek) {
    if(opor == wartosc and licznik == 3) return true;
    if(poczatek == N or licznik>3) return false;
    return(oporniki(t,szeregowe(opor,t[poczatek]),wartosc,licznik+1,poczatek+1) or oporniki(t,rownolegle(opor,t[poczatek]),wartosc,licznik+1,poczatek+1) or oporniki(t,opor,wartosc,licznik,poczatek+1));
}



int main() {
    srand(time(NULL));
    int t[N];
    for(int i=0;i<N;i++) t[i] = 1+rand()%25;
    for(int i=0;i<N;i++) cout << t[i] << " ";
    cout << endl;
    if(oporniki(t,0,60,0,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
