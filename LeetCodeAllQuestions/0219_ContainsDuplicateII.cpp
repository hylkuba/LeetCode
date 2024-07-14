#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/**
 * @brief Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
 * 
 */

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i - mp[nums[i]]) <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main(void) {
    std::vector<int> nums = {1, 2};
    int k = 2;
    Solution sol;
    std::cout << std::boolalpha << sol.containsNearbyDuplicate(nums, k) << std::endl;

    return 0;
}