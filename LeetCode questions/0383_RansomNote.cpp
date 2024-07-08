#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
 * 
 */

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        
        std::vector<char> r;
        std::vector<char> m;

        for(size_t i = 0; i < ransomNote.size(); i++) {
            r.push_back(ransomNote[i]);
        }

        for(size_t i = 0; i < magazine.size(); i++) {
            m.push_back(magazine[i]);
        }

        std::sort(r.begin(), r.end());
        std::sort(m.begin(), m.end());


        size_t j = 0;
        for(size_t i = 0; i < m.size(); i++) {
            if(j >= r.size()) return true;
            if(r[j] == m[i]) j++;
        }

        return j == r.size();
    }
};

int main(void) {
    Solution sol;
    std::cout << sol.canConstruct("a", "b") << std::endl;
    std::cout << sol.canConstruct("aa", "ab") << std::endl;
    std::cout << sol.canConstruct("aa", "aab") << std::endl;
    return 0;
}