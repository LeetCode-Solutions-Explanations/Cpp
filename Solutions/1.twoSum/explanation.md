# Two Sum Problem in C++

## Problem Description

The **Two Sum** problem requires us to find two numbers in an array that add up to a specific target. The goal is to return the indices of these two numbers.

### Example

Given:

- `nums = [2, 7, 11, 15]`
- `target = 9`

Expected Output: `[0, 1]` because `nums[0] + nums[1] == 9`

---

## Key Concepts

### 1. **Using a Hash Map for Fast Lookup**

To solve this problem efficiently, we use a **hash map** (also known as an unordered map in C++). A hash map lets us store key-value pairs and quickly look up the values based on their keys.

In this problem:

- The **key** in the hash map is each element in `nums`.
- The **value** is the index of that element.

### 2. **Complements**

For each element in the array:

1. We calculate its **complement**: the number needed to reach the target when added to the current element.
2. We then check if this complement already exists in our hash map.

If it exists, we’ve found our solution: the current element and its complement add up to the target.

### 3. **Why Use a Hash Map?**

Using a hash map reduces the time complexity of this problem from **O(n^2)** (using two nested loops) to **O(n)**, since hash map operations (insertion and lookup) are average **O(1)**.

---

## Step-by-Step Solution

Here’s a breakdown of the solution code:

### Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Initialize the hash map

        for (int i = 0; i < nums.size(); i++) { // Loop through each element
            int complement = target - nums[i]; // Calculate complement

            if (map.find(complement) != map.end()) { // Check if complement is in the map
                return {map[complement], i}; // Return indices if complement is found
            }

            map[nums[i]] = i; // Add current number and index to the map
        }

        return {}; // Return empty if no solution found (not expected as per constraints)
    }
};
```

### Explanation

1. **Create a Hash Map**:

   - `unordered_map<int, int> map` initializes an empty hash map where the keys are numbers from `nums` and values are their indices.

2. **Iterate through the Array**:

   - `for (int i = 0; i < nums.size(); i++)` goes through each number in the array.

3. **Calculate Complement**:

   - `int complement = target - nums[i];` calculates the complement of the current number, which is the number needed to add up to `target`.

4. **Check the Hash Map**:

   - `if (map.find(complement) != map.end())` checks if the complement is already in the map.
   - If the complement is found, `return {map[complement], i};` returns the indices of the complement and the current number.

5. **Store Current Number**:

   - `map[nums[i]] = i;` adds the current number and its index to the map if the complement isn’t found.

6. **Return Empty Vector**:
   - `return {};` returns an empty vector if no solution exists. (According to the problem constraints, there will always be a valid solution.)

---

## Main Function for Testing

Here’s a sample `main` function to test the solution:

```cpp
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: ";
    if (!result1.empty()) {
        cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test Case 2: ";
    if (!result2.empty()) {
        cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test Case 3: ";
    if (!result3.empty()) {
        cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
```

### Explanation of `main` Function

1. We create an instance of the `Solution` class.
2. For each test case:
   - A `nums` vector and a `target` integer are created.
   - We call the `twoSum` function with these inputs and store the result.
   - We output the result if a solution is found, otherwise, we output "No solution found."

---

## Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the number of elements in `nums`, because each number is checked only once.
- **Space Complexity**: **O(n)**, for storing elements in the hash map.

---

## Summary

This approach is efficient for solving the **Two Sum** problem:

- We use a **hash map** to track elements and indices.
- We find the required complement in constant time **O(1)** for each element.
- This solution is **optimal** and meets the problem’s constraints.
