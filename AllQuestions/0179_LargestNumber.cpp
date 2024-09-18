#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * @brief Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
 * 
 */

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {

        std::sort(nums.begin(), nums.end(), [](int a, int b){
            std::string x = std::to_string(a);
            std::string y = std::to_string(b);
            return x + y > y + x;
        });

        if(nums[0] == 0) return "0";

        std::string result = "";
        for(auto num : nums) {
            result += std::to_string(num);
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {3,30,34,5,9};
    std::cout << solution.largestNumber(nums) << std::endl;
    return 0;
}