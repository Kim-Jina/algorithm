#include <iostream>
#include <cstdlib>

using namespace std;

int QisEmpty(int size){											// function which check wheter Queue is empty
	if (size == 0)			// emtpy
		return 1;
	else					// not empty
		return 0;
}
void Min_Heapify(int* Q, int* key, int size, int i){	// Max Heapify
	int l = 2 * i + 1, r = 2 * i + 2;		// left and right
	int min = i, temp;						// min, temp

	if (l < size&&key[Q[l]] < key[Q[i]])	// left
		min = l;

	if (r < size&&key[Q[r]] < key[Q[min]])			// right
		min = r;

	if (min != i){								// exchage Q[i] with Q[min]
		temp = Q[i];
		Q[i] = Q[min];
		Q[min] = temp;
		Min_Heapify(Q, key, size, min);			// go to Min_Heapify function
	}
}
int Extract_Min(int* Q, int* key, int size){
	int min;	// minimum

	for (int i = size - 1; i >= 0; i--)	// go to Min_Heapify function 
		Min_Heapify(Q, key, size, i);

	min = Q[0];				// extract minimum
	Q[0] = Q[size - 1];		// Q[0] is Q[size-1]
	
	return min;
}
int check_vertex(int* Q, int size, int v){
	int check = 0;		// check
	
	for (int i = 0; i < size; i++){ // find vertex
		if (Q[i] == v){
			check = 1;
			break;
		}
	}

	if (check == 0)	// not exist
		return 0;
	else			// exist
		return 1;
}
void prim(int** G, int* Q, int* key, int* pie, int size, int start){	// Prim algorithm
	int Q_size = size;	// Q's size
	int u, v, i;		// index

	// initialize key, pie, Q
	for (i = 0; i < size; i++){
		key[i] = 10000000;			// infinite
		pie[i] = 0;					// zero
		Q[i] = i;					// i
	}

	key[start] = 0;					// starting key

	while (!QisEmpty(Q_size)){
		u = Extract_Min(Q, key, Q_size--);				// extract minimum
		for (v = 0; v < size; v++){						// find values of key and pie
			if (check_vertex(Q, Q_size, v) == 1 && G[u][v] != 0 && G[u][v] < key[v]){
				key[v] = G[u][v];
				pie[v] = u;
			}
		}
	}

	// print key's values
	for (int i = 0; i < size; i++)
		cout << key[i] << " ";
	cout << endl;
}
int main(void){
	int** G;				// graph
	int *Q, *key, *pie;		// priority queue, key, pie
	int size, start;		// size, start

	// Enter the size and start
	cout << "Enter the size: ";
	cin >> size;
	cout << "Enter the start: ";
	cin >> start;

	// dynamic allocation
	G = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(sizeof(int)*size);
	Q = (int*)malloc(sizeof(int)*size);
	key = (int*)malloc(sizeof(int)*size);
	pie = (int*)malloc(sizeof(int)*size);

	// make graph
	cout << "<Graph>" << endl;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cin >> G[i][j];
		}
	}

	/////////// Prim ////////////////////
	cout << "<Prim's algorithm>" << endl;
	prim(G, Q, key, pie, size, start);

	// free dynamic allocation
	for (int i = 0; i < size; i++)
		free(G[i]);
	free(G);
	free(Q);
	free(key);
	free(pie);

	return 0;
}