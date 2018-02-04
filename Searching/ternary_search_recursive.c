#include <stdio.h>

int recursive_ternary_search(int arr[], int searchKey, int left,int right) {
    if(left <= right) {
        int middle1 = left + (right - left) / 3;
        int middle2 = right - (right - left) / 3;
        if(arr[middle1] == searchKey) {
            return middle1;
        }
        if(arr[middle2] == searchKey) {
            return middle2;
        }
        if(searchKey < arr[middle1]) {
            return recursive_ternary_search(arr, searchKey, left, middle1 - 1);
        }
        else if(searchKey > arr[middle2]) {
            return recursive_ternary_search(arr, searchKey, middle2 + 1, right);
        }
        else {
            return recursive_ternary_search(arr, searchKey, middle1 + 1, middle2 - 1);
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    
    int arr[] = {0, 2, 3, 5, 8, 9, 10, 12, 14, 20, 31};
    int arrLength = sizeof(arr) / sizeof(int);
    
    int searchKey = 20;
    int foundAt = recursive_ternary_search(arr, searchKey, 0, arrLength - 1);
    if(foundAt == -1) {
        printf("%d not found \n", searchKey);
    } else {
        printf("%d found Index :: %d \n", searchKey, foundAt);
    }

    searchKey = 55;
    foundAt = recursive_ternary_search(arr, searchKey, 0, arrLength - 1);
    if(foundAt == -1) {
        printf("%d not found \n", searchKey);
    } else {
        printf("%d found Index :: %d \n", searchKey, foundAt);
    }

    return 0;
}

