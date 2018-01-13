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

void Merge(int arr[], int low, int middle, int up) {

	int i = low, j = middle+1, k = low;
	int temp;
	int b[100];
	int m = 0;

	while(i <= middle && j <= up) {
		if(arr[i] < arr[j]) {
			b[k++] = arr[i++];	
		} else {
			b[k++] = arr[j++];
		}
	}

	for(m = i; m <= middle ; ++m) {
		b[k++] = arr[m];	
	}

	for(m = j; m <= up ; ++m) {
		b[k++] = arr[m];	
	}

	for(m = low; m <= up; ++m) {
		arr[m] = b[m];
	}

	return;
}

void MergeSort(int arr[], int low, int up) {
	if(low < up) {
		int middle = (low + up) / 2;
		MergeSort(arr, low, middle);
		MergeSort(arr, middle+1, up);
		Merge(arr, low, middle, up);
	}
	return;
}

int main(int argc, char const *argv[]) {

	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);

	MergeSort(arr, 0, arrLength-1);
	printArray(arr, arrLength);

	return 0;
}
