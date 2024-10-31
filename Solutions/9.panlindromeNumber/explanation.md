### Problem Overview

A palindrome number reads the same forwards and backwards. For example:

- `121` is a palindrome.
- `-121` is not a palindrome because the negative sign makes it different when reversed.
- `10` is not a palindrome as it reads `01` backwards.

### Approach

The solution aims to determine if a number is a palindrome using mathematical manipulation rather than string conversion. Here's a breakdown of the approach:

1. **Edge Cases**:

   - Negative numbers are not palindromes.
   - Numbers that end in `0` (except for `0` itself) cannot be palindromes because they would read with a leading zero when reversed.

2. **Reverse Half of the Number**:
   - The number is reversed digit by digit until the reversed number becomes greater than or equal to the remaining part of the original number. This allows us to compare just the two halves of the number.
   - For even-length numbers, both halves will be equal at the end.
   - For odd-length numbers, removing the last digit from the reversed number (using integer division by `10`) allows us to compare the two halves.

### Code Explanation

```cpp
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases: negative numbers and numbers ending in 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        // Reverse half of the number
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10; // Build the reversed half
            x /= 10; // Remove the last digit from x
        }

        // Check if the number is a palindrome
        return x == reversed_half || x == reversed_half / 10;
    }
};

int main() {
    Solution solution;

    // Test cases
    int testCases[] = {121, -121, 10, 0, 12321, 1234321, 123454321, -1};
    for (int x : testCases) {
        std::cout << "Input: " << x << " - Output: " << (solution.isPalindrome(x) ? "true" : "false") << std::endl;
    }

    return 0;
}
```

### Detailed Steps

1. **Input Handling**: The function takes an integer `x`.
2. **Edge Case Check**:

   - If `x` is negative (`x < 0`), it returns `false`.
   - If `x` ends with `0` but is not `0` itself (`x % 10 == 0 && x != 0`), it returns `false`.

3. **Reverse Half Calculation**:

   - Initialize `reversed_half` to `0`.
   - While the original number (`x`) is greater than the reversed half:
     - Extract the last digit of `x` (`x % 10`).
     - Add this digit to `reversed_half` after shifting its previous value left (multiplied by `10`).
     - Remove the last digit from `x` by integer division (`x /= 10`).

4. **Final Check**:
   - After exiting the loop, `x` contains the first half of the digits, and `reversed_half` contains the reversed second half.
   - Return `true` if both halves are equal (`x == reversed_half`).
   - For odd-length numbers, ignore the middle digit of `reversed_half` by checking if `x` equals `reversed_half / 10`.

### Complexity Analysis

- **Time Complexity**: **O(log10(n))**, where `n` is the input number. This is because we remove one digit from `x` in each iteration.
- **Space Complexity**: **O(1)**, since we use a fixed amount of extra space.

### Test Cases

The `main` function tests various cases:

- `121`: Expected output `true`.
- `-121`: Expected output `false`.
- `10`: Expected output `false`.
- `0`: Expected output `true`.
- `12321`: Expected output `true`.
- `1234321`: Expected output `true`.
- `123454321`: Expected output `true`.
- `-1`: Expected output `false`.

### Conclusion

This approach is efficient and straightforward, directly manipulating the integer to check for palindrome properties without using additional space for strings or arrays. The method also elegantly handles edge cases like negative numbers and numbers ending in zero.
