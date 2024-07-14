#include <iostream>
#include <string>
#include <map>

/**
 * @brief Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
 * 
 */

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::map<char, int> m;

        for(size_t i = 0; i < s.size(); i++) {
            m[s[i]] += 1;
        }

        int even = 0;
        bool odd = false;

        for(const auto& it : m) {
            if(it.second > 1) {
                if(it.second % 2 == 0) {
                    even += it.second;
                } else {
                    even += it.second - 1;
                    odd = true;
                }
            } else {
                odd = true;
            }
        }

        return odd ? even + 1 : even;
    }
};

int main(void) {
    Solution s;
    std::cout << s.longestPalindrome("abccccdd") << std::endl;
    std::cout << s.longestPalindrome("a") << std::endl;
    return 0;
}