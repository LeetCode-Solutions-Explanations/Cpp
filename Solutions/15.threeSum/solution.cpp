#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); // Sort the array

        for (int i = 0; i < nums.size(); i++)
        {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // Early exit: If nums[i] is greater than 0, break, since we need a sum of 0
            if (nums[i] > 0)
            {
                break;
            }

            int left = i + 1;            // Start pointer
            int right = nums.size() - 1; // End pointer

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    left++; // Increase the sum
                }
                else if (sum > 0)
                {
                    right--; // Decrease the sum
                }
                else
                {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicate elements for the second number
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    // Skip duplicate elements for the third number
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};

// Example usage
int main()
{
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> triplets = solution.threeSum(nums);

    std::cout << "Triplets that sum to zero:\n";
    for (const auto &triplet : triplets)
    {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
