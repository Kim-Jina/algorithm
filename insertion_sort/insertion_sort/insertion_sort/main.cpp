#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

	int arr[100000] = {};								// array
	int temp, c, s;										// swap integer, choose method, size
	int i, j;											// index;
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

	// insertion sort
	for (i = 1; i < s; i++){
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--){
				arr[j + 1] = arr[j];
				arr[j] = temp;
		}
	}
	
	e_time = clock();				// measure ending time
	
	// print array after sorting
	printf("<after sorting>\n");
	for (i = 0; i < s; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	// print running time
	printf("%.10f\n", ((double)(e_time - s_time))/CLOCKS_PER_SEC);

	return 0;
}