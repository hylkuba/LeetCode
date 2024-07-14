#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
 * 
 */

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";
        size_t index = 0;

        bool keepGoing = true;

        // Go character by character and for each character, check if it is the same for all the words in "strs"
        while(keepGoing) {
            char currentChar = '*';

            // Iterate through the vector and check if the character on current index of the word is the same
            for (const auto& word : strs) {

                // Check if the length of word exceeded current index
                if(word.length() <= index) {
                    keepGoing = false;
                    break;
                }

                // If the word is the first iteration, set the current character to the first character of the word
                // Otherwise, check if the current character is the same as the character in the word
                if (currentChar == '*') {
                    currentChar = word[index];
                } else if (currentChar != word[index]) {
                    keepGoing = false;
                    break;
                }
            }

            if (keepGoing) {
                result += currentChar;
            }

            index++;
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << solution.longestCommonPrefix(strs) << std::endl;

    strs = {"dog", "racecar", "car"};
    std::cout << solution.longestCommonPrefix(strs) << std::endl;

    return 0;
}