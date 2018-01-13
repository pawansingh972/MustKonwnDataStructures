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

void insertionSort(int arr[], int arrLength) {
	int temp, i, j;
	for (i = 1; i < arrLength; ++i) {
		int key = arr[i];
		for (j = i - 1; j >= 0 && key < arr[j]; --j) {
			if(arr[j] > key) {
				SWAP(arr[j], arr[j+1], temp);
			}
		}
	}
	return;
}

int main(int argc, char const *argv[]) {

	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);

	insertionSort(arr, arrLength);
	printArray(arr, arrLength);

	return 0;
}

