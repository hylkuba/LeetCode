#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/**
 * @brief Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
 * 
 */

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int flipped = 0;
        int longest = 0;
        int size = nums.size();

        // Holds indexes where we flipped
        std::queue<int> q;

        while(right < size) {
            while(right < size && nums[right] == 1) {
                right++;
            }

            if(right < size && nums[right] == 0 && flipped < k) {
                q.push(right);
                flipped++;
                right++;
            } else {
                if(!q.empty()) {
                    longest = std::max(longest, right - left);
                } else {
                    longest = std::max(longest, right - left - 1);
                }

                if(!q.empty()) {
                    left = q.front();
                    q.pop();
                }
                left++;
                q.push(right);
                right++;
            }
        }

        // Return the longest consecutive ones, or the distance between the end of vector and left index
        return !q.empty() ? std::max(longest, right - left) : std::max(longest, right - left - 1);
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    std::cout << solution.longestOnes(nums, k) << std::endl;
    return 0;
}