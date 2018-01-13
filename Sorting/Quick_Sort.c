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

int Partition(int arr[], int left, int right) {
	int pivot = left;
	int i, j, k, temp;

	i = left + 1;
	j = right;

	while(i <= right && arr[i] < arr[pivot]) {
		i++;
	}

	while(j >= left && arr[j] > arr[pivot]) {
		j--;
	}
	
	k = i; 
	while( k < j)  {
		if(arr[k+1] < arr[pivot]) {
			SWAP(arr[i], arr[k+1], temp);
			i++;
		}
		k++;
	}

	i--;
	SWAP(arr[i], arr[pivot], temp);

	return i;
}

void QuickSort(int arr[], int left, int right) {
	if(left < right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
	return;
}

int main(int argc, char const *argv[]) {
	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, arrLength-1);
	printArray(arr, arrLength);

	return 0;
}
