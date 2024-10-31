Here’s a detailed explanation of the **Integer to Roman** problem, including an overview of the provided C++ solution. This problem involves converting an integer (within a specific range) into its corresponding Roman numeral representation.

### Problem Overview

The task is to convert a given integer `num` (1 ≤ num ≤ 3999) into its Roman numeral equivalent. Roman numerals are represented by a combination of specific symbols, each corresponding to a different value.

### Roman Numeral Symbols and Values

The symbols and their respective values are as follows:

| Symbol | Value |
| ------ | ----- |
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

### Conversion Rules

1. **Basic Addition**: Symbols representing values are appended together to form numbers (e.g., `III` for `3`, `XX` for `20`).
2. **Subtractive Notation**: Certain combinations are used to represent numbers that cannot be formed by simple addition:
   - 4 is represented as `IV` (5 - 1).
   - 9 is represented as `IX` (10 - 1).
   - 40 is represented as `XL` (50 - 10).
   - 90 is represented as `XC` (100 - 10).
   - 400 is represented as `CD` (500 - 100).
   - 900 is represented as `CM` (1000 - 100).

### Examples

1. **Example 1**:

   - **Input**: `num = 3749`
   - **Output**: `"MMMDCCXLIX"`
   - **Explanation**:
     - `3000 = MMM`
     - `700 = DCC`
     - `40 = XL`
     - `9 = IX`

2. **Example 2**:

   - **Input**: `num = 58`
   - **Output**: `"LVIII"`
   - **Explanation**:
     - `50 = L`
     - `8 = VIII`

3. **Example 3**:
   - **Input**: `num = 1994`
   - **Output**: `"MCMXCIV"`
   - **Explanation**:
     - `1000 = M`
     - `900 = CM`
     - `90 = XC`
     - `4 = IV`

### Constraints

- `1 <= num <= 3999`

### C++ Code Explanation

Here's the provided code that implements the integer to Roman numeral conversion:

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Pairs of Roman numeral symbols and their values
        const pair<int, string> mappings[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;

        // Iterate through the mapping array
        for (const auto& [value, symbol] : mappings) {
            while (num >= value) {
                result += symbol; // Append the symbol
                num -= value;     // Subtract the value
            }
        }

        return result; // Return the resulting Roman numeral
    }
};

// Example usage
int main() {
    Solution solution;
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "Input: " << num1 << ", Output: " << solution.intToRoman(num1) << endl; // Output: MMMDCCXLIX
    cout << "Input: " << num2 << ", Output: " << solution.intToRoman(num2) << endl; // Output: LVIII
    cout << "Input: " << num3 << ", Output: " << solution.intToRoman(num3) << endl; // Output: MCMXCIV

    return 0;
}
```

### Step-by-Step Breakdown

1. **Mapping Initialization**:

   - An array of pairs (`mappings`) is created to store the Roman numeral symbols alongside their integer values. This list is ordered from the largest to the smallest value to facilitate conversion.

2. **Conversion Logic**:

   - The function `intToRoman(int num)` initializes an empty string `result` to accumulate the Roman numeral symbols.
   - A loop iterates through the `mappings` array, checking each value.
   - Inside the loop, while the input `num` is greater than or equal to the current value:
     - The corresponding Roman numeral symbol is appended to `result`.
     - The integer value of that symbol is subtracted from `num`.

3. **Returning the Result**:
   - After processing all mappings, the function returns the constructed Roman numeral string.

### Complexity Analysis

- **Time Complexity**: **O(1)** (constant time) since the maximum number of iterations is limited by the number of symbols (13), regardless of the value of `num`.
- **Space Complexity**: **O(1)** since the space used does not depend on the size of `num`.

### Conclusion

This approach efficiently converts an integer to its Roman numeral representation using a greedy algorithm with direct value-to-symbol mapping. The code is straightforward and leverages constant-time operations to achieve the desired result within the constraints provided.
