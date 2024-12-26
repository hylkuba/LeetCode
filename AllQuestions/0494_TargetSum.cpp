#include <iostream>
#include <vector>

/**
 * @brief You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
 * 
 */

class Solution {
    const bool MINUS = false;
    const bool PLUS = true;
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        m_target = target;
        m_nums = nums;
        m_numsSize = m_nums.size();

        solve(0, MINUS, 0);
        solve(0, PLUS, 0);

        return count / 2;
    }

private:
    void solve(int index, bool sign, int sum) {
        if(index >= m_numsSize) {
            if(sum == m_target) {
                count++;
            }
            return;
        }

        int val = abs(m_nums[index]);

        if(sign == MINUS) {
            sum -= val;
        } else {
            sum += val;
        }

        index++;
        solve(index, MINUS, sum);
        solve(index, PLUS, sum);
    }

private:
    std::vector<int> m_nums;
    int m_target;
    int m_numsSize;
    int count = 0;
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = solution.findTargetSumWays(nums, target);
    std::cout << "Result: " << result << std::endl;
    return 0;
}