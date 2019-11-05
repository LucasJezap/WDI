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
        p->val = rand()%10;
        p->next = first;
        first = p;
        i++;
    }
}

void wypisz(node *first) {
    while(first!=NULL) {
        cout << first->val << " ";
        first=first->next;
    }
    cout << endl;
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

void zwieksz(node *&first,int &nadmiar, node *tmp) {
    if(first==NULL) return;
    zwieksz(first->next,nadmiar,tmp);
    if(first->next == NULL) {
        if(first->val == 9) { first->val = 0, nadmiar = 1; }
        else first->val++;
    }
    else {
        if(nadmiar == 1) {
            if(first->val == 9) { first->val = 0, nadmiar = 1;}
            else { first->val++, nadmiar = 0; }
            if(first  == tmp) {
                node *p = new node;
                p->val = 1;
                p->next = first;
                first = p;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    int nadmiar = 0;
    zwieksz(first,nadmiar,first);
    wypisz(first);
}
