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

bool binarny(int x) {
    int jedynki = 0;
    while(x>0) {
        if(x%2==1) jedynki++;
        x/=2;
    }
    if(jedynki%2==1) return true;
    else return false;
}

void zadanie(node *&first) {
    if(first==NULL) return;
    wstaw_wartownika(first);
    node *p = first, *q = first->next;
    while(q!=NULL) {
        if(binarny(q->val)) {
            p->next = q->next;
            delete q;
            q=p;
        }
        p=q;
        q=q->next;
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
