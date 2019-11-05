#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node {
 int val;
 node* next;
};

void stworz(node *&first, int N) {
    int i = 0;
    node *p = NULL;
    while(i<N) {
        p = new node;
        p->val = 100-2*i;
        p->next = first;
        first = p;
        i++;
    }
}

void wypisz(node *first) {
    while(first!=NULL) {
        cout << first->val << " -> ";
        first=first->next;
    }
    cout << "NULL" << endl;
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

void zadanie(node *&first) {
    if(first==NULL) return;
    wstaw_wartownika(first);
    node *q = first->next, *p = first->next->next, *last, *f,*tmp=first;
    int dlugosc = 1, max_dlugosc = 1;
    int licznik = 1;
    while(p!=NULL) {
        if(p->val>q->val) dlugosc++;
        else { dlugosc = 1, tmp = q; }
        if(max_dlugosc==dlugosc) licznik++;
        if(max_dlugosc<dlugosc) { max_dlugosc = dlugosc, licznik = 1; last = p; f=tmp; }
        q=p;
        p=p->next;
    }
    if(licznik==1) {
        node *tmp2 = f->next;
        f->next = last->next;
        while(tmp2!=last) {
            node *tmp3 = tmp2;
            tmp2=tmp2->next;
            delete tmp3;
        }
    }
    usun_wartownika(first);
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    zadanie(first);
    wypisz(first);
}
