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
    int x = rand()%50;
    node *p = NULL;
    while(i<N) {
        p = new node;
        p->val = 200-3*x-5*i;
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

int zadanie(node *&first1, node *&first2) {
    if(first1==NULL or first2==NULL) return 0;
    wstaw_wartownika(first1), wstaw_wartownika(first2);
    bool powtorka;
    int ilosc = 0;
    node *b = first1->next, *a=first1;
    while(b!=NULL) {
        powtorka = false;
        node *p = first2->next, *q=first2;
        while(p!=NULL and p->val<=b->val) {
            if(p->val == b->val) {
                powtorka = true;
                q->next = p->next;
                delete p;
                p=q;
                ilosc++;
            }
            q=p,p=p->next;
        }
        if(powtorka) {
            a->next = b->next;
            delete b;
            b=a;
            ilosc++;
        }
        a=b;
        b=b->next;
    }
    usun_wartownika(first1), usun_wartownika(first2);
    return ilosc;
}

int main() {
    srand(time(NULL));
    node *first1 = NULL, *first2 = NULL;
    stworz(first1,5);
    stworz(first2,5);
    wypisz(first1);
    wypisz(first2);
    cout << zadanie(first1, first2) << endl;
    wypisz(first1);
    wypisz(first2);
}
