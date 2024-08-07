#include <iostream>

/**
 * @brief Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
 

Follow up: Could you do it without any loop/recursion in O(1) runtime?
 * 
 */

class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;

        int val = 0;

        while(num != 0) {
            int digit = num % 10;
            val += digit;
            num /= 10;
        }

        return addDigits(val);
    }
};

int main(void) {
    Solution sol;
    int num = 38;
    std::cout << sol.addDigits(num) << std::endl;
    return 0;
}