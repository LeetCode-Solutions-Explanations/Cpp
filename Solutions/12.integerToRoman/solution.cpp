#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        // Pairs of Roman numeral symbols and their values
        const pair<int, string> mappings[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string result;

        // Iterate through the mapping array
        for (const auto &[value, symbol] : mappings)
        {
            while (num >= value)
            {
                result += symbol; // Append the symbol
                num -= value;     // Subtract the value
            }
        }

        return result; // Return the resulting Roman numeral
    }
};

// Example usage
int main()
{
    Solution solution;
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "Input: " << num1 << ", Output: " << solution.intToRoman(num1) << endl; // Output: MMMDCCXLIX
    cout << "Input: " << num2 << ", Output: " << solution.intToRoman(num2) << endl; // Output: LVIII
    cout << "Input: " << num3 << ", Output: " << solution.intToRoman(num3) << endl; // Output: MCMXCIV

    return 0;
}
