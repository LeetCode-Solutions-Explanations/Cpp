#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int start = 0, maxLength = 1;

        for (int i = 0; i < s.length(); i++)
        {
            // Check for odd-length palindromes (single character center)
            int left1 = i, right1 = i;
            while (left1 >= 0 && right1 < s.length() && s[left1] == s[right1])
            {
                if (right1 - left1 + 1 > maxLength)
                {
                    start = left1;
                    maxLength = right1 - left1 + 1;
                }
                left1--;
                right1++;
            }

            // Check for even-length palindromes (two character center)
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < s.length() && s[left2] == s[right2])
            {
                if (right2 - left2 + 1 > maxLength)
                {
                    start = left2;
                    maxLength = right2 - left2 + 1;
                }
                left2--;
                right2++;
            }
        }

        return s.substr(start, maxLength);
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "babad";
    string test2 = "cbbd";
    string test3 = "a";
    string test4 = "ac";
    string test5 = "racecar";

    cout << "Longest Palindromic Substring of '" << test1 << "': "
         << solution.longestPalindrome(test1) << endl; // Output: "bab" or "aba"
    cout << "Longest Palindromic Substring of '" << test2 << "': "
         << solution.longestPalindrome(test2) << endl; // Output: "bb"
    cout << "Longest Palindromic Substring of '" << test3 << "': "
         << solution.longestPalindrome(test3) << endl; // Output: "a"
    cout << "Longest Palindromic Substring of '" << test4 << "': "
         << solution.longestPalindrome(test4) << endl; // Output: "a" or "c"
    cout << "Longest Palindromic Substring of '" << test5 << "': "
         << solution.longestPalindrome(test5) << endl; // Output: "racecar"

    return 0;
}
