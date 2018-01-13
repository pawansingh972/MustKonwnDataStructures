#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void bubbleSort(int arr[], int arrLength) {
	int temp;
	for (int i = 0; i < arrLength - 1; ++i) {
		for (int j = 0; j < (arrLength - i - 1); ++j) {
			if(arr[j] > arr[j+1]) {
				SWAP(arr[j], arr[j+1], temp);
			}
		}
	}
	return;
}

void printArray(int arr[], int arrLength) {
	printf("[ ");
	for (int i = 0; i < arrLength; ++i) {
		((i != arrLength - 1) && printf("%d, ", arr[i])) || printf("%d", arr[i]);
	}
	printf(" ]");
}

int main(int argc, char const *argv[]) {

	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);

	bubbleSort(arr, arrLength);
	printArray(arr, arrLength);

	return 0;
}

