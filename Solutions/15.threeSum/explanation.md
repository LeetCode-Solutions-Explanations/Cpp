### Problem Definition

The **3Sum** problem is defined as follows:

- Given an integer array `nums`, return all unique triplets \([nums[i], nums[j], nums[k]]\) such that \(i \neq j\), \(i \neq k\), and \(j \neq k\), where the sum \(nums[i] + nums[j] + nums[k] = 0\).
- The solution set must not contain duplicate triplets.

### Concepts Involved

1. **Sorting**:

   - Sorting the input array helps simplify the problem, especially when it comes to finding pairs that sum up to a specific value. Once sorted, if you need a larger sum, you can move forward; if you need a smaller sum, you can move backward.

2. **Two-Pointer Technique**:

   - This technique involves maintaining two pointers that help traverse the array to find pairs. By sorting the array first, you can effectively eliminate certain possibilities based on the values at the pointers.

3. **Avoiding Duplicates**:
   - It's crucial to skip duplicates to ensure that the same triplet is not added multiple times to the result. This can be done by checking adjacent elements during iteration.

### Detailed Explanation of the Algorithm

#### Step-by-Step Breakdown

1. **Sorting the Array**:

   - The first step is to sort the array. This allows for the use of the two-pointer technique and helps easily manage duplicates.
   - **Example**: If `nums = [-1, 0, 1, 2, -1, -4]`, sorting gives `[-4, -1, -1, 0, 1, 2]`.

2. **Iterating Through the Array**:

   - Use a loop to fix one element and then apply the two-pointer technique to find pairs that sum to the negative of the fixed element.
   - **Outer Loop**: Iterate through each element as a potential first element of the triplet.
     - If `nums[i] > 0`, break out of the loop since the sum cannot be zero (all subsequent numbers will also be positive due to sorting).
     - Skip duplicate elements for the first number to avoid repeating triplets.

3. **Two-Pointer Technique**:

   - For each fixed element, initialize two pointers: `left` (starting just after the fixed element) and `right` (at the end of the array).
   - While `left < right`, compute the sum of the three elements.
     - If the sum is less than zero, move the `left` pointer to the right to increase the sum.
     - If the sum is greater than zero, move the `right` pointer to the left to decrease the sum.
     - If the sum is exactly zero, add the triplet to the result and move both pointers inward, skipping over duplicates.

4. **Storing Unique Triplets**:
   - After finding a triplet, ensure you skip any duplicate values for both pointers to maintain unique triplets.

### C++ Implementation

Here’s the complete C++ code implementing the above logic:

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); // Step 1: Sort the array

        for (int i = 0; i < nums.size(); i++) {
            // Step 2: Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            // Early exit if the current number is greater than 0
            if (nums[i] > 0) {
                break; // No need to continue if nums[i] is positive
            }

            int left = i + 1; // Initialize left pointer
            int right = nums.size() - 1; // Initialize right pointer

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++; // Move left pointer to increase the sum
                } else if (sum > 0) {
                    right--; // Move right pointer to decrease the sum
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Step 3: Skip duplicate elements for the second number
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++; // Skip duplicates
                    }
                    // Step 4: Skip duplicate elements for the third number
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--; // Skip duplicates
                    }
                    left++; // Move pointers inward
                    right--;
                }
            }
        }

        return result; // Return the list of unique triplets
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> triplets = solution.threeSum(nums);

    std::cout << "Triplets that sum to zero:\n";
    for (const auto& triplet : triplets) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
```

### Code Explanation

1. **Sorting**:

   - The `std::sort(nums.begin(), nums.end());` statement sorts the array in ascending order.

2. **Outer Loop**:

   - The loop starts from the first element and iterates to the last. It checks if the current element is a duplicate or if it is greater than zero (where valid triplets can no longer be formed).

3. **Two-Pointer Logic**:

   - The inner `while (left < right)` loop evaluates potential pairs.
   - Depending on the sum of the triplet, it either moves the `left` pointer right (to increase the sum) or the `right` pointer left (to decrease the sum).

4. **Triplet Storage**:

   - When a valid triplet is found, it is stored in the `result` vector.
   - Duplicates are skipped by incrementing or decrementing the pointers accordingly.

5. **Output**:
   - The `main` function demonstrates how to use the `Solution` class to find and print the triplets.

### Complexity Analysis

- **Time Complexity**:
  - The sorting step is \(O(n \log n)\), and the two-pointer traversal takes \(O(n^2)\). Hence, the overall time complexity is \(O(n^2)\).
- **Space Complexity**:
  - The space complexity is \(O(1)\) if we disregard the space needed for the output, as the sorting can be done in place.

### Conclusion

The **3Sum** problem can be efficiently solved using sorting combined with the two-pointer technique. This approach not only simplifies the problem but also ensures that we can manage duplicates effectively, leading to a clear and concise solution. By breaking down the problem into smaller steps, we can better understand and implement solutions in programming.
