#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
            if (count > numsSize / 2) {
                return nums[i];
            }
        } else {
            count = 1;
        }
    }
    
    return nums[0];
}

int main() {
    int numsSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    int nums[numsSize];

    printf("Enter %d elements:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    int majority = majorityElement(nums, numsSize);

    printf("\nOutput: %d\n", majority);

    return 0;
}