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

        /**
         * @brief Base Case Handling: The variable ways is initialized to 1, which accounts for the base case where n is 0 or 1. In such cases, there is only one way to climb the stairs (either no steps or one step).

Loop Through Combinations: The outer loop iterates from 1 to n/2. This is because the maximum number of 2-steps (pairs of steps) one can take is n/2 (when n is even). When n is odd, one less 2-step can be taken, and the remaining will be 1-steps.

Calculate Ways Using Combinatorics: For each possible number of 2-steps i, the inner loop calculates the number of ways to arrange these 2-steps among the remaining 1-steps. This is essentially calculating the binomial coefficient (C(n - i, i)), which represents the number of ways to choose i positions out of n - i for the 2-steps. The calculation is done in a way to avoid overflow and factorial computation by using the product of ratios.

Accumulate Ways: The result of the combinatorial calculation for each i is added to ways. This accumulates the total number of distinct ways to climb the stairs, considering all possible combinations of 1-step and 2-step moves.

Return Total Ways: Finally, the function returns the total number of distinct ways to climb to the top of the staircase.
         * 
         */
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