#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;
struct punkt{
	int x,y;
};
const int N = 50;


bool czy_kwadrat(punkt p1,punkt p2,punkt p3,punkt p4) {
	if(p1.x==p4.x and p1.y==p2.y and p2.x==p3.x and p3.y==p4.y) return true;
	return false;
}

bool czy_pusty(punkt p1,punkt p2,punkt p3,punkt p4,punkt tab[]) {
	for(int i=0;i<N;i++) {	
			if(tab[i].x>p1.x and tab[i].x<p2.x and tab[i].y>p1.y and tab[i].y<p4.y) return false;
			if(tab[i].x>p1.x and tab[i].x<p2.x and tab[i].y<p1.y and tab[i].y>p4.y) return false;
			if(tab[i].x<p1.x and tab[i].x>p2.x and tab[i].y<p1.y and tab[i].y>p4.y) return false;
			if(tab[i].x<p1.x and tab[i].x>p2.x and tab[i].y>p1.y and tab[i].y<p4.y) return false;
	}
	return true;
}

bool kwadrat(punkt tab[]) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			for(int k=0;k<N;k++) {
				for(int t=0;t<N;t++) {
					if(i!=j and i!=k and i!=t and j!=k and j!=t and k!=t)
						if(czy_kwadrat(tab[i],tab[j],tab[k],tab[t]) and czy_pusty(tab[i],tab[j],tab[k],tab[t],tab)) {
							return true;
						}
				}
			}
		}
	}
	return false;
}



int main() {
	srand(time(NULL));
	punkt tab[N];
	for(int i=0;i<N;i++) {
		tab[i].x = rand()%32;
		tab[i].y = rand()%32;
		//cout << "(" << tab[i].x << "," << tab[i].y << ")" << endl;
	} 
	if(kwadrat(tab)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
}
