#include <iostream>
#include <string>
#include <set>

/**
 * @brief Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
 * 
 */

class Solution {
public:
    std::string reverseVowels(std::string s) {
        if(s.size() <= 1) return s;
        
        size_t l = 0;
        size_t r = s.size() - 1;

        std::set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        while(l < r) {
            if(vowels.find(s[l]) != vowels.end()) {
                char c = s[l];
                while(l < r) {

                    if(vowels.find(s[r]) != vowels.end()) {
                        s[l] = s[r];
                        s[r] = c;
                        r--;
                        break;
                    }
                    r--;
                }
            }

            l++;
        }

        return s;
    }
};

int main(void) {
    Solution s;
    std::cout << s.reverseVowels("aA") << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << s.reverseVowels("leetcode") << std::endl;
    return 0;
}