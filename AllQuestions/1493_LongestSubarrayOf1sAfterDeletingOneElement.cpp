#include <iostream>
#include <vector>

/**
 * @brief Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 * 
 */

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int size = nums.size();

        if(size <= 1) return 0;

        int longest = 0;
        int currLongest = 0;
        bool removed = false;
        int prevRemoved = -1;

        for(int i = 0; i < size; i++) {
            if(nums[i] == 1) {
                currLongest++;
            } else {

                // If we have already removed one zero, set the distance starting from previosly removed index
                // If current longest is greater than previous max, set it
                if(removed) {
                    longest = std::max(longest, currLongest);
                    currLongest = i - prevRemoved - 1;
                }

                prevRemoved = i;
                removed = true;
            }
        }

        // Check for possible longest distance after last element in vector
        longest = std::max(longest, currLongest);

        // If no elements containing zeroes were removed, we must substract one element as it is specified in description
        return removed ? longest : longest - 1;
    }
};

int main(void) {
    Solution s;
    std::vector<int> nums = {1, 1, 0, 1};
    std::cout << s.longestSubarray(nums) << std::endl;
    return 0;
}