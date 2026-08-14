#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;
    
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }
    
    return n;
}

int main() {
    int numsSize, val;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    int nums[numsSize];

    printf("Enter %d elements:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    printf("Enter the value to remove (val): ");
    scanf("%d", &val);

    int k = removeElement(nums, numsSize, val);

    printf("\nOutput: %d, nums = [", k);
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]);
        if (i < k - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}