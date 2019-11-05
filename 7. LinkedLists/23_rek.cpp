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
        p->val = 1000-x*3*i;
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
    if(first1==NULL) return first2;
    if(first2==NULL) return first1;
    if(first1->val>first2->val) {
        first2->next = scal(first1,first2->next);
        return first2;
    }
    else {
        first1->next = scal(first1->next,first2);
        return first1;
    }
}

int main() {
    srand(time(NULL));
    node *first1 = NULL;
    node *first2 = NULL;
    stworz(first1,5);
    stworz(first2,5);
    wypisz(first1);
    wypisz(first2);
    wypisz(scal(first1, first2));
}
