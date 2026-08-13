#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }

    int totalSize = m + n;

    for (int i = 1; i < totalSize; i++)
    {
        int key = nums1[i];
        int j = i - 1;

        while (j >= 0 && nums1[j] > key)
        {
            nums1[j + 1] = nums1[j];
            j--;
        }
        nums1[j + 1] = key;
    }
}

int main()
  {
    int m, n;

    printf("Enter the number of elements in nums1 (m): ");
    scanf("%d", &m);

    printf("Enter the number of elements in nums2 (n): ");
    scanf("%d", &n);

    int nums1Size = m + n;
    int nums2Size = n;

    int nums1[nums1Size];
    int nums2[nums2Size];

    printf("\nEnter %d elements for nums1 (sorted):\n", m);
    for(int i = 0; i < m; i++)
    {
        printf("nums1[%d] = ", i);
        scanf("%d", &nums1[i]);
    }

    for(int i = m; i < nums1Size; i++)
    {
        nums1[i] = 0;
    }

    if (n > 0)
    {
        printf("\nEnter %d elements for nums2 (sorted):\n", n);
        for(int i = 0; i < n; i++)
        {
            printf("nums2[%d] = ", i);
            scanf("%d", &nums2[i]);
        }
    }

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    printf("\nOutput: [");
    for(int i = 0; i < nums1Size; i++)
    {
        printf("%d", nums1[i]);
        if (i < nums1Size - 1)
        {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
  }
