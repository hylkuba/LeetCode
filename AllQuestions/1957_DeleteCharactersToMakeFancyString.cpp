#include <iostream>
#include <string>

/**
 * @brief A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
 * 
 */

class Solution {
public:
    std::string makeFancyString(std::string s) {
        char prev = s[0];
        size_t size = s.size();
        std::string result = "";
        result += prev;
        
        for (size_t i = 1; i < size; ) {
            if(s[i] == prev) {
                result += prev;
                ++i;
                while(i < size && s[i] == prev) {
                    ++i;
                }
            } else {
                prev = s[i++];
                result += prev;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.makeFancyString("leeetcode") << std::endl;
    std::cout << s.makeFancyString("aaabaaaa") << std::endl;
    std::cout << s.makeFancyString("aab") << std::endl;
    return 0;
}