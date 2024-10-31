#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return ""; // Handle empty input

        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            char currentChar = strs[0][i]; // Get character from the first string
            for (int j = 1; j < strs.size(); j++)
            {
                // If index exceeds current string length or characters do not match
                if (i >= strs[j].length() || strs[j][i] != currentChar)
                {
                    return prefix; // Return the accumulated prefix
                }
            }
            prefix += currentChar; // Append the character to the prefix
        }
        return prefix; // Return the longest common prefix
    }
};

int main()
{
    Solution solution;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};

    cout << "Longest Common Prefix of strs1: " << solution.longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << "Longest Common Prefix of strs2: " << solution.longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}
