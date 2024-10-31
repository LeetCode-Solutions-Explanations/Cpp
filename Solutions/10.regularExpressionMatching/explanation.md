### Problem Overview

The problem requires implementing a function that checks whether the input string `s` fully matches the pattern `p`. The pattern may contain:

- `.` which matches any single character.
- `*` which matches zero or more occurrences of the preceding element.

### Examples

- **Input**: `s = "aa"`, `p = "a"` → **Output**: `false` (no match)
- **Input**: `s = "aa"`, `p = "a*"` → **Output**: `true` (matches `aa` with `a*`)
- **Input**: `s = "ab"`, `p = ".*"` → **Output**: `true` (matches any character zero or more times)

### Approach

The solution uses a recursive helper function with memoization to avoid redundant calculations. Here’s how it works:

1. **Base Case**:

   - If the pattern index `j` reaches the end of the pattern, the function checks if the string index `i` is also at the end of the string. If both are at the end, it returns `true` (match); otherwise, it returns `false` (no match).

2. **Memoization**:

   - To optimize the recursion, the function stores results in a memoization table (`unordered_map`) using a unique key created from the indices of the string and pattern. This prevents re-evaluating the same state.

3. **Character Match**:

   - The function checks if the current characters of the string and pattern match (`s[i] == p[j]`) or if the current pattern character is a dot (`.`).

4. **Handling `*` in the Pattern**:

   - If the next character in the pattern is `*`, there are two cases to consider:
     1. Treat `*` as matching zero occurrences of the preceding character and move to the next character in the pattern (`p[j+2]`).
     2. If there is a match (the current characters match), move to the next character in the string (`s[i+1]`) while keeping the pattern at `p[j]` (to allow `*` to match more characters).

5. **Proceeding Without `*`**:
   - If the next character is not `*`, the function simply moves to the next characters in both the string and the pattern.

### Code Explanation

Here’s the code again for reference, followed by an explanation of each part:

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // Memoization table to store results of subproblems
        unordered_map<string, bool> memo;
        return isMatchHelper(s, p, 0, 0, memo);
    }

private:
    bool isMatchHelper(const string &s, const string &p, int i, int j, unordered_map<string, bool> &memo) {
        // Base case: if we reach the end of the pattern
        if (j == p.length()) {
            return i == s.length();
        }

        // Create a unique key for memoization
        string key = to_string(i) + "-" + to_string(j);
        if (memo.count(key)) {
            return memo[key];
        }

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' in the pattern
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Two cases:
            // 1. Treat '*' as matching zero characters: move to p[j+2]
            // 2. If there's a match, move to the next character in s
            memo[key] = (isMatchHelper(s, p, i, j + 2, memo) || (match && isMatchHelper(s, p, i + 1, j, memo)));
        } else {
            // Proceed to the next character in both s and p
            memo[key] = match && isMatchHelper(s, p, i + 1, j + 1, memo);
        }

        return memo[key];
    }
};

// Test cases to validate the solution
int main() {
    Solution solution;

    // Test case 1
    cout << (solution.isMatch("aa", "a") ? "true" : "false") << endl; // Expected: false

    // Test case 2
    cout << (solution.isMatch("aa", "a*") ? "true" : "false") << endl; // Expected: true

    // Test case 3
    cout << (solution.isMatch("ab", ".*") ? "true" : "false") << endl; // Expected: true

    // Additional test cases
    cout << (solution.isMatch("mississippi", "mis*is*p*.") ? "true" : "false") << endl; // Expected: false
    cout << (solution.isMatch("aab", "c*a*b") ? "true" : "false") << endl; // Expected: true
    cout << (solution.isMatch("aaa", "a*") ? "true" : "false") << endl; // Expected: true
    cout << (solution.isMatch("ab", ".*c") ? "true" : "false") << endl; // Expected: false
    cout << (solution.isMatch("abcde", ".*e") ? "true" : "false") << endl; // Expected: true

    return 0;
}
```

### Detailed Steps

1. **Input Handling**: The function `isMatch` initiates the matching process and calls the helper function with the starting indices (`0` for both `s` and `p`).

2. **Base Case**:

   - If the pattern index `j` reaches the end of the pattern, the function checks if `i` (the string index) has also reached the end.

3. **Memoization Key**:

   - A key is generated using the current indices to check if the result is already computed.

4. **Character Matching**:

   - It checks whether the current characters match or if the pattern character is a dot.

5. **Pattern Processing with `*`**:

   - If the current pattern character is followed by `*`, it considers two scenarios:
     - Moving past the `*` if it doesn’t match (`isMatchHelper(s, p, i, j + 2)`).
     - If there is a match, it considers the next character in the string without moving past the `*` (`isMatchHelper(s, p, i + 1, j)`).

6. **Proceeding Without `*`**:

   - If the pattern does not contain a `*`, it moves to the next character in both the string and pattern if there’s a match.

7. **Returning the Result**:
   - The result is stored in the memoization map to be reused in future calls.

### Complexity Analysis

- **Time Complexity**: **O(m \* n)**, where `m` is the length of the string and `n` is the length of the pattern. Each state (combination of `i` and `j`) is calculated once.
- **Space Complexity**: **O(m \* n)** for memoization storage.

### Conclusion

The recursive approach with memoization effectively handles the complexity of regular expression matching while ensuring efficiency by storing previously computed results. This solution is particularly useful given the constraints (length of `s` and `p` up to `20`), making it feasible to compute within reasonable time limits.
