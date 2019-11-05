#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int N = 20;

struct kwadrat{
    int x1;
    int x2;
    int y1;
    int y2;
};

bool niezachodzace(kwadrat a, kwadrat b) {
    if(b.x1>a.x2 or b.y1>a.y2) return true;
    if(a.x1>b.x2 or a.y1>b.y2) return true;
    return false;
}

bool wszystkie_niezachodzace(kwadrat t[N], bool zabrane[N], kwadrat a) {
    for(int i=0;i<N;i++) {
        if(zabrane[i] and !niezachodzace(t[i],a)) return false;
    }
    return true;
}

int pole(kwadrat a) {
    return (a.x2-a.x1)*(a.y2-a.y1);
}

bool zadanie(kwadrat t[N],bool zabrane[N], int suma, int poczatek, int liczebnosc) {
    if(suma == 832 and liczebnosc == 13) return true;
    if(poczatek==N or liczebnosc > 13) return false;
    if(!zabrane[poczatek] and wszystkie_niezachodzace(t,zabrane,t[poczatek])) {
        zabrane[poczatek] = true;
        if(zadanie(t,zabrane,suma+pole(t[poczatek]),poczatek+1,liczebnosc+1)) return true;
        zabrane[poczatek] = false;
    }
    if(zadanie(t,zabrane,suma,poczatek+1,liczebnosc)) return true;
    return false;
}

int main() {
    srand(time(NULL));
    kwadrat t[N];
    bool zabrane[N];
    for(int i=0;i<N;i++) zabrane[i] = false;
    cout << "(x1,x2,y1,y2)" << endl << endl << endl;
    for(int i=0;i<N;i++) {
        int x = 0;
        t[i].x1 = rand()%100;
        t[i].y1 = rand()%100;
        while(x<t[i].x1) x=rand()%150;
        t[i].x2 = x;
        t[i].y2 = t[i].y1 + t[i].x2 - t[i].x1;
        cout << "(" << t[i].x1 << "," << t[i].x2 << "," << t[i].y1 << "," << t[i].y2 << ")" << endl;
    }
    cout << endl;
    if(zadanie(t,zabrane,0,0,0)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
