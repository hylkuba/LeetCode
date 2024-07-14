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
        std::vector<int> alphabet(26, 0);
        
        for (char c : ransomNote) {
            size_t i = magazine.find(c, alphabet[c - 'a']);
            if (i == std::string::npos) return false;
            alphabet[c - 'a'] = i + 1;
        }

        return true;
    }
};

int main(void) {
    Solution sol;
    std::cout << sol.canConstruct("a", "b") << std::endl;
    std::cout << sol.canConstruct("aa", "ab") << std::endl;
    std::cout << sol.canConstruct("aa", "aab") << std::endl;
    return 0;
}