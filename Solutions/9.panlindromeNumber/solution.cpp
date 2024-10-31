#include <iostream>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Edge cases: negative numbers and numbers ending in 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reversed_half = 0;
        // Reverse half of the number
        while (x > reversed_half)
        {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // Check if the number is a palindrome
        return x == reversed_half || x == reversed_half / 10;
    }
};

int main()
{
    Solution solution;

    // Test cases
    int testCases[] = {121, -121, 10, 0, 12321, 1234321, 123454321, -1};
    for (int x : testCases)
    {
        std::cout << "Input: " << x << " - Output: " << (solution.isPalindrome(x) ? "true" : "false") << std::endl;
    }

    return 0;
}
