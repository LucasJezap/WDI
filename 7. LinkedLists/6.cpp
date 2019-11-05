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
        p->val = 65+2*i;
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

void zadanie(node *&first, int x) {
    wstaw_wartownika(first);
    node *q=first, *p = first->next;
    while(p!=NULL and p->val!=x) { q=p, p=p->next; }
    if(p!=NULL) {
        q->next = p->next;
        delete p;
        p=q;
    }
    else {
        node *tmp = new node;
        tmp->val = x;
        tmp->next = NULL;
        q->next = tmp;
    }
    usun_wartownika(first);
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    zadanie(first,123);
    wypisz(first);
}
