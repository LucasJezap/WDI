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
        p->val = rand()%100-rand()%100;
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

int zadanie(node *&first1, node *&first2, node *&first3) {
   wstaw_wartownika(first1);
   node *p = first1, *q = first1->next;
   node *last2 = NULL, *last3 = NULL;
   int ilosc = 0;
   while(q!=NULL) {
        if(q->val%2==0 and q->val>0) {
            if(first2==NULL) first2 = last2 = q;
            else { last2->next = q; last2 = q; }
        }
        if(abs(q->val)%2==1 and q->val<0) {
            if(first3==NULL) first3 = last3 = q;
            else { last3->next = q; last3 = q; }
        }
        if(q->val == 0 or (q->val>0 and q->val%2==1) or (q->val<0 and abs(q->val)%2==0)) {
            p->next = q->next;
            delete q;
            q=p;
            ilosc++;
        }
        p=q;
        q=q->next;
   }
   if(last2!=NULL) last2->next = NULL;
   if(last3!=NULL) last3->next = NULL;
   usun_wartownika(first1);
   return ilosc;
}

int main() {
    srand(time(NULL));
    node *first1 = NULL, *first2 = NULL, *first3 = NULL;
    stworz(first1,10);
    wypisz(first1);
    cout << zadanie(first1,first2,first3) << endl;
    wypisz(first1);
    wypisz(first2);
    wypisz(first3);
}
