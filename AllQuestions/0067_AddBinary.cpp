#include <iostream>
#include <string>

/**
 * @brief Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
 * 
 */

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";

        bool carry = false;
        int index = 0;
        while(true) {
            if(index >= a.size() && index >= b.size()) {
                if(carry) {
                    result = "1" + result;
                }
                break;
            }

            char aChar = '0';
            char bChar = '0';
            if(index < a.size()) {
                aChar = a[a.size() - 1 - index];
            }

            if(index < b.size()) {
                bChar = b[b.size() - 1 - index];
            }

            if(aChar == '1' && bChar == '1') {
                if(carry) {
                    result = "1" + result;
                } else {
                    result = "0" + result;
                }
                carry = true;
            } else if(aChar == '0' && bChar == '0') {
                if(carry) {
                    result = "1" + result;
                } else {
                    result = "0" + result;
                }
                carry = false;
            } else {
                if(carry) {
                    result = "0" + result;
                    carry = true;
                } else {
                    result = "1" + result;
                    carry = false;
                }
            }

            index++;
        }
    }
};

int main(void) {
    Solution s;
    std::string a = "11";
    std::string b = "1";
    std::cout << s.addBinary(a, b) << std::endl;
    return 0;
}