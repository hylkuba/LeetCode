#include <iostream>
#include <string>

/**
 * @brief Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 * 
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; // Negative numbers are not palindromes
        }

        int original = x;
        long long reversed = 0;

        // Reverse the number
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Check if the reversed number is equal to the original number
        return reversed == original;
    }
};

int main(void) {
    Solution solution;
    std::cout << solution.isPalindrome(121) << std::endl;
    std::cout << solution.isPalindrome(-121) << std::endl;
    std::cout << solution.isPalindrome(10) << std::endl;
    return 0;
}