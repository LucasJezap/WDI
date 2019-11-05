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
    int x= rand()%50;
    node *p = NULL;
    while(i<N) {
        p = new node;
        p->val = 300-x*3*i;
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

node * scal(node *first1, node *first2) {
    node *first3 = NULL, *last = NULL;
    if(first1==NULL) return first2;
    if(first2==NULL) return first1;
    while(first1!=NULL and first2!=NULL) {
        if(first1->val>first2->val) {
            if(first3==NULL) {first3=last=first2; first2=first2->next;}
            else { last->next = first2; last = first2; first2=first2->next; }
        }
        else {
            if(first3==NULL) { first3=last=first1; first1=first1->next; }
            else { last->next = first1; last = first1; first1=first1->next; }
        }
    }
    if(first1==NULL) last->next = first2;
    if(first2==NULL) last->next = first1;
    return first3;
}

int main() {
    srand(time(NULL));
    node *first1 = NULL;
    node *first2 = NULL;
    stworz(first1,5);
    stworz(first2,7);
    wypisz(first1);
    wypisz(first2);
    wypisz(scal(first1, first2));
}
