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

node * roznica(node *first1, node *first2) {
   if(first1==NULL) return first2;
   if(first2==NULL) return first1;
   node *first3 = NULL , *last3 = NULL;
   while(first1!=NULL and first2!=NULL) {
        first1->val = first1->val-first2->val;
        if(first3==NULL) first3=last3=first1;
        else { last3->next = first1; last3 = first1; }
        first1=first1->next;
        first2=first2->next;
   }
    while(first2!=NULL) {
        first2->val*=-1;
        last3->next = first2, last3=first2;
        first2=first2->next;
    }
    return first3;
}

int main() {
    node *first1 = NULL, *first2 = NULL;
    stworz(first1,10);
    stworz(first2,5);
    wypisz(first1);
    wypisz(first2);
    wypisz(roznica(first1,first2));
    wypisz(first1);
    wypisz(first2);
}
