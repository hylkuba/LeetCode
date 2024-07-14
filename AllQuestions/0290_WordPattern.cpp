#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>

/**
 * @brief Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
 * 
 */

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::map<char, std::string> m;
        std::set<std::string> unique;

        std::string word;
        std::istringstream stream(s);

        for(size_t i = 0; i < pattern.size(); i++) {
            if(stream >> word) {
                char key = pattern[i];

                if(m.find(key) != m.end()) {
                    if(m[key] != word) return false;
                } else if(unique.find(word) != unique.end()) {
                    return false;
                } else {
                    m[key] = word;
                    unique.insert(word);
                }
            } else {
                return false;
            }
        }

        return !(stream >> word);
    }
};

int main(void) {
    Solution sol;
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    std::cout << sol.wordPattern(pattern, s) << std::endl;
    return 0;
}