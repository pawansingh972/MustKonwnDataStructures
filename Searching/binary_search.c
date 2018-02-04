#include <stdio.h>

#define COMPARE(x, y) ( ((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1 )

int BinarySearch(int arr[], int searchKey, int arrLength) {
	int middle;
	int left = 0;
	int right = arrLength - 1;

	while(left <= right) {
		middle = (left + right) / 2;
		switch(COMPARE(arr[middle], searchKey)) {
			case -1: 
				left = middle + 1;
				break;
			case 0:
				return middle;
			case 1:
				right = middle -1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	
	int arr[] = {0, 2, 3, 5, 8, 9, 10, 12, 14, 20, 31};
	int arrLength = sizeof(arr) / sizeof(int);
	
	int searchKey = 20;
	int foundAt = BinarySearch(arr, searchKey, arrLength);
	if(foundAt == -1) {
		printf("%d not found \n", searchKey);
	} else {
		printf("%d found Index :: %d \n", searchKey, foundAt);
	}

	searchKey = 55;
	foundAt = BinarySearch(arr, searchKey, arrLength);
	if(foundAt == -1) {
		printf("%d not found \n", searchKey);
	} else {
		printf("%d found Index :: %d \n", searchKey, foundAt);
	}

	return 0;
}
