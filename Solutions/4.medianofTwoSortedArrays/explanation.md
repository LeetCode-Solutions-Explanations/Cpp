# Median of Two Sorted Arrays

## Problem Description

The **Median of Two Sorted Arrays** problem requires finding the median of two sorted arrays. The arrays can have different lengths, and the solution should be efficient, ideally better than **O((m + n))** where `m` and `n` are the lengths of the two arrays.

Given:

- `nums1 = [1, 3]`
- `nums2 = [2]`
- Expected Output: `2.0` because the merged array `[1, 2, 3]` has `2` as the median.

---

## Key Concepts

### 1. **Binary Search for Efficient Partitioning**

To efficiently find the median, we can use **binary search** to partition one of the arrays at the correct point such that:

- The left halves of both arrays combined have the same number of elements as the right halves.
- All elements in the left half are less than or equal to all elements in the right half.

This way, we avoid merging the arrays and achieve a time complexity of **O(log(min(m, n)))** by searching in the smaller array.

### 2. **Handling Edge Cases**

To partition correctly, we handle edge cases by defining:

- `INT_MIN` for elements that would otherwise be "left of the start" of an array.
- `INT_MAX` for elements "right of the end" of an array.

These help us manage empty subarrays and make comparisons at boundaries more straightforward.

### 3. **Median Calculation Based on Total Length**

After finding the correct partition:

- If the combined length of the arrays is **even**, the median is the average of the largest element on the left side and the smallest element on the right side.
- If the length is **odd**, the median is the largest element on the left side.

---

## Step-by-Step Solution

Here’s a breakdown of the solution code:

### Code

```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        while (left <= right)
        {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                right = partition1 - 1;
            }
            else
            {
                left = partition1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};
```

### Explanation

1. **Check Array Sizes**:

   - If `nums1` is larger than `nums2`, swap them. We want to perform binary search on the smaller array for efficiency.

2. **Binary Search on `nums1`**:
   - We initialize `left = 0` and `right = m` (length of `nums1`).
   - Using `partition1 = (left + right) / 2`, we find the midpoint in `nums1` and then calculate the corresponding `partition2` for `nums2` as `(m + n + 1) / 2 - partition1`.
3. **Calculate Edge Elements at Partitions**:

   - `maxLeft1` and `minRight1` represent the left and right edges around `partition1` in `nums1`.
   - `maxLeft2` and `minRight2` represent the left and right edges around `partition2` in `nums2`.
   - Special cases:
     - When a partition is at the start, set `maxLeft` to `INT_MIN`.
     - When a partition is at the end, set `minRight` to `INT_MAX`.

4. **Check if Correct Partition**:

   - If `maxLeft1 <= minRight2` and `maxLeft2 <= minRight1`, this partition is correct.
   - Calculate the median based on the combined length:
     - **Even length**: Return the average of `max(maxLeft1, maxLeft2)` and `min(minRight1, minRight2)`.
     - **Odd length**: Return `max(maxLeft1, maxLeft2)`.

5. **Adjust Partition**:

   - If `maxLeft1 > minRight2`, move `right` to `partition1 - 1`.
   - Otherwise, move `left` to `partition1 + 1`.

6. **Throw Exception**:
   - If we exit the loop without finding a solution, throw an exception. This would occur only if the inputs were not sorted.

---

## Test Cases

The following `main` function demonstrates testing the solution with several examples:

```cpp
int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test Case 1: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test Case 2: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 3
    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Test Case 3: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 4
    nums1 = {};
    nums2 = {1};
    cout << "Test Case 4: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 5
    nums1 = {2};
    nums2 = {};
    cout << "Test Case 5: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
```

### Explanation of `main` Function

1. **Create Test Cases**:

   - Each test case contains two input arrays and verifies the output of `solution.findMedianSortedArrays`.

2. **Run and Display Results**:
   - For each test case, print the result from `solution.findMedianSortedArrays`.

---

## Complexity Analysis

- **Time Complexity**: **O(log(min(m, n)))**, where `m` and `n` are the lengths of the two arrays. We perform binary search on the smaller array.
- **Space Complexity**: **O(1)**, as we use a constant amount of extra space.

---

## Summary

This solution efficiently finds the median of two sorted arrays by leveraging:

- **Binary Search**: Applied on the smaller array for efficient partitioning.
- **Edge Handling**: `INT_MIN` and `INT_MAX` help handle boundary cases cleanly.
