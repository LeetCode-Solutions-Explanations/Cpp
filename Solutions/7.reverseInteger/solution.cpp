#include <iostream>
#include <vector>

class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;

        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;

            // Overflow check
            if (result > 214748364 || (result == 214748364 && digit > 7))
                return 0;
            if (result < -214748364 || (result == -214748364 && digit < -8))
                return 0;

            result = result * 10 + digit;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> testCases = {123, -123, 120, 1534236469, -2147483412};

    for (int x : testCases)
    {
        std::cout << "Input: " << x << " | Output: " << solution.reverse(x) << std::endl;
    }

    return 0;
}
