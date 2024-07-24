#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * @brief You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 

Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109
 * 
 */

class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        std::vector<std::pair<int, int>> mappedValues(nums.size());
        
        // Function to get the mapped value of a number
        auto getMappedValue = [&](int num) {
            if(num == 0) return mapping[0]; // Handle 0 explicitly

            int result = 0;
            int place = 1;
            while(num > 0) {
                int digit = num % 10;
                result = mapping[digit] * place + result;
                place *= 10;
                num /= 10;
            }

            return result;
        };
        
        // Populate mappedValues with (mapped value, original index)
        for(size_t i = 0; i < nums.size(); ++i) {
            mappedValues[i] = {getMappedValue(nums[i]), i};
        }
        
        // Stable sort by mapped value, then by original index. Needs to take the whole pair in case we have same mapping value, we return by the relative order
        std::stable_sort(mappedValues.begin(), mappedValues.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });
        
        // Reorder nums based on sorted mapped values
        std::vector<int> result(nums.size());
        for(size_t i = 0; i < nums.size(); ++i) {
            result[i] = nums[mappedValues[i].second];
        }
        
        return result;
    }
};

int main(void) {
    Solution sol;
    std::vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    std::vector<int> nums = {991,338,38};
    std::vector<int> result = sol.sortJumbled(mapping, nums);
    for(auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}