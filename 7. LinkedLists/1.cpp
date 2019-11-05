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
        p->val = i*i+2*i-5;
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

bool czy_nalezy(node *first, int x) {
    if(first==NULL) return false;
    while(first!=NULL) {
        if(first->val == x) return true;
        first=first->next;
    }
    return false;
}

void dodaj(node *&first, int x) {
    wstaw_wartownika(first);
    node *p,*q;
    p=first->next;
    q=first;
    while(p!=NULL and p->val>x) {
        q=p;
        p=p->next;
    }
    if(p!=NULL and p->val == x) {usun_wartownika(first); return; }
    node *r = new node;
    r->val = x;
    q->next = r;
    r->next = p;
    usun_wartownika(first);
}

void usun(node *&first,int x) {
    if(first==NULL) return;
    wstaw_wartownika(first);
    node *q=first,*p=first->next;
    while(p!=NULL and p->val!=x) {
        q=p,p=p->next;
    }
    if(p!=NULL) {
        q->next = p->next;
        delete p;
        p=q;
    }
    usun_wartownika(first);
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    cout << czy_nalezy(first,30) << endl;
    wypisz(first);
    dodaj(first,-100);
    wypisz(first);
    usun(first,94);
    wypisz(first);
}
