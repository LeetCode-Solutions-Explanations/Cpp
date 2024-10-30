#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Create a hash map to store numbers and their indices
        unordered_map<int, int> map;

        // Iterate through each element in nums
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the complement of the current number
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (map.find(complement) != map.end())
            {
                // If found, return the indices of the complement and current number
                return {map[complement], i};
            }

            // Store the current number and its index in the map
            map[nums[i]] = i;
        }

        // Return an empty vector if no solution is found (as per problem constraints, this won't happen)
        return {};
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: ";
    if (!result1.empty())
    {
        cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test Case 2: ";
    if (!result2.empty())
    {
        cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test Case 3: ";
    if (!result3.empty())
    {
        cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
