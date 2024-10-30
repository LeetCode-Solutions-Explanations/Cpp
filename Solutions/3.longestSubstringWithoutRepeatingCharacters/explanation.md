# Length of Longest Substring Without Repeating Characters

## Problem Description

The **Length of Longest Substring Without Repeating Characters** problem requires us to find the longest substring in a given string that contains no repeated characters. We need to return the length of this longest substring.

### Example

Given:

- `s = "abcabcbb"`
- Expected Output: `3` because the longest substring without repeating characters is `"abc"`.

---

## Key Concepts

### 1. **Sliding Window Technique**

The sliding window technique is useful for problems involving a contiguous subarray or substring. Here, we use two pointers:

- **`left` pointer** (start of the window)
- **`right` pointer** (end of the window)

As we move `right` to include each character in the window, we adjust `left` to ensure the window contains no repeating characters. This method allows us to process each character once, achieving an efficient solution.

### 2. **Hash Map for Character Indices**

To check for repeating characters, we use a **hash map** to store the most recent index of each character encountered. This helps us:

- Quickly identify if a character is repeating within the current window.
- Update the `left` pointer to skip over previous instances of a character when a repeat is found.

### 3. **Adjusting Window Bounds**

For each character in the string:

- If the character is already in the hash map and is within the current window, we move the `left` pointer to one position past the last occurrence of the character.
- Update the maximum length of the substring without repeating characters based on the current window size (`right - left + 1`).

---

## Step-by-Step Solution

Here’s a breakdown of the solution code:

### Code

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, left = 0;

        for (int right = 0; right < s.length(); ++right)
        {
            // If character is already in the map, move `left` pointer past the last occurrence
            if (charIndexMap.find(s[right]) != charIndexMap.end())
            {
                left = max(left, charIndexMap[s[right]] + 1);
            }

            // Update the character's latest index and calculate maxLength
            charIndexMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

````

### Explanation

1. **Initialize Variables**:

   - `unordered_map<char, int> charIndexMap` keeps track of the last index where each character appeared.
   - `int maxLength = 0` stores the maximum length of a substring without repeating characters.
   - `int left = 0` points to the start of the current window.

2. **Expand the Window**:

   - The `for` loop iterates with `right` over each character in the string.

3. **Check for Repeats**:

   - If `s[right]` is found in `charIndexMap` and within the current window (`left` to `right`), it means the character has been repeated.
   - Move `left` to the right of the last occurrence of `s[right]` by setting `left = max(left, charIndexMap[s[right]] + 1)`.

4. **Update Character Index and Max Length**:

   - Record the latest position of `s[right]` in `charIndexMap`.
   - Calculate the current window length as `right - left + 1` and update `maxLength` if this length is greater than the previous `maxLength`.

5. **Return Maximum Length**:
   - After iterating through `s`, `maxLength` holds the length of the longest substring without repeating characters.

---

## Test Cases

The following `main` function demonstrates testing the solution with several examples:

```cpp
int main()
{
    Solution solution;
    vector<pair<string, int>> testCases = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"", 0},
        {"abcdef", 6},
        {"aab", 2},
        {"dvdf", 3},
        {"anviaj", 5}};

    for (const auto &testCase : testCases)
    {
        string input = testCase.first;
        int expectedOutput = testCase.second;
        int result = solution.lengthOfLongestSubstring(input);

        cout << "Input: \"" << input << "\"" << endl;
        cout << "Expected Output: " << expectedOutput << endl;
        cout << "Result: " << result << endl;
        cout << (result == expectedOutput ? "Pass\n" : "Fail\n") << endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}
```

### Explanation of `main` Function

1. **Create Test Cases**:

   - Each test case contains a string input and the expected output (length of the longest substring without repeating characters).

2. **Run and Check Results**:
   - For each test case, `solution.lengthOfLongestSubstring(input)` is called.
   - Compare the result to the expected output, and print "Pass" or "Fail" accordingly.

---

## Complexity Analysis

- **Time Complexity**: **O(n)**, where `n` is the length of the input string `s`. Each character is processed at most twice (once by `right` pointer and, in the worst case, once by `left` pointer).
- **Space Complexity**: **O(min(n, m))**, where `m` is the size of the character set. In the worst case, we may store all unique characters in `charIndexMap`.

---

## Summary

The sliding window approach with a hash map provides an efficient solution:

- **Sliding Window**: Allows us to check each substring just once.
- **Hash Map**: Quickly checks and updates the last seen index of each character.

This solution achieves optimal performance and meets the problem's requirements.

```

````
