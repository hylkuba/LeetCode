#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

/**
 * @brief A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
 * 
 */

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::map<std::string, int> m;
        std::istringstream iss(s1);
        std::istringstream iss2(s2);

        std::string word;
        while (iss >> word) {
            m[word]++;
        }


        while(iss2 >> word) {
            m[word]++;
        }

        std::vector<std::string> result;
        for(auto it : m) {
            if(it.second == 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    std::string s1 = "this apple is sweet";
    std::string s2 = "this apple is sour";
    std::vector<std::string> result = sol.uncommonFromSentences(s1, s2);
    for(auto word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}