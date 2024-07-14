#include <iostream>
#include <string>
#include <map>

/**
 * @brief Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
 * 
 */

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::map<char, char> key;

        for(size_t i = 0; i < s.size(); i++) {
            // Check for new mapping
            if(key.find(s[i]) == key.end()) {
                key[s[i]] = t[i];
            } else {
                if(key[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        // Check again for the other string due to mapping overlay
        key.clear();
        for(size_t i = 0; i < t.size(); i++) {
            // Check for new mapping
            if(key.find(t[i]) == key.end()) {
                key[t[i]] = s[i];
            } else {
                if(key[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(void) {
    return 0;
}