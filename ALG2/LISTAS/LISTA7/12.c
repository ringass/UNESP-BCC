#include <stdio.h>

void oddEvenSort(int arr[], int n) {
    int sorted = 0;

    
    while (!sorted) {
        sorted = 1;  

        
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;  
            }
        }

        
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;  
            }
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {5, 1, 4, 2, 8, 3, 7, 6, 9, 18};
    int n = 10;


    print(arr, n);

    oddEvenSort(arr, n);

    print(arr, n);

    return 0;
}
