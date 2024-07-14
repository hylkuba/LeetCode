#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 * 
 */

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }
};

int main(void) {
    Solution sol;
    std::string s = "anagram";
    std::string t = "nagaram";
    std::cout << sol.isAnagram(s, t) << std::endl;
    return 0;
}