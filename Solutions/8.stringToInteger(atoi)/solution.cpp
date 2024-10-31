#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        long result = 0;

        // Step 1: Ignore leading whitespace
        while (i < s.size() && s[i] == ' ')
            i++;

        // Step 2: Handle sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Step 3: Convert characters to integer with overflow checks
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i++] - '0');

            // Check for overflow and exit early if detected
            if (result * sign >= INT_MAX)
                return INT_MAX;
            if (result * sign <= INT_MIN)
                return INT_MIN;
        }

        return static_cast<int>(result * sign);
    }
};

// Main function to test the myAtoi implementation
int main()
{
    Solution solution;

    // Test cases
    string test1 = "42";
    string test2 = "   -042";
    string test3 = "1337c0d3";
    string test4 = "0-1";
    string test5 = "words and 987";

    cout << "Input: \"" << test1 << "\" Output: " << solution.myAtoi(test1) << endl;
    cout << "Input: \"" << test2 << "\" Output: " << solution.myAtoi(test2) << endl;
    cout << "Input: \"" << test3 << "\" Output: " << solution.myAtoi(test3) << endl;
    cout << "Input: \"" << test4 << "\" Output: " << solution.myAtoi(test4) << endl;
    cout << "Input: \"" << test5 << "\" Output: " << solution.myAtoi(test5) << endl;

    return 0;
}
