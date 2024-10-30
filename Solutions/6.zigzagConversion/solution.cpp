#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        // Initialize a list of strings for each row
        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;

        // Build the zigzag pattern row by row
        for (char c : s)
        {
            rows[currRow] += c;
            // If we are at the top or bottom row, switch direction
            if (currRow == 0 || currRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            // Move up or down based on direction
            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows into one result string
        string result;
        for (string row : rows)
        {
            result += row;
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: " << s1 << ", numRows = " << numRows1 << endl;
    cout << "Output: " << solution.convert(s1, numRows1) << endl;
    cout << "Expected: PAHNAPLSIIGYIR" << endl
         << endl;

    // Test case 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: " << s2 << ", numRows = " << numRows2 << endl;
    cout << "Output: " << solution.convert(s2, numRows2) << endl;
    cout << "Expected: PINALSIGYAHRPI" << endl
         << endl;

    // Test case 3
    string s3 = "A";
    int numRows3 = 1;
    cout << "Input: " << s3 << ", numRows = " << numRows3 << endl;
    cout << "Output: " << solution.convert(s3, numRows3) << endl;
    cout << "Expected: A" << endl
         << endl;

    return 0;
}
