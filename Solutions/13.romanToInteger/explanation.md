### Problem Overview

The task is to convert a given Roman numeral string `s` into its integer equivalent, using specific rules for numeral representation and subtraction.

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

- Roman numerals are generally written from largest to smallest from left to right.
- However, there are special cases where a smaller numeral precedes a larger numeral, indicating subtraction:
  - `I` before `V` (5) and `X` (10) indicates 4 and 9, respectively.
  - `X` before `L` (50) and `C` (100) indicates 40 and 90, respectively.
  - `C` before `D` (500) and `M` (1000) indicates 400 and 900, respectively.

### Examples

1. **Example 1**:

   - **Input**: `s = "III"`
   - **Output**: `3`
   - **Explanation**: `III = 3`.

2. **Example 2**:

   - **Input**: `s = "LVIII"`
   - **Output**: `58`
   - **Explanation**: `L = 50`, `V = 5`, `III = 3`.

3. **Example 3**:
   - **Input**: `s = "MCMXCIV"`
   - **Output**: `1994`
   - **Explanation**: `M = 1000`, `CM = 900`, `XC = 90`, and `IV = 4`.

### Constraints

- `1 <= s.length <= 15`
- `s` contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
- It is guaranteed that `s` is a valid Roman numeral in the range [1, 3999].

### C++ Code Explanation

Here’s the provided code that implements the conversion from Roman numeral to integer:

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map to store the values of Roman numerals
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (char c : s) {
            int currValue = romanValues[c];
            // If the previous value is less than the current value, we need to subtract
            if (prevValue < currValue) {
                total += currValue - 2 * prevValue; // Subtract the previous value twice
            } else {
                total += currValue; // Otherwise, just add the current value
            }
            prevValue = currValue; // Update the previous value
        }

        return total;
    }
};

int main() {
    Solution solution;

    // Test cases
    cout << "Input: III, Output: " << solution.romanToInt("III") << endl; // Output: 3
    cout << "Input: LVIII, Output: " << solution.romanToInt("LVIII") << endl; // Output: 58
    cout << "Input: MCMXCIV, Output: " << solution.romanToInt("MCMXCIV") << endl; // Output: 1994

    return 0;
}
```

### Step-by-Step Breakdown

1. **Mapping Initialization**:

   - An unordered map (`romanValues`) is created to store the values of Roman numerals associated with their corresponding characters.

2. **Conversion Logic**:

   - The function `romanToInt(string s)` initializes a variable `total` to accumulate the integer value and `prevValue` to track the value of the previous numeral.
   - The function iterates through each character in the input string `s`.
   - For each character, it retrieves its corresponding integer value from the `romanValues` map.
   - It checks if the current value is greater than the previous value:
     - If it is, this indicates a subtraction case (e.g., `IV` or `IX`). Therefore, the previous value is subtracted from the total twice (once to remove its previous addition and once to account for the current value).
     - If the current value is not greater, it simply adds the current value to the total.
   - Finally, it updates `prevValue` to the current value for the next iteration.

3. **Returning the Result**:
   - After processing all characters in the string, the function returns the accumulated `total`, which represents the integer value of the Roman numeral.

### Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the length of the input string `s`. Each character is processed once.
- **Space Complexity**: **O(1)**, as the space used does not depend on the input size but rather on the fixed size of the map.

### Conclusion

This approach efficiently converts a Roman numeral string into its integer representation using a linear pass through the string and a simple conditional logic for handling subtraction cases. The solution is both clear and optimal within the constraints provided.
