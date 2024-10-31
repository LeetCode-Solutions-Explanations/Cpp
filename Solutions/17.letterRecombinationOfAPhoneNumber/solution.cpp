#include <iostream>
#include <vector>
#include <string>
#include <cmath> // for pow function

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        // Base case: if input digits is empty, return an empty vector
        if (digits.empty())
        {
            return {};
        }

        // Mapping of digits to letters
        const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"};

        vector<string> combinations;
        string currentCombination;
        combinations.reserve(pow(4, digits.size())); // Reserve space for combinations

        backtrack(combinations, currentCombination, digits, mapping, 0);

        return combinations;
    }

private:
    void backtrack(vector<string> &combinations, string &currentCombination,
                   const string &digits, const vector<string> &mapping, int index)
    {
        // If the current combination is the same length as digits, add it to results
        if (index == digits.size())
        {
            combinations.push_back(currentCombination);
            return;
        }

        // Get the current digit and its corresponding letters
        int digit = digits[index] - '0';
        const string &letters = mapping[digit];

        // Store the current length to avoid repeated calls to size()
        int currentLength = currentCombination.size();
        for (char letter : letters)
        {
            currentCombination.push_back(letter); // Add letter to the current combination
            backtrack(combinations, currentCombination, digits, mapping, index + 1);
            currentCombination.resize(currentLength); // Backtrack, restore length
        }
    }
};

// Main function to test the Solution
int main()
{
    Solution solution;
    string digits;

    // Example test cases
    digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string &str : result)
    {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl; // To remove the last comma and space

    digits = "";
    result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string &str : result)
    {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl;

    digits = "2";
    result = solution.letterCombinations(digits);
    cout << "Input: " << digits << " => Output: [";
    for (const string &str : result)
    {
        cout << "\"" << str << "\", ";
    }
    cout << "\b\b]" << endl;

    return 0;
}
