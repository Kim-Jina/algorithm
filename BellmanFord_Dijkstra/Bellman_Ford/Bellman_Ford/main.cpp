#include <iostream>

using namespace std;

int w[5][5] = {	// edge (A,B,C,D,E)
	{ 0, -1, 4, 0, 0 },
	{ 0, 0, 3, 2, 2 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 5, 0, 0 },
	{ 0, 0, 0, -3, 0 }
};

void B_F(int *d){	// Bellman-Ford algorithm
	int s = 0;	// start point
	int v, u;	
	int i;		// index

	// initialize d
	d[s] = 0;
	for (i = s + 1; i < 5; i++){
		d[i] = 10000;
	}

	// relaxation step
	for (i = 1; i < 5; i++){
		for (u = 0; u < 5; u++){
			for (v = 0; v<5; v++){
				if (w[u][v] != 0 && d[v]>d[u] + w[u][v]){
					d[v] = d[u] + w[u][v];
				}
			}
		}
	}

	// report that a negative-weight cycle exits
	for (u = 0; u < 5; u++){
		for (v = 0; v < 5; v++){
			if (w[u][v] != 0 && d[v]>d[u] + w[u][v]){
				cout << "Negative-weight cycle exits " << endl;
				return;
			}
		}
	}
}
int main(void){
	int *d = new int[5];	// the shortest distance
	int i;					// index

	B_F(d);	// move to B_F function

	for (i = 0; i < 5; i++)
		cout << (char)(i + 'A') << " ";
	cout << endl;
	for (i = 0; i < 5; i++)
		cout << d[i] << " ";
	cout << endl;

	return 0;
}