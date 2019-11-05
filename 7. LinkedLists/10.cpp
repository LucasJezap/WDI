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
        p->val = 1+rand()%10;
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
    if(first==NULL or first->next == NULL) return;
    wstaw_wartownika(first);
    node *p = first, *q = first->next, *r = first->next->next;
    while(r!=NULL) {
        if(r->val%q->val==0) {
            p->next = r;
            delete q;
            q=p;
        }
        p=q;
        q=r;
        r=r->next;
    }
    usun_wartownika(first);
}

int main() {
    srand(time(NULL));
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    zadanie(first);
    wypisz(first);
}
