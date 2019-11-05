#include <iostream>
#include <string>
using namespace std;

int ile_samoglosek(string a) {
    int ilosc = 0;
    for(int i=0;a[i]!='\0';i++) if(a[i]=='a' or a[i] =='e' or a[i]=='i' or a[i]=='o' or a[i]=='u' or a[i]=='y') ilosc++;
    return ilosc;
}
int suma_kodu(string a) {
    int suma = 0;
    for(int i=0;a[i]!='\0';i++) suma+=(int)a[i];
    return suma;
}

bool poszukiwania(string wyraz2,string budowany,int waga,int samogloski,string &szukany,int poczatek) {
    if(suma_kodu(budowany)==waga and ile_samoglosek(budowany)==samogloski) { szukany = budowany; return true; }
    if(wyraz2[poczatek]=='\0') return false;
    return(poszukiwania(wyraz2,budowany+wyraz2[poczatek],waga,samogloski,szukany,poczatek+1) or poszukiwania(wyraz2,budowany,waga,samogloski,szukany,poczatek+1));
}

bool zadanie(string wyraz1,string wyraz2) {
    int waga = suma_kodu(wyraz1);
    int samogloski = ile_samoglosek(wyraz1);
    string szukany;
    if(poszukiwania(wyraz2,"",waga,samogloski,szukany,0))  { cout << szukany << endl; return true;}
    return false;
}


int main() {
   string wyraz1,wyraz2;
   cin >> wyraz1 >> wyraz2;
   if(zadanie(wyraz1,wyraz2)) cout << "TAK" << endl;
   else cout << "NIE" << endl;
}
