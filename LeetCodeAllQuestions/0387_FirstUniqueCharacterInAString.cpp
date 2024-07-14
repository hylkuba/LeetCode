#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
 * 
 */

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> charCount(26, 0);
        
        // Count the frequency of each character
        for (char ch : s) {
            charCount[ch - 'a']++;
        }
        
        // Find the first unique character
        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

int main(void) {
    Solution sol;
    std::cout << sol.firstUniqChar("leetcode") << std::endl;
    std::cout << sol.firstUniqChar("loveleetcode") << std::endl;
    std::cout << sol.firstUniqChar("aabb") << std::endl;
    return 0;
}
