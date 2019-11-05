#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node {
 int val1,val2;
 node* next;
};

void stworz(node *&first, int N) {
    int i = 0;
    node *p = NULL;
    while(i<N) {
        p = new node;
        p->val1 = rand()%90;
        int x = p->val1;
        while(x<=p->val1) x=rand()%100;
        p->val2 = x;
        p->next = first;
        first = p;
        i++;
    }
}

void wypisz(node *first) {
    while(first!=NULL) {
        cout << "<" << first->val1 << "," << first->val2 << ">" << " -> ";
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

void zadanie(node *first) {
    if(first==NULL) return;
    node *p = first, *q, *r;
    int usuniete;
    while(p!=NULL) {
        usuniete = 1;
        while(usuniete!=0) {
        usuniete = 0;
        q=p->next, r=p;
            while(q!=NULL) {
                if(q->val2>p->val2 and q->val1>p->val1 and q->val1<p->val2) p->val2 = q->val2;
                else if(q->val1<p->val1 and q->val2>p->val1 and q->val2<p->val2) p->val1 = q->val1;
                else if(q->val1<p->val1 and q->val2>p->val2) {p->val1 = q->val1, p->val2 = q->val2; }
                if(!(q->val1 > p->val2 or q->val2<p->val1)) {
                    r->next = q->next;
                    delete q;
                    q=r;
                    usuniete++;
                }
                r=q;
                q=q->next;
            }
        }
        p=p->next;
    }
}

int main() {
    srand(time(NULL));
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    zadanie(first);
    wypisz(first);
}
