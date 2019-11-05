#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int N = 8;
bool koniec = false;

void wypisz(int tab[N][N]) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cout << setw(4) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

bool mozliwe(int t[N][N], int i, int w, int k, int &w1, int &k1){
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    w1 = w + dx[i];
    k1 = k + dy[i];
    return w1 >= 0 && w1 < N && k1 >= 0 && k1 < N && t[w1][k1] == 0;
}

void skok(int t[N][N], int w, int k, int n){
    t[w][k] = n;
    if(n == N * N){
            wypisz(t);
            koniec = true;
    }
    else{
        for(int i = 0; i < 8 && koniec == false; i++){
            int k1, w1;
            if(mozliwe(t, i, w, k, w1, k1)) skok(t, w1, k1, n + 1);
        }
    }
    t[w][k] = 0;
}
int main() {
    srand(time(NULL));
    int t[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) t[i][j] = 0;
    int w,k;
    cin >> w >> k;
    skok(t,w,k,1);
}
