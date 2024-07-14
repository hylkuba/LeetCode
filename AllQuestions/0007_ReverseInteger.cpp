#include <iostream>

/**
 * @brief Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
 * 
 */

class Solution {                      
public:
    int reverse(int x) {
        int r=0;
        while(x){
         if (r > INT_MAX/10 || r < INT_MIN/10) return 0;
         r=r*10+x%10;
         x=x/10;
        } 
        return r;
    }
}; 

int main(void) {
    Solution solution;
    std::cout << solution.reverse(123) << std::endl;
    std::cout << solution.reverse(-123) << std::endl;
    std::cout << solution.reverse(120) << std::endl;
    return 0;
}