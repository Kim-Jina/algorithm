#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge_f(int arr[], int left, int mid, int right){	// fuction which merge array
	int t_arr[100000] = {};					// temp array
	int l_value = left, m_value = mid + 1;	// left value, right value, middle value
	int i = left, j;						// index

	// compare left side of array and right side of array
	while (l_value <= mid&&m_value <= right){
		if (arr[l_value] < arr[m_value])	// if left side of array is less than right side of array
			t_arr[i++] = arr[l_value++];	// save left side of array into t_arr
		else								// if left side of array is more than right side of array
			t_arr[i++] = arr[m_value++];	// save right side of array into t_arr
	}

	if (l_value>mid){						// if right side of array exists
		for (j = m_value; j <= right; j++)	// save right side of array into t_arr
			t_arr[i++] = arr[j];
	}
	else{									// if left side of array exists
		for (j = l_value; j <= mid; j++)	// save left side of array into t_arr
			t_arr[i++] = arr[j];
	}

	for (j = left; j <= right; j++)					// save t_arr into arr
		arr[j] = t_arr[j];
}
void seperate_f(int arr[], int left, int right){		// function which sperate array
	int mid;		// middle position of array

	// start seperating array
	if (left < right){						// if left value is less than right value
		mid = (left + right) / 2;			// mid is an average between left and right
		seperate_f(arr, left, mid);			// seperate left side of array
		seperate_f(arr, mid + 1, right);	// seperate right side of array
		merge_f(arr, left, mid, right);		// merge the array
	}
}
int main(void){

	int arr[100000] = {};								// array
	int c, s;											// choose method, size
	int i;												// index;
	clock_t s_time, e_time;								// starting time, end time

	// input size
	while (1){
		printf("input size : ");
		scanf("%d", &s);
		if (s>2 && s <= 100000)
			break;
	}

	// choose the case
	while (1){
		printf("choose the case (1. the best case, 2. the worst case, 3. the average case): ");
		scanf("%d", &c);
		if (c > 0 && c < 4)
			break;
	}

	if (c == 1){					//  the best case
		for (i = 0; i < s; i++)
			arr[i] = i + 1;
	}
	else if (c == 2){				// the worst case
		for (i = 0; i < s; i++)
			arr[i] = s - i;
	}
	else{							// the average case
		for (i = 0; i < s; i++)
			arr[i] = (rand() % s) + 1;
	}
	
	// print array before sorting
	printf("<before sorting>\n");
	for (i = 0; i < s; i++)
		printf("%d ", arr[i]);
	printf("\n");

	s_time = clock();				// measure starting time
	// start merge sort
	seperate_f(arr, 0, s - 1);		// go to seperate_f function
	e_time = clock();				// measure ending time
	
	// print array after sorting
	printf("<after sorting>\n");
	for (i = 0; i < s; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("%.10f\n", ((double)(e_time - s_time)) / CLOCKS_PER_SEC);	// print running time

	return 0;
}