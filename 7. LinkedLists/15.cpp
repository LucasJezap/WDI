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
        p->val = rand()%10;
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
    wstaw_wartownika(first);
    bool powtorka;
    node *a = first, *b = first->next;
    while(b!=NULL) {
        powtorka = false;
        node *p = b->next, *q = b;
        while(p!=NULL) {
            if(p->val == b->val) {
                q->next = p->next;
                delete p;
                p=q;
                powtorka = true;
            }
            q=p;
            p=p->next;
        }
        if(powtorka) {
            a->next = b->next;
            delete b;
            b=a;
        }
        a=b;
        b=b->next;
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
