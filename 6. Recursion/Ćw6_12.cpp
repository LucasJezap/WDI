#include <iostream>

using namespace std;

void rozklad(int k,string a,int czynnik) {
    if(k==0) { cout << a << endl; }
    else {
        for(int i=czynnik;i<=k;i++) rozklad(k-i,a+to_string(i)+" ",i);
    }
}


int main() {
	int k;
	cin >> k;
	rozklad(k,"",1);
}
