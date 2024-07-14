#include <iostream>
#include <vector>

/**
 * @brief You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
 * 
 */

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if(nums.size() == 0) return {};

        if(nums.size() == 1) return {std::to_string(nums[0])};

        std::vector<std::string> ranges;

        size_t index = 0;
        size_t size = nums.size();

        // Edges of interval
        int start, end;

        // Keep track whether interval is consecutive or if it is a single number
        bool consecutive = false;

        // Set start of interval before looping
        start = nums[index++];

        while(index < size) {
            if(nums[index] - 1 == nums[index - 1]) { // Move end of interval by one
                end = nums[index];
                consecutive = true;
            } else {            // Add interval
                add(ranges, start, end, consecutive);

                start = nums[index];
                consecutive = false;
            }
            index++;
        }

        // Add the final interval
        add(ranges, start, end, consecutive);

        return ranges;
    }

private:
    void add(std::vector<std::string> &ranges, int start, int end, bool consecutive) {
        if(!consecutive) {
            ranges.push_back(std::to_string(start));
            return;
        }
        
        std::string interval = std::to_string(start);
        interval += "->";
        interval += std::to_string(end);
        ranges.push_back(interval);
    }
};

int main(void) {
    std::vector<int> nums = {0,1,2,4,5,7};
    Solution sol;
    std::vector<std::string> result = sol.summaryRanges(nums);

    for(auto& s : result) {
        std::cout << s << std::endl;
    }

    return 0;
}