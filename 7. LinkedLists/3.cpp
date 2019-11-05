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
        p->val = rand()%100;
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

void usun(node *&first) {
    wstaw_wartownika(first);
    int i=1;
    node *q=first,*p=first->next;
    while(p!=NULL) {
        if(i%2==0) {
        q->next = p->next;
        delete p;
        p=q;
        }
        q=p;
        p=p->next;
        i++;
    }
    usun_wartownika(first);
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    usun(first);
    wypisz(first);
}
