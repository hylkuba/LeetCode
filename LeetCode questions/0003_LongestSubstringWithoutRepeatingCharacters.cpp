#include <iostream>
#include <string>
#include <set>

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
        size_t stringLength = s.length();
        size_t currPivot = 0;
        size_t longestSubstring = 0;

        std::set<char> usedCharacters;

        while(currPivot < stringLength) {
            // Start sequence from the current pivot
            size_t i = currPivot;
            size_t currLength = 0;
            while(i < stringLength) {
                // If the character is not in the set, add it
                if(usedCharacters.find(s[i]) == usedCharacters.end()) {
                    usedCharacters.insert(s[i]);
                    currLength++;
                } else {
                    break;
                }
                i++;
            }
            if(currLength > longestSubstring) {
                longestSubstring = currLength;
            }

            usedCharacters.clear();

            currPivot++;
        }

        return longestSubstring;
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