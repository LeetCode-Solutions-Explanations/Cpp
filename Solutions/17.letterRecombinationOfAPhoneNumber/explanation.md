The **Letter Combinations of a Phone Number** problem involves generating all possible letter combinations that a sequence of digits could represent based on a classic mobile phone keypad. Each digit corresponds to a set of letters, and the task is to explore all combinations of these letters for a given string of digits.

### Problem Definition

Given a string `digits` containing digits from `2-9`, the goal is to return all possible letter combinations that the number could represent. Each digit corresponds to specific letters as follows:

- 2 -> "abc"
- 3 -> "def"
- 4 -> "ghi"
- 5 -> "jkl"
- 6 -> "mno"
- 7 -> "pqrs"
- 8 -> "tuv"
- 9 -> "wxyz"

### Concepts Involved

1. **Backtracking**:

   - Backtracking is a powerful technique used for solving problems incrementally. It builds a solution step-by-step and removes solutions that fail to satisfy the constraints of the problem as soon as this is detected.

2. **Mapping**:

   - A mapping from digits to their corresponding letters is necessary for translating the digit string into letter combinations.

3. **Dynamic String Construction**:
   - The solution requires constructing strings of varying lengths based on the input digits.

### Detailed Explanation of the Algorithm

#### Step-by-Step Breakdown

1. **Base Case**:

   - If the input string `digits` is empty, immediately return an empty vector since there are no combinations to generate.

2. **Mapping Digits to Letters**:

   - Create a vector `mapping` that holds the strings corresponding to each digit from 0 to 9. Digits 0 and 1 have no corresponding letters, so they are initialized to empty strings.

3. **Vector for Combinations**:

   - Create a vector `combinations` to store the resulting combinations of letters. Additionally, reserve enough space based on the maximum possible combinations to enhance performance.

4. **Backtracking Function**:

   - A private helper function named `backtrack` is implemented, which takes the current state of combinations, the current combination being built, the input digits, the mapping, and the current index in the digits string.

5. **Recursive Exploration**:
   - Inside the `backtrack` function:
     - **Termination Condition**: If the `index` equals the length of the `digits` string, it means a complete combination has been formed, and it is added to `combinations`.
     - **Digit Processing**: Convert the current digit from the string to an integer to find the corresponding letters from the mapping.
     - **Loop Through Letters**: For each letter corresponding to the current digit:
       - Append the letter to the `currentCombination`.
       - Recursively call `backtrack` for the next index.
       - After returning from recursion, backtrack by removing the last letter added to restore the `currentCombination`.

### C++ Implementation

Here’s the complete C++ code implementing the above logic:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath> // for pow function

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Base case: if input digits is empty, return an empty vector
        if (digits.empty()) {
            return {};
        }

        // Mapping of digits to letters
        const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> combinations;
        string currentCombination;
        combinations.reserve(pow(4, digits.size())); // Reserve space for combinations

        backtrack(combinations, currentCombination, digits, mapping, 0);

        return combinations;
    }

private:
    void backtrack(vector<string>& combinations, string& currentCombination,
                   const string& digits, const vector<string>& mapping, int index) {
        // If the current combination is the same length as digits, add it to results
        if (index == digits.size()) {
            combinations.push_back(currentCombination);
            return;
        }

        // Get the current digit and its corresponding letters
        int digit = digits[index] - '0';
        const string& letters = mapping[digit];

        // Store the current length to avoid repeated calls to size()
        int currentLength = currentCombination.size();
        for (char letter : letters) {
            currentCombination.push_back(letter); // Add letter to the current combination
            backtrack(combinations, currentCombination, digits, mapping, index + 1);
            currentCombination.resize(currentLength); // Backtrack, restore length
        }
    }
};

// Main function to test the Solution
int main() {
    Solution solution;
    string digits;

    // Example test cases
    digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string& str : result) {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl; // To remove the last comma and space

    digits = "";
    result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string& str : result) {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl;

    digits = "2";
    result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string& str : result) {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl;

    return 0;
}
```

### Code Explanation

1. **Base Case Handling**:

   - The first line in the `letterCombinations` function checks if `digits` is empty and returns an empty vector if true.

2. **Mapping Definition**:

   - The mapping of digits to letters is defined as a vector of strings. The first two indices (0 and 1) are left empty since they don’t correspond to any letters.

3. **Combination Vector**:

   - The `combinations` vector is created to store the resulting letter combinations, and memory is reserved for the maximum number of combinations possible.

4. **Backtracking Function**:

   - The `backtrack` function handles the recursive exploration of possible combinations. It checks when to add a completed combination to the results and manipulates the current string appropriately.
   - The `currentLength` variable is used to manage the length of `currentCombination` efficiently during backtracking.

5. **Output**:
   - The `main` function tests various cases, including non-empty and empty input, printing the corresponding outputs.

### Complexity Analysis

- **Time Complexity**:
  - The time complexity is \(O(3^N \cdot 4^M)\), where \(N\) is the number of digits mapped to 3 letters (2, 3, 4, 5, 6, 8) and \(M\) is the number of digits mapped to 4 letters (7, 9). Since the maximum length of `digits` is 4, the practical upper bound remains manageable.
- **Space Complexity**:
  - The space complexity is \(O(N \cdot 4^M)\) due to storing the combinations.

### Conclusion

The **Letter Combinations of a Phone Number** problem demonstrates the effectiveness of backtracking as a method for exploring all potential solutions to a problem incrementally. By systematically exploring combinations, the algorithm efficiently generates the required outputs. The use of mapping for digit-letter correspondence simplifies the process of constructing combinations, making the solution both elegant and efficient.
