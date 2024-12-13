#include <stdio.h>

// Function to find the majority element
int majorityElement(int nums[], int size) {
    int candidate = -1, count = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    // If count > size / 2, return the candidate
    if (count > size / 2) {
        return candidate;
    } else {
        return -1; // No majority element
    }
}

int main() {
    int nums[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, size);
    if (result != -1) {
        printf("Majority element: %d\n", result);
    } else {
        printf("No majority element\n");
    }

    return 0;
}
