#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
 * 
 */

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int len = nums.size(); 
        if(len == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        std::sort(nums.begin(), nums.end());

        // Array is sorted, so in case the sum of first three elements is greater than target
        // return the sum, because all other sums will be greater than this
        int ans = nums[0] + nums[1] + nums[2];
        if(ans >= target) {
            return ans;
        }

        // Array is sorted, so in case the sum of last three elements is less than target
        // return the sum, because all other sums will be less than this
        int max = nums[len - 1] + nums[len - 2] + nums[len - 3];
        if(max <= target) {
            return max;
        }

        int previous = nums[0];
        int left, right, sum;
        int dist = abs(ans - target);

        for(int i = 0; i < len - 2; i++) {

            if (i && (nums[i] == previous)) {
                continue;
            }

            previous = nums[i];
            left = i + 1;
            right = len - 1;

            // Move indexes "left" and "right" towards each other to find the sum closest to "target"
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return sum;
                }

                // If the current sum is closer to the target than the previous closest sum, update the closest sum
                if(abs(sum - target) < dist) {
                    ans = sum;
                    dist = abs(ans - target);
                }
                
                // Move indexes "left" or "right" towards each other if there are duplicate numbers
                if(sum < target) { 
                    while((left < right) && (nums[left] == nums[left + 1])) {
                        left++;
                    }
                    left++;
                } else {
                    while((left < right) && (nums[right] == nums[right - 1])) {
                        right--;
                    }
                    right--;
                }   
            }
        }
        return ans;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    std::cout << solution.threeSumClosest(nums, target) << std::endl;
    return 0;
}