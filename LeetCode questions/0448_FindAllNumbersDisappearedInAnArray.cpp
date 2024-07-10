#include <iostream>
#include <vector>

/**
 * @brief Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 * 
 */

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = nums[i] - 1;
            while(nums[index] != index + 1) {
                int temp = nums[index];
                nums[index] = index + 1;
                index = temp - 1;
            }
        }

        std::vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]-1 != i) res.push_back(i+1);
        }
        return res;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    std::vector<int> res = solution.findDisappearedNumbers(nums);

    for(int i=0; i<res.size(); i++) {
        std::cout << res[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}