#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for abs()

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // Sort the array
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements' sum

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1;            // The left pointer
            int right = nums.size() - 1; // The right pointer

            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Check if this is closer to target than what we have found so far
                if (abs(currentSum - target) < abs(closestSum - target))
                {
                    closestSum = currentSum;
                }

                // Move pointers based on comparison
                if (currentSum < target)
                {
                    left++; // Need a larger sum
                }
                else if (currentSum > target)
                {
                    right--; // Need a smaller sum
                }
                else
                {
                    // If currentSum is exactly equal to target, we've found the best case
                    return currentSum;
                }
            }
        }

        return closestSum; // Return the closest sum found
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = solution.threeSumClosest(nums, target);

    cout << "The closest sum to " << target << " is: " << result << endl;

    return 0;
}
