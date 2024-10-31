#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 != 0)
            return false; // Early return if length is odd

        stack<char> stack;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false; // No matching open bracket
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                {
                    return false; // Mismatched brackets
                }
            }
        }
        return stack.empty(); // True if all brackets are matched
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([{}])";
    string test5 = "{[()]}";
    string test6 = "([)]";

    cout << "Test 1: " << solution.isValid(test1) << endl; // Expected: true
    cout << "Test 2: " << solution.isValid(test2) << endl; // Expected: true
    cout << "Test 3: " << solution.isValid(test3) << endl; // Expected: false
    cout << "Test 4: " << solution.isValid(test4) << endl; // Expected: true
    cout << "Test 5: " << solution.isValid(test5) << endl; // Expected: true
    cout << "Test 6: " << solution.isValid(test6) << endl; // Expected: false

    return 0;
}
