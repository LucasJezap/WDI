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

bool zadanie(node *first1, node *first2) {
    node *tmp1 = first1, *tmp2 = first2;
    int dlugosc1 = 0, dlugosc2 = 0;
    while(tmp1) { dlugosc1++; tmp1=tmp1->next; }
    while(tmp2) { dlugosc2++; tmp2=tmp2->next; }
    node *p,*q;
    if(dlugosc1>dlugosc2) { p = first1, q = first2; }
    else { p = first2, q = first1; }
    while(p!=NULL) {
        if(p->val == q->val) {
            tmp1 = p, tmp2 = q;
            while(tmp1!=NULL and tmp2!=NULL and tmp1->val==tmp2->val) { tmp1=tmp1->next, tmp2=tmp2->next; }
            if(tmp2==NULL) return true;
        }
        p=p->next;
    }
    return false;
}

int main() {
    srand(time(NULL));
    node *first1 = NULL;
    node *first2 = NULL;
    stworz(first1,4);
    stworz(first2,12);
    wypisz(first1);
    wypisz(first2);
    if(zadanie(first1,first2)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
}
