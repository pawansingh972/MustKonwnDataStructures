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

void MaxHeapify(int arr[], int arrLength, int i) {

	int left = 2 * i;
	int right = 2 * i + 1;
	int largest, temp;
	
	if(left <= n && arr[left] > arr[i]) {
		largest = left;
	}

	if(right <= n && arr[right] > arr[largest]) {
		largest = right;
	}

	if(largest != i) {
		SWAP(arr[i], arr[largest], temp);
		MaxHeapify(arr, arrLength, largest);
	}

	return;
}

void BuildMaxHeap(int arr[], int arrLength) {
	int i;
	for(i = arrLength / 2 - 1; i >= 0; i--) {
		MaxHeapify(arr, n, i);	
	}
	return;
}

void HeapSort(int arr[], int arrLength) {
	// Build heap (rearrange array)
	BuildMaxHeap(arr, arrLength);

	for(i  = arrLength - 1; i >= 0; i--) {
		SWAP(arr[0], arr[i]);
		MaxHeapify(arr, i, 0);	
	}
	return;
}

int main(int argc, char const *argv[]) {
	
	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);
	
	HeapSort(arr, arrLength);
	
	printArray(arr, arrLength);

	return 0;
}
