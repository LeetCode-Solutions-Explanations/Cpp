### Problem Overview

The task is to implement a function similar to `atoi` in C, which parses a string and converts it to an integer. The function needs to:

1. Ignore leading whitespace.
2. Handle optional signs (`+` or `-`).
3. Parse as many numerical characters as possible.
4. Stop parsing on encountering non-numeric characters.
5. Handle integer overflow by returning `INT_MAX` or `INT_MIN` when the parsed number exceeds these boundaries.

### Solution Approach

The solution consists of several steps to handle edge cases and meet requirements systematically.

```cpp
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Step 1: Ignore leading whitespace
        while (i < s.size() && s[i] == ' ') i++;

        // Step 2: Handle sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Step 3: Convert characters to integer with overflow checks
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i++] - '0');

            // Check for overflow and exit early if detected
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
        }

        return static_cast<int>(result * sign);
    }
};
```

### Step-by-Step Explanation

1. **Initialize Variables**:

   - `i = 0`: This is the index used to iterate over the characters in the string `s`.
   - `sign = 1`: This variable stores the sign of the resulting integer (`1` for positive, `-1` for negative).
   - `result = 0`: We use a `long` type for `result` to handle overflow before final conversion to `int`.

2. **Step 1: Ignore Leading Whitespace**:

   - We iterate through the string with a `while` loop to skip leading whitespace.
   - This loop stops as soon as `i` points to the first non-space character or the end of the string.

3. **Step 2: Handle Sign**:

   - After skipping whitespaces, we check if the next character is a `+` or `-`.
   - If a sign is found, we update `sign` to `-1` if it’s `-`, otherwise leave it as `1` for positive numbers. We then increment `i` to move to the next character.
   - If no sign character is present, `sign` remains `1` by default.

4. **Step 3: Convert Characters to Integer**:

   - We enter another `while` loop that will only process numeric characters (`'0'` to `'9'`).
   - In each iteration:
     - We update `result` by shifting the current value of `result` left by one decimal place (multiplying by 10) and adding the numeric value of the current character (`s[i] - '0'`).
     - We increment `i` to move to the next character.
   - **Overflow Check**:
     - Since `result` is of type `long`, we can perform overflow checks before casting it to `int`.
     - We check whether `result * sign` exceeds `INT_MAX` or falls below `INT_MIN`:
       - If `result * sign >= INT_MAX`, we return `INT_MAX`.
       - If `result * sign <= INT_MIN`, we return `INT_MIN`.

5. **Return Final Result**:
   - Once the loop completes (either by running out of numeric characters or hitting a non-numeric character), we return the final value as `result * sign`, cast to an `int`.

### Example Walkthrough

Let's walk through some test cases to illustrate the solution's behavior:

1. **Input:** `"42"`

   - Leading whitespace ignored.
   - No sign character, so `sign` remains `1`.
   - Digits parsed: `4`, `2`.
   - Result is `42 * 1 = 42`.

2. **Input:** `"   -042"`

   - Leading whitespace ignored.
   - Sign character `-`, so `sign = -1`.
   - Digits parsed: `0`, `4`, `2`.
   - Result is `42 * -1 = -42`.

3. **Input:** `"1337c0d3"`

   - No whitespace or sign to handle.
   - Digits parsed: `1`, `3`, `3`, `7`. Parsing stops at non-numeric character `c`.
   - Result is `1337 * 1 = 1337`.

4. **Input:** `"0-1"`

   - No whitespace or sign to handle.
   - Digit parsed: `0`. Parsing stops immediately since `-` is non-numeric.
   - Result is `0 * 1 = 0`.

5. **Input:** `"words and 987"`
   - First character is non-numeric and non-whitespace, so no digits are parsed.
   - Result is `0`.

### Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the length of the input string `s`. We scan each character only once.
- **Space Complexity**: **O(1)**, since we use a constant amount of space for variables.

### Edge Cases

- **Overflow**: Inputs like `"2147483648"` or `"-2147483649"` should return `INT_MAX` and `INT_MIN` respectively.
- **Non-numeric Leading Characters**: For example, `"words and 987"` should return `0`.
- **Single Character**: `"+"`, `"-"`, `" "`, `"a"` should all return `0`.
- **Min/Max Boundaries**: `"-2147483648"` should return `-2147483648` and `"2147483647"` should return `2147483647`.
