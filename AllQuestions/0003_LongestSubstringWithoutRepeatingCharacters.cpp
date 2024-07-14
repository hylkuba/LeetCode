#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

/**
 * @brief Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLength = 0, left = 0;
        int stringLength = s.length();
        
        std::unordered_set<char> charSet;
        
        // Sliding window approach
        for (int i = 0; i < stringLength; i++) {
            if(charSet.count(s[i]) == 0) {
                charSet.insert(s[i]);
                maxLength = std::max(maxLength, i - left + 1);
            } else {
                while (charSet.count(s[i])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[i]);
            }
        }
    
        return maxLength;
    }
};

int main(void) {
    Solution sol;

    std::string s = "abcabcbb";
    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;

    s = "bbbbb";
    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;

    s = "pwwkew";
    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;

    s = "";
    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;

    s = " ";
    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;

    return 0;
}