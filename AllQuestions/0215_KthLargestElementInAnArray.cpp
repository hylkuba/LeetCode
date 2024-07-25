#include <vector>
#include <map>
#include <iostream>

/**
 * @brief Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 * 
 */

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::map<int, int> m;

        for(auto num : nums) {
            m[num]++;
        }

        int cnt = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++) {
            cnt += it->second;

            if(cnt >= k) {
                return it->first;
            }
        }

        return 0;
    }
};

int main(void) {
    Solution sol;
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    std::cout << sol.findKthLargest(nums, k) << std::endl;

    return 0;
}