# Longest Palindromic Substring

## Problem Description

The **Longest Palindromic Substring** problem requires finding the longest substring in a given string that is a palindrome. A palindrome is a string that reads the same forwards and backwards.

### Example

Given:

- Input: `s = "babad"`
- Expected Output: `"bab"` or `"aba"` (both are valid)

---

## Key Concepts

### 1. **Understanding Palindromes**

A palindrome is a sequence that is identical when reversed. For example:

- `"racecar"` is a palindrome because it reads the same forwards and backwards.
- `"abc"` is not a palindrome.

### 2. **Expanding Around Center**

To find the longest palindromic substring, we can expand around potential centers:

- **Odd-length palindromes**: A single character is the center (e.g., `aba`).
- **Even-length palindromes**: Two consecutive characters are the center (e.g., `abba`).

By iterating through each character and using it as a potential center, we can expand outward to check for palindromes.

### 3. **Complexity Considerations**

The brute force approach would involve checking all possible substrings, leading to a time complexity of **O(n^3)**. However, our approach will reduce this to **O(n^2)** because for each character, we perform an expansion, which takes linear time.

---

## Step-by-Step Solution

Here’s a breakdown of the solution code:

### Code

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return ""; // Handle empty string case
        int start = 0, maxLength = 1; // Initialize starting index and max length

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (single character center)
            int left1 = i, right1 = i;
            while (left1 >= 0 && right1 < s.length() && s[left1] == s[right1]) {
                if (right1 - left1 + 1 > maxLength) {
                    start = left1; // Update start index
                    maxLength = right1 - left1 + 1; // Update max length
                }
                left1--; // Expand to the left
                right1++; // Expand to the right
            }

            // Check for even-length palindromes (two character center)
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < s.length() && s[left2] == s[right2]) {
                if (right2 - left2 + 1 > maxLength) {
                    start = left2; // Update start index
                    maxLength = right2 - left2 + 1; // Update max length
                }
                left2--; // Expand to the left
                right2++; // Expand to the right
            }
        }

        return s.substr(start, maxLength); // Return the longest palindrome substring
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "babad";
    string test2 = "cbbd";
    string test3 = "a";
    string test4 = "ac";
    string test5 = "racecar";

    cout << "Longest Palindromic Substring of '" << test1 << "': "
         << solution.longestPalindrome(test1) << endl;  // Output: "bab" or "aba"
    cout << "Longest Palindromic Substring of '" << test2 << "': "
         << solution.longestPalindrome(test2) << endl;  // Output: "bb"
    cout << "Longest Palindromic Substring of '" << test3 << "': "
         << solution.longestPalindrome(test3) << endl;  // Output: "a"
    cout << "Longest Palindromic Substring of '" << test4 << "': "
         << solution.longestPalindrome(test4) << endl;  // Output: "a" or "c"
    cout << "Longest Palindromic Substring of '" << test5 << "': "
         << solution.longestPalindrome(test5) << endl;  // Output: "racecar"

    return 0;
}
```

### Explanation

1. **Initial Checks**:

   - If the string is empty, return an empty string immediately.

2. **Variable Initialization**:

   - `start` keeps track of the starting index of the longest palindrome found.
   - `maxLength` keeps track of the length of that palindrome.

3. **Iterate Through Each Character**:

   - For each character in the string, consider it as the center of a potential palindrome.

4. **Check for Odd-Length Palindromes**:

   - Set `left1` and `right1` both to the current index `i`.
   - Expand outwards as long as the characters on both sides match.
   - If a longer palindrome is found, update `start` and `maxLength`.

5. **Check for Even-Length Palindromes**:

   - Set `left2` to the current index and `right2` to the next index `i + 1`.
   - Repeat the expansion and length checking as done for odd-length palindromes.

6. **Return the Longest Palindromic Substring**:
   - After examining all possible centers, return the substring from `start` with length `maxLength`.

---

## Complexity Analysis

- **Time Complexity**: **O(n^2)**, where `n` is the length of the input string. We potentially expand around each character, leading to quadratic behavior.
- **Space Complexity**: **O(1)**, since we are only using a constant amount of extra space for variables.

---

## Summary

This solution effectively finds the longest palindromic substring by:

- Expanding around each character and each pair of characters to check for palindromic conditions.
- It balances efficiency and simplicity, making it an optimal approach for this problem
