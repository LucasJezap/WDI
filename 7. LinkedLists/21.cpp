#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node {
 int val;
 node* next;
};

void stworz_cykl(node *&first, int N) {
    int i = 0;
    node *p = NULL;
    node *tmp;
    while(i<N) {
        p = new node;
        p->val = rand()%100;
        p->next = first;
        first = p;
        if(i==0) tmp = p;
        if(i==N-3) tmp->next = p;
        i++;
    }
}

void wypisz_cykl(node *first, int N) {
    int i=0;
    int x;
    while(i<N) {
        if(i==2) x= first->val;
        cout << first->val << " -> ";
        first=first->next;
        i++;
    }
    cout << "cykl rozpoczynajacy sie od " << x << endl;
}

void wstaw_wartownika(node *&first) {
    node *wartownik = new node;
    wartownik->next = first;
    first = wartownik;
}

void usun_wartownika(node *&first) {
    node *tmp = first;
    first=first->next;
    delete tmp;
}

int dlugosc_niecyklu(node *first, node *tmp) {
    int dlugosc = 0;
    while(first!=tmp) {dlugosc++, first=first->next; tmp=tmp->next; }
    return dlugosc;
}

int cykl(node *first) {
    node *a=first, *b=first;
    while(true) {
        a=a->next;
        b=b->next->next;
        if(a==b) return dlugosc_niecyklu(first,a);
    }
}

int main() {
    node *first = NULL;
    stworz_cykl(first,5);
    wypisz_cykl(first,5);
    cout << cykl(first);
}
