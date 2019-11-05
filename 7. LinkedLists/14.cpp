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

node * zadanie(node *first) {
    if(first==NULL) return NULL;
    node * pocz[10], * koniec[10];
    for(int i=0;i<10;i++) { pocz[i]=NULL,koniec[i]=NULL; }
    while(first!=NULL) {
        int x = (first->val)%10;
        if(pocz[x]==NULL) {
            pocz[x] = koniec[x] = first;
        }
        else {
            koniec[x]->next = first;
            koniec[x] = first;
        }
        first=first->next;
    }
    node *first3 = NULL, *last3 = NULL;
    for(int i=0;i<10;i++) {
        while(pocz[i]!=NULL) {
            if(first3==NULL) first3 = last3 = pocz[i];
            else { last3->next = pocz[i] , last3 = pocz[i]; }
            if(pocz[i]==koniec[i]) break;
            pocz[i] = pocz[i]->next;
        }
    }
    last3->next = NULL;
    return first3;
}

int main() {
    srand(time(NULL));
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    wypisz(zadanie(first));
}
