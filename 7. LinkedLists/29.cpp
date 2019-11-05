#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct node {
 string val;
 node* next;
};

void stworz_cykl(node *&first, int N) {
    int i = 0;
    node *p = NULL;
    node *tmp;
    while(i<N) {
        p = new node;
        cin >> p->val;
        p->next = first;
        first = p;
        if(i==0) tmp = p;
        i++;
    }
    tmp->next = p;
}

void wypisz_cykl(node *first, int N) {
    int i=0;
    while(i<N) {
        cout << first->val << " -> ";
        first=first->next;
        i++;
    }
    cout << "itd..." << endl;
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

int dlugosc_cykl(node *first, node *tmp) {
    int dlugosc = 0;
    while(first!=tmp) {dlugosc++, first=first->next; }
    return dlugosc;
}

int pierwsza(string a) { return a[0]; }

int ostatnia(string a) { return a[a.size()-1]; }

bool wstaw(node *&first, string napis) {
    if(first==NULL) return false;
    node *p = first, *q = first->next;
    node *fast = first, *slow = first;
    while(true) {
        if(ostatnia(p->val)<pierwsza(napis) and ostatnia(napis)<pierwsza(q->val)) {
            node *x = new node;
            x->val = napis;
            p->next = x;
            x->next = q;
            first=x;
            return true;
        }
        p=q;
        q=q->next;
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast) break;
    }
    return false;
}
int main() {
    node *first = NULL;
    stworz_cykl(first,5);
    wypisz_cykl(first,5);
    string napis;
    cin >> napis;
    if(wstaw(first,napis)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
    wypisz_cykl(first,6);
}
