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

// To heapify a subtree rooted with node i which is
// an index in arr[]. arrLength is size of heap
void MaxHeapify(int arr[], int arrLength, int i) {

	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	int temp;

	if(left < arrLength && arr[left] > arr[i]) {
		largest = left;
	}

	if(right < arrLength && arr[right] > arr[largest]) {
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
		MaxHeapify(arr, arrLength, i);	
	}
	return;
}

void HeapSort(int arr[], int arrLength) {
	int i, temp;

	// Build heap (rearrange array)
	BuildMaxHeap(arr, arrLength);

	for(i = arrLength - 1; i >= 0; i--) {
		SWAP(arr[i], arr[0], temp);
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
