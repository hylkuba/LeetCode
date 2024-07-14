#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 * 
 */

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Merge nums1 and nums2 into a new vector
        std::vector<int> merged(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        // Sort the merged vector
        std::sort(merged.begin(), merged.end());

        double median = merged.size() / 2;
        if (merged.size() % 2 == 0) {
            return (merged[median] + merged[median - 1]) / 2.0;
        } else {
            return merged[median];
        }
    }
};

int main(void) {
    Solution sol;
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    double median = sol.findMedianSortedArrays(nums1, nums2);

    // Print the result
    std::cout << "Median: " << median << std::endl;

    return 0;
}