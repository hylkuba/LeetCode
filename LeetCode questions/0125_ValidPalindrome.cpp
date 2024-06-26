#include <iostream>
#include <string>

/**
 * @brief A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
 * 
 */

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = (int)s.length() - 1;

        while(left <= right) {
            // Skip non-alphanumeric characters
            while(left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters
            while(left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare the characters in lowercase
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        
        return true;
    }
};

int main(void) {
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
}