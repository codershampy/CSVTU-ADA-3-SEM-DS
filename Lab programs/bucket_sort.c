#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bucketSort(float arr[], int n) {
  
    int i, j;
    float minValue = arr[0];
    float maxValue = arr[0];
    
    for (i = 1; i < n; i++) {
        if (arr[i] < minValue) minValue = arr[i];
        if (arr[i] > maxValue) maxValue = arr[i];
    }

    int bucketCount = n;
    float range = maxValue - minValue;
    struct Bucket {
        float* values;
        int size;
    } buckets[bucketCount];
    
    for (i = 0; i < bucketCount; i++) {
        buckets[i].values = (float*)malloc(n * sizeof(float));
        buckets[i].size = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = (int)((arr[i] - minValue) * (bucketCount - 1) / range);
        buckets[bucketIndex].values[buckets[bucketIndex].size++] = arr[i];
    }

    for (i = 0; i < bucketCount; i++) {
        if (buckets[i].size > 0) {
    
            for (j = 1; j < buckets[i].size; j++) {
                float key = buckets[i].values[j];
                int k = j - 1;
                while (k >= 0 && buckets[i].values[k] > key) {
                    buckets[i].values[k + 1] = buckets[i].values[k];
                    k--;
                }
                buckets[i].values[k + 1] = key;
            }
        }
    }
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    float arr[] = {0.42, 0.32, 0.53, 0.71, 0.24, 0.56, 0.71};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);
    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

