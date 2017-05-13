#include <iostream>
#include <cstdlib>

using namespace std;

int Adj[5][5] = {			// edge (A, B, C, D, E) 
	{ 0, 10, 3, 0, 0 },
	{ 0, 0, 1, 2, 0 },
	{ 0, 4, 0, 8, 2 },
	{ 0, 0, 0, 0, 7 },
	{ 0, 0, 0, 9, 0 }
};

int QisEmpty(int size){		// function which check wheter Queue is empty
	if (size == 0)			// emtpy
		return 1;
	else					// not empty
		return 0;
}
void Min_Heapify(int* Q, int* d, int size, int i){	// Max Heapify
	int l = 2 * i + 1, r = 2 * i + 2;		// left and right
	int min = i, temp;						// min, temp

	if (l < size&&d[Q[l]] < d[Q[i]])	// left
		min = l;

	if (r < size&&d[Q[r]] < d[Q[min]])			// right
		min = r;

	if (min != i){								// exchage Q[i] with Q[min]
		temp = Q[i];
		Q[i] = Q[min];
		Q[min] = temp;
		Min_Heapify(Q, d, size, min);			// go to Min_Heapify function
	}
}
int Extract_Min(int* Q, int* d, int size){
	int min;	// minimum

	for (int i = size - 1; i >= 0; i--)	// go to Min_Heapify function 
		Min_Heapify(Q, d, size, i);

	min = Q[0];				// extract minimum
	Q[0] = Q[size - 1];		// Q[0] is Q[size-1]

	return min;
}
void Dijkstra(int* Q, int* S, int* d){
	int Q_size = 5;	// size of queue
	int s = 0;		// index of single source
	int u, v;		// start point, end point
	int index = 0;	// index of S

	// initialize d
	d[s] = 0;
	for (int i = s + 1; i < 5; i++)
		d[i] = 10000;

	//initialize Q
	for (int i = 0; i < 5; i++)
		Q[i] = i;

	while (!QisEmpty(Q_size)){
		u = Extract_Min(Q, d, Q_size--);	// extract minimum by using min heap
		S[index++] = u;						// store u in S
		for (v = 0; v<5; v++){				// calculate the shortest distance
			if (Adj[u][v] != 0 && d[v]>d[u] + Adj[u][v]){
				d[v] = d[u] + Adj[u][v];
			}
		}
	}
}
int main(void){
	int *Q = new int[5];		// Queue
	int *S = new int[5];		// single source
	int *d = new int[5];		// distance
	int i;						// index

	Dijkstra(Q, S, d);	// move to Dijkstra function

	// print result
	cout << "S : ";
	for (i = 0; i < 5; i++)
		cout << (char)(S[i]+'A') << " ";
	cout << endl << "==================" << endl;
	
	for (i = 0; i < 5; i++)
		cout << (char)(i + 'A') << " ";
	cout << endl;
	for (i = 0; i < 5; i++)
		cout << d[i] << " ";
	cout << endl;

	return 0;
}