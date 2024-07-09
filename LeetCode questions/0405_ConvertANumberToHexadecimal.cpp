#include <iostream>
#include <algorithm>

/**
 * @brief Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
 

Constraints:

-231 <= num <= 231 - 1
 * 
 */

class Solution {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
public:
    std::string toHex(int num) {
        if(num == 0) return "0";
        
        std::string result = "";
        unsigned int n = static_cast<unsigned int>(num);

        while(n > 0) {
            int rem = n % 16;
            result += hex[rem];
            n /= 16;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(void) {
    Solution s;
    std::cout << s.toHex(26) << std::endl;
    std::cout << s.toHex(-1) << std::endl;
}