#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        while (left <= right)
        {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                right = partition1 - 1;
            }
            else
            {
                left = partition1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test Case 1: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test Case 2: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 3
    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Test Case 3: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 4
    nums1 = {};
    nums2 = {1};
    cout << "Test Case 4: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    // Test case 5
    nums1 = {2};
    nums2 = {};
    cout << "Test Case 5: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
