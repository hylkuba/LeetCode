#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

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