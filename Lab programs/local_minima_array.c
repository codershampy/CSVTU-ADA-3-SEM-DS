#include <stdio.h>

void findLocalMinima(int arr[], int n) {
    if (n == 1 || arr[0] < arr[1]) {
        printf("Local minima found at index 0 with value %d\n", arr[0]);
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("Local minima found at index %d with value %d\n", i, arr[i]);
        }
    }
    if (arr[n - 1] < arr[n - 2]) {
        printf("Local minima found at index %d with value %d\n", n - 1, arr[n - 1]);
    }
}

int main() {
    int arr[] = {5, 3, 4, 2, 6, 8, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLocalMinima(arr, n);

    return 0;
}
