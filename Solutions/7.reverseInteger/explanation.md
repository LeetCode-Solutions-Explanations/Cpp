### Problem Analysis

The goal is to reverse the digits of a given integer `x`. If reversing the integer results in a value that exceeds the 32-bit signed integer range `[-2^31, 2^31 - 1]`, the function should return `0`.

### Key Observations

1. The 32-bit signed integer range in C++ is `[-2147483648, 2147483647]`. Therefore, we need to check for potential overflow before each operation that could cause it.
2. Reversing involves repeatedly extracting the last digit from `x` and appending it to a new integer `result`.

### Solution Approach

1. **Extract Digits**: Use modulo and division to retrieve the last digit of `x` and remove it.
2. **Check for Overflow**:
   - Before multiplying `result` by 10 and adding the new digit, ensure this operation will not cause overflow.
   - If `result > 214748364`, multiplying by 10 will exceed `2147483647`.
   - If `result == 214748364`, we check the final digit: if it’s greater than `7` for positive numbers or less than `-8` for negative numbers, overflow occurs.
3. **Update the Result**: Multiply `result` by 10 and add the extracted digit.

### Code Implementation

Here's the C++ code implementing the above approach with test cases for validation:

```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Overflow check
            if (result > 214748364 || (result == 214748364 && digit > 7)) return 0;
            if (result < -214748364 || (result == -214748364 && digit < -8)) return 0;

            result = result * 10 + digit;
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> testCases = {123, -123, 120, 1534236469, -2147483412};

    for (int x : testCases) {
        std::cout << "Input: " << x << " | Output: " << solution.reverse(x) << std::endl;
    }

    return 0;
}
```

### Explanation of Code

1. **Overflow Check**: `if (result > 214748364 || (result == 214748364 && digit > 7))` and `if (result < -214748364 || (result == -214748364 && digit < -8))` prevent overflow by comparing `result` with the bounds.
2. **Result Update**: `result = result * 10 + digit` builds the reversed integer digit-by-digit.
3. **Test Cases**: The `testCases` vector contains a mix of positive, negative, zero, and edge cases to verify correctness.

### Complexity Analysis

- **Time Complexity**: **O(log₁₀(x))** — The loop runs for each digit in `x`, resulting in logarithmic complexity in base 10.
- **Space Complexity**: **O(1)** — The solution uses a constant amount of space.
