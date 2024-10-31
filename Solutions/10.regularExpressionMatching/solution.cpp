#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // Memoization table to store results of subproblems
        unordered_map<string, bool> memo;
        return isMatchHelper(s, p, 0, 0, memo);
    }

private:
    bool isMatchHelper(const string &s, const string &p, int i, int j, unordered_map<string, bool> &memo)
    {
        // Base case: if we reach the end of the pattern
        if (j == p.length())
        {
            return i == s.length();
        }

        // Create a unique key for memoization
        string key = to_string(i) + "-" + to_string(j);
        if (memo.count(key))
        {
            return memo[key];
        }

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' in the pattern
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            // Two cases:
            // 1. Treat '*' as matching zero characters: move to p[j+2]
            // 2. If there's a match, move to the next character in s
            memo[key] = (isMatchHelper(s, p, i, j + 2, memo) || (match && isMatchHelper(s, p, i + 1, j, memo)));
        }
        else
        {
            // Proceed to the next character in both s and p
            memo[key] = match && isMatchHelper(s, p, i + 1, j + 1, memo);
        }

        return memo[key];
    }
};

// Test cases to validate the solution
int main()
{
    Solution solution;

    // Test case 1
    cout << (solution.isMatch("aa", "a") ? "true" : "false") << endl; // Expected: false

    // Test case 2
    cout << (solution.isMatch("aa", "a*") ? "true" : "false") << endl; // Expected: true

    // Test case 3
    cout << (solution.isMatch("ab", ".*") ? "true" : "false") << endl; // Expected: true

    // Additional test cases
    cout << (solution.isMatch("mississippi", "mis*is*p*.") ? "true" : "false") << endl; // Expected: false
    cout << (solution.isMatch("aab", "c*a*b") ? "true" : "false") << endl;              // Expected: true
    cout << (solution.isMatch("aaa", "a*") ? "true" : "false") << endl;                 // Expected: true
    cout << (solution.isMatch("ab", ".*c") ? "true" : "false") << endl;                 // Expected: false
    cout << (solution.isMatch("abcde", ".*e") ? "true" : "false") << endl;              // Expected: true

    return 0;
}
