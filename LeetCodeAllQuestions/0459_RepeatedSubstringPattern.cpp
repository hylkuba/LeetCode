#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 * 
 */

class Solution {
public:
     bool repeatedSubstringPattern(std::string str) {
        int i = 1, j = 0, n = str.size();
        std::vector<int> arr(n+1,0);

        while(i < str.size()) {
            if(str[i] == str[j]) arr[++i] = ++j;
            else if(j == 0) i++;
            else j = arr[j];
        }

        return arr[n] && (arr[n] % (n-arr[n]) == 0);
    }
};

int main(void) {
    Solution sol;
    std::cout << sol.repeatedSubstringPattern("abab") << std::endl;
    std::cout << sol.repeatedSubstringPattern("aba") << std::endl;
    std::cout << sol.repeatedSubstringPattern("abcabcabcabc") << std::endl;
    return 0;
}