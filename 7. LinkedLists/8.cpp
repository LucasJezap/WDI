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

void odwroc(node *&first) {
    if(first!=NULL) {
        node *a,*b;
        a = first;
        while(a->next!=NULL) {
            b = a->next;
            a->next = b->next;
            b->next = first;
            first = b;
        }
    }
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    odwroc(first);
    wypisz(first);
}
