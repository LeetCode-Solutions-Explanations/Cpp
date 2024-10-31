The **4Sum** problem is a classic algorithmic challenge where we need to find all unique quadruplets in an array that sum up to a given target. This problem extends the concepts used in the **2Sum** and **3Sum** problems, leveraging sorting and the two-pointer technique.

### Problem Definition

Given an array `nums` of `n` integers, return an array of all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

- \(0 \leq a, b, c, d < n\)
- \(a, b, c,\) and \(d\) are distinct indices.
- \(nums[a] + nums[b] + nums[c] + nums[d] == target\)

You may return the answer in any order.

### Key Concepts

1. **Sorting**:

   - Sorting the input array helps in efficiently skipping duplicates and using the two-pointer technique for finding pairs.

2. **Two-Pointer Technique**:

   - After selecting the first two numbers, we can use two pointers to find pairs in the remaining array that sum up to the required value.

3. **Avoiding Duplicates**:
   - We need to ensure that we do not include duplicate quadruplets in our result, which involves skipping over equal numbers during the iteration.

### Detailed Explanation of the Algorithm

1. **Sorting the Array**:

   - Start by sorting the input array. This allows us to handle duplicates easily and helps in two-pointer scanning.

2. **Iterating Over the Array**:

   - Use two nested loops to select the first two numbers of the quadruplet. The outer loop runs from the start of the array to the fourth last element, and the inner loop runs from the next element of the outer loop to the third last element.

3. **Two-Pointer Approach**:

   - For each pair of numbers selected by the outer and inner loops, initialize two pointers: one (`left`) starting just after the inner loop index and the other (`right`) starting at the end of the array.
   - Calculate the sum of the current quadruplet.
   - If the sum equals the target, add this quadruplet to the results and skip duplicates by moving both pointers inward.
   - If the sum is less than the target, move the left pointer to the right (to increase the sum).
   - If the sum is greater than the target, move the right pointer to the left (to decrease the sum).

4. **Handling Duplicates**:
   - After processing a quadruplet, increment the left pointer and decrement the right pointer while skipping over duplicate values to avoid adding the same quadruplet multiple times.

### C++ Implementation

Here’s the complete C++ code implementing the algorithm:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int n = nums.size();

        // Step 2: Iterate through the array
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for the second number
                int left = j + 1; // The left pointer
                int right = n - 1; // The right pointer

                // Step 3: Use two pointers to find the last two numbers
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; // Move left pointer to the right
                        --right; // Move right pointer to the left
                    } else if (sum < target) {
                        ++left; // Increase the sum
                    } else {
                        --right; // Decrease the sum
                    }
                }
            }
        }
        return result; // Step 4: Return the result
    }
};

// Main function to test the Solution
int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    std::vector<std::vector<int>> result1 = solution.fourSum(nums1, target1);
    std::cout << "Example 1 Output:\n";
    for (const auto& quadruplet : result1) {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i) {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    // Test case 2
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    std::vector<std::vector<int>> result2 = solution.fourSum(nums2, target2);
    std::cout << "Example 2 Output:\n";
    for (const auto& quadruplet : result2) {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i) {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}
```

### Code Explanation

1. **Sorting**:

   - The first step sorts the `nums` array, which allows the algorithm to leverage the two-pointer technique and simplifies the process of avoiding duplicates.

2. **Outer and Inner Loop**:

   - The outer loop selects the first number, while the inner loop selects the second number.
   - Duplicate checks prevent re-processing the same number at each level of iteration.

3. **Two-Pointer Logic**:

   - The two pointers (`left` and `right`) are used to find the remaining two numbers. The logic inside the while loop calculates the total sum of the four selected numbers and adjusts the pointers based on the comparison to the target.

4. **Handling Duplicates**:

   - After finding a valid quadruplet, the algorithm skips duplicates for both pointers to ensure uniqueness in results.

5. **Output**:
   - The main function tests the `fourSum` method with example inputs and displays the outputs.

### Complexity Analysis

- **Time Complexity**:

  - The time complexity is \(O(n^3)\), where \(n\) is the number of elements in `nums`. This arises from the three nested loops (one outer and two for two pointers) leading to a cubic growth in combinations checked.

- **Space Complexity**:
  - The space complexity is \(O(k)\), where \(k\) is the number of unique quadruplets found. The space is primarily used for storing results.

### Conclusion

The **4Sum** problem effectively showcases how sorting and the two-pointer technique can be used to find combinations that meet a specific condition efficiently. By carefully managing the search space and avoiding duplicates, we can arrive at the solution in a reasonable time frame, making this approach both elegant and effective for solving related problems.
