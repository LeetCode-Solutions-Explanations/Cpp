Here’s a detailed explanation of the **Container With Most Water** problem along with an overview of the provided C++ solution. This problem involves finding the maximum amount of water that can be contained between two vertical lines represented by an array of heights.

### Problem Overview

You are given an integer array `height` where each element represents the height of a vertical line drawn on a 2D plane. The goal is to find two lines that, along with the x-axis, form a container capable of holding the maximum amount of water.

### How Water is Calculated

For two lines at indices `i` and `j`, the amount of water they can contain is determined by:

- The width of the container, which is `j - i`.
- The height of the container, which is the shorter of the two lines (`min(height[i], height[j])`).

Thus, the formula for the area (water contained) can be expressed as:
\[
\text{Area} = \text{height} \times \text{width} = \min(\text{height}[i], \text{height}[j]) \times (j - i)
\]

### Examples

1. **Example 1**:

   - **Input**: `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`
   - **Output**: `49`
   - **Explanation**: The maximum area is formed between the lines at indices `1` (height `8`) and `8` (height `7`), which gives an area of `7 * (8 - 1) = 49`.

2. **Example 2**:
   - **Input**: `height = [1, 1]`
   - **Output**: `1`
   - **Explanation**: The only two lines both have height `1`, so the area is `1 * (1 - 0) = 1`.

### Constraints

- The length of the height array \( n \) must satisfy \( 2 \leq n \leq 10^5 \).
- Heights must be in the range \( 0 \leq height[i] \leq 10^4 \).

### Approach

The solution uses a **two-pointer** technique, which is efficient for this problem. The idea is to start with two pointers, one at the beginning (`left`) and one at the end (`right`) of the array, and iteratively move them towards each other based on the heights of the lines.

### C++ Code Explanation

Here’s the provided code for the solution:

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the current area
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area for example 1: " << solution.maxArea(height1) << endl; // Output: 49

    // Example 2
    vector<int> height2 = {1, 1};
    cout << "Max area for example 2: " << solution.maxArea(height2) << endl; // Output: 1

    return 0;
}
```

### Step-by-Step Breakdown

1. **Initialization**:

   - Two pointers `left` and `right` are initialized at the start and end of the `height` array, respectively.
   - A variable `maxArea` is initialized to keep track of the maximum area found.

2. **Main Loop**:

   - The loop continues until the `left` pointer is less than the `right` pointer.
   - For each pair of lines:
     - The current area is calculated using the formula provided.
     - `maxArea` is updated to be the maximum of itself and the current area.

3. **Pointer Movement**:

   - The pointer that points to the shorter line is moved inward, which is based on the greedy approach that aims to find a potentially taller line that might give a larger area in future iterations.
   - If `height[left]` is less than `height[right]`, move `left` to the right (`left++`); otherwise, move `right` to the left (`right--`).

4. **Returning the Result**:
   - After the loop completes, the function returns the maximum area found.

### Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the length of the `height` array. The algorithm goes through the array once, checking each possible pair of lines.
- **Space Complexity**: **O(1)**, as the solution uses a constant amount of space regardless of the input size.

### Conclusion

This approach efficiently finds the maximum area of water that can be contained by utilizing the two-pointer technique. It ensures that every possible combination of lines is considered while minimizing the number of checks needed, making it suitable for larger input sizes.
