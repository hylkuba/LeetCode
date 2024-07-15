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

        std::queue<int> q;

        while (right < size) {
            if (nums[right] == 0) {
                q.push(right);
                if (flipped < k) {
                    flipped++;
                } else {
                    longest = std::max(longest, right - left);
                    if (!q.empty()) {
                        left = q.front() + 1; // Move left to just beyond the oldest flipped 0
                        q.pop();
                    }
                }
            }
            // Update longest for every iteration to include sequences of 1s
            longest = std::max(longest, right - left + 1);
            right++;
        }

        return longest;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {0,0,1,1,1,0,0};
    int k = 2;
    std::cout << solution.longestOnes(nums, k) << std::endl;
    return 0;
}