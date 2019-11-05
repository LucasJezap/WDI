#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node {
 string val;
 node* next;
};

void stworz(node *&first, int N) {
    int i = 0;
    node *p = NULL;
    while(i<N) {
        p = new node;
        p->val = 65+2*i;
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

bool wieksza_waga(string a, string b) {
    int i=0;
    while(a[i]!='\0' and b[i]!='\0') {
        if(b[i]>a[i]) return false;
        if(b[i]<a[i]) return true;
        i++;
    }
    if(a[i]!='\0' and b[i]!='\0') return true;
    else return false;
}

bool rowna(string a, string b) {
    int i=0;
    while(a[i]!='\0' and b[i]!='\0') {
        if(a[i]!=b[i]) return false;
        i++;
    }
    if(a[i]=='\0' and b[i]=='\0') return true;
    return false;
}

bool zadanie(node *&first, string x) {
    wstaw_wartownika(first);
    node *q = first, *p = first->next;
    while(p!=NULL and wieksza_waga(p->val,x)) { q=p, p=p->next; }
    if(!rowna(x,p->val)) {
        node *tmp = new node;
        tmp->val = x;
        q->next = tmp;
        tmp->next = p;
        usun_wartownika(first);
        return true;
    }
    else {
        usun_wartownika(first);
        return false;
    }
}

int main() {
    node *first = NULL;
    stworz(first,10);
    wypisz(first);
    cout << zadanie(first,"F") << endl;
    wypisz(first);
}
