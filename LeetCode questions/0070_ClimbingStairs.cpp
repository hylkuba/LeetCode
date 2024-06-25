#include <iostream>

/**
 * @brief You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
 * 
 */

class Solution {
public:
    int climbStairs(int n) {
        int ways = 1;

        for (int i = 1; i <= n / 2; i++) {
            double sum = 1;

            for (int j = i; j < 2 * i; j++) {
                // (C(n, k) = n! / (k! * (n - k)!)) Product of combination
                sum *= (double)(n - j) / (j - i + 1);
            }

            ways += sum;
        }

        return ways;
    }
};

int main(void) {
    Solution s;
    std::cout << s.climbStairs(20) << std::endl;
    std::cout << s.climbStairs(31) << std::endl;
    return 0;
}