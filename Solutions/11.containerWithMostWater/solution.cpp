#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right)
        {
            // Calculate the current area
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area for example 1: " << solution.maxArea(height1) << endl; // Output: 49

    // Example 2
    vector<int> height2 = {1, 1};
    cout << "Max area for example 2: " << solution.maxArea(height2) << endl; // Output: 1

    return 0;
}
