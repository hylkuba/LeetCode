#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
 * 
 */

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string result = "";
        int carry = 0;
        
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        
        while (i1 >= 0 || i2 >= 0 || carry) {
            int n1 = i1 >= 0 ? num1[i1--] - '0' : 0;
            int n2 = i2 >= 0 ? num2[i2--] - '0' : 0;
            
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(void) {
    Solution s;
    std::cout << s.addStrings("11", "123") << std::endl;
    std::cout << s.addStrings("456", "77") << std::endl;
    std::cout << s.addStrings("0", "0") << std::endl;
}