#include <stdio.h>

int LinearSearch(int arr[], int arrLength, int key) {
	int i;
	for(i = 0; i < arrLength; i++) {
		if(arr[i] == key) {
			return i;
		}	
	}	
	return -1;
}



int main(int argc, char const *argv[]) {
	
	int arr[] = {20, 12, 5, 14, 9, 31, 8, 2, 10, 0, 3};
	int arrLength = sizeof(arr) / sizeof(int);
	
	int searchKey = 31;
	int foundAt = LinearSearch(arr, arrLength, searchKey);
	if(foundAt == -1) {
		printf("%d not found \n", searchKey);
	} else {
		printf("%d found Index :: %d \n", searchKey, foundAt);
	}

	searchKey = 55;
	foundAt = LinearSearch(arr, arrLength, searchKey);
	if(foundAt == -1) {
		printf("%d not found \n", searchKey);
	} else {
		printf("%d found Index :: %d \n", searchKey, foundAt);
	}

	return 0;
}
