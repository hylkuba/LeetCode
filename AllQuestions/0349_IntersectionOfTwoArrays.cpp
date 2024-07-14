#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 * 
 */

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> result;

        size_t i1 = 0;
        size_t i2 = 0;

        while(i1 < nums1.size() && i2 < nums2.size()) {
            if(nums1[i1] < nums2[i2]) { 
                i1++;
                continue;
            }

            if(nums1[i1] > nums2[i2]) {
                i2++;
                continue;
            }

            if(nums1[i1] == nums2[i2]) {
                result.push_back(nums1[i1]);
                int curr = nums1[i1];
                
                i1++;
                i2++;

                while(i1 < nums1.size() && i2 < nums2.size() && nums1[i1] == nums2[i2] && nums1[i1] == curr) {
                    i1++;
                    i2++;
                }
            }
        }

        return result;
    }
};

int main(void) {
    Solution s;
    std::vector<int> nums1 = {2, 1};
    std::vector<int> nums2 = {1, 2};
    std::vector<int> result = s.intersection(nums1, nums2);
    for(auto& r : result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;

    return 0;
}