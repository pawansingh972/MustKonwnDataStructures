#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void printArray(int arr[], int arrLength) {
	int i;
	printf("[ ");
	for (i = 0; i < arrLength; ++i) {
		((i != arrLength - 1) && printf("%d, ", arr[i])) || printf("%d", arr[i]);
	}
	printf(" ]");
}

void selectionSort(int arr[], int arrLength) {
	int temp, i, j;
	for (i = 0; i < arrLength - 1; ++i) {
		int min = i;
		for (j = i + 1; j < arrLength; ++j) {
			if(arr[min] > arr[j]) {
				min = j;
			}
		}
		if(i != min) {
			SWAP(arr[min], arr[i], temp);
		}
	}
	return;
}

int main(int argc, char const *argv[]) {

	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);

	selectionSort(arr, arrLength);
	printArray(arr, arrLength);

	return 0;
}

