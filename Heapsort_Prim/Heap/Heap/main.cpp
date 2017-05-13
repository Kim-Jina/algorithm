#include <iostream>
#include <cstdlib>

using namespace std;

void Max_Heapify(int* A, int size, int i){	// Max Heapify
	int l = 2 * i + 1, r = 2 * i + 2;		// left and right
	int max, temp;							// max, temp

	if (l < size&&A[l] > A[i])				// left
		max = l;
	else
		max = i;

	if (r < size&&A[r] > A[max])			// right
		max = r;

	if (max != i){							// exchage A[i] with A[max]
		temp = A[i];
		A[i] = A[max];
		A[max] = temp;
		Max_Heapify(A, size, max);			// go to Max_Heapify function
	}
}
void Build_Max_Heap(int* A, int size){	// Build max heap
	for (int i = size / 2; i >= 0; i--)
		Max_Heapify(A, size, i);		// go to Max_Heapify function
}
void HeapSort(int* A, int size){		// Heap sort
	int temp;			// temp

	Build_Max_Heap(A, size);		// go to Build_Max_Heap function

	for (int i = size; i > 0; i--){	// exchange A[0] with A[i-1]
		cout << A[0] << " ";
		temp = A[0];
		A[0] = A[i - 1];
		A[i - 1] = temp;
		Max_Heapify(A, i - 1, 0);	// go to Max_Heapify function
	}
	cout << endl;
}
int main(void){
	int *A;				// array
	int size;			// size

	// enter the size
	cout << "Enter the size : ";
	cin >> size;
	
	// dynamic allocation
	A = (int*)malloc(sizeof(int)*size);
	
	// Enter the array
	cout << "Enter the array : ";
	for (int i = 0; i < size; i++)
		cin >> A[i];

	//////////// Heap sort //////////////
	cout << "Result : ";
	HeapSort(A, size);

	free(A);	// free dynamic allocation

	return 0;
}