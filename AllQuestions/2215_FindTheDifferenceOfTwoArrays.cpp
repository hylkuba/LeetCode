#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

/**
 * @brief Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
 * 
 */

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Convert vectors to sets to remove duplicates
        std::set<int> set1(nums1.begin(), nums1.end());
        std::set<int> set2(nums2.begin(), nums2.end());

        std::vector<int> num1DiffNum2;
        std::vector<int> num2DiffNum1;

        // Find nums1 - nums2
        std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(num1DiffNum2));

        // Find nums2 - nums1
        std::set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), std::back_inserter(num2DiffNum1));

        return {num1DiffNum2, num2DiffNum1};
    }
};

int main(void) {
    Solution s;
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    std::vector<std::vector<int>> result = s.findDifference(nums1, nums2);
    for(auto& vec : result) {
        for(auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}