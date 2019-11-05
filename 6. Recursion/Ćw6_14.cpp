#include <iostream>
using namespace std;


void wypisz(int t[8]) {
    for(int i=0;i<8;i++) cout << t[i];
    cout << endl;
}

void hetman(int k,bool poziom[8], bool ukos_pr[15], bool ukos_le[15], int het[8]) {
    if(k==8) wypisz(het);
    else {
        for(int w=0;w<8;w++)
            if(!poziom[w] and !ukos_pr[w-k+7] and !ukos_le[w+k]) {
                poziom[w]=ukos_pr[w-k+7]=ukos_le[w+k]=true;
                het[k] = w;
                hetman(k+1,poziom,ukos_pr,ukos_le,het);
                poziom[w]=ukos_pr[w-k+7]=ukos_le[w+k]=false;
            }
    }
}

int main() {
 int het[8];
 bool poziom[8];
 bool ukos_pr[15];
 bool ukos_le[15];
 hetman(0,poziom,ukos_pr,ukos_le,het);
}
