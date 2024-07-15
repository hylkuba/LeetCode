#include <vector>
#include <iostream>

/**
 * @brief You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
 * 
 */

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double max = 0.0;

        // Initialize prevSum and average max
        for(int i = 0; i < k; i++) {
            max += nums[i];
        }
        int prevSum = max;
        max /= k;

        // Add to previous sum new element and subtract the first element
        int size = nums.size();
        for(int i = k; i < size; i++) {
            double average = 0;

            prevSum += nums[i];
            prevSum -= nums[i - k];

            average = prevSum;
            average /= k;

            if(average > max) {
                max = average;
            }
        }

        return max;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double result = solution.findMaxAverage(nums, k);
    std::cout << "Result: " << result << std::endl;
    return 0;
}