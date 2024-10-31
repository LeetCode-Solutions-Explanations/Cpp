#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // Map to store the values of Roman numerals
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int total = 0;
        int prevValue = 0;

        for (char c : s)
        {
            int currValue = romanValues[c];
            // If the previous value is less than the current value, we need to subtract
            if (prevValue < currValue)
            {
                total += currValue - 2 * prevValue; // Subtract the previous value twice
            }
            else
            {
                total += currValue; // Otherwise, just add the current value
            }
            prevValue = currValue; // Update the previous value
        }

        return total;
    }
};

int main()
{
    Solution solution;

    // Test cases
    cout << "Input: III, Output: " << solution.romanToInt("III") << endl;         // Output: 3
    cout << "Input: LVIII, Output: " << solution.romanToInt("LVIII") << endl;     // Output: 58
    cout << "Input: MCMXCIV, Output: " << solution.romanToInt("MCMXCIV") << endl; // Output: 1994

    return 0;
}
