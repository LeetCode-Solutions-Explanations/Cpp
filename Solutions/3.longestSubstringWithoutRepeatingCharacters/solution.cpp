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

// Test cases
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
