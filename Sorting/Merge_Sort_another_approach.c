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


// Merges two subarrays of arr[].
// First subarray is 'arr[low..middle]'
// Second subarray is 'arr[middle+1..up]'

void Merge(int arr[], int low, int middle, int up) {

	int i, j, k;
	int left_array_length = middle - low + 1;
	int right_array_length = up - middle;
	int left_array[left_array_length], right_array[right_array_length];
	
	for(i = 0; i < left_array_length; i++) {
		left_array[i] = arr[low + i];	
	}

	for(i = 0; i < right_array_length; i++) {
		right_array[i] = arr[middle + 1 + i];	
	}

	i = 0;
	j = 0;
	k = low;
	while(i < left_array_length && j < right_array_length) {
		if(left_array[i] < right_array[j]) {
			arr[k++] = left_array[i++];
		} else {
			arr[k++] = right_array[j++];
		}
	}

	while(i < left_array_length) {
		arr[k++] = left_array[i++];
	}

	while(j < right_array_length) {
		arr[k++] = right_array[j++];
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
