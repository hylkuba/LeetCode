#include <iostream>
#include <string>

/**
 * @brief You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
 * 
 */

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        size_t length1 = word1.length();
        size_t length2 = word2.length();

        std::string result = "";

        size_t i = 0;
        for(i; i < length1; i++) {
            result += word1[i];
            if(i < length2) {
                result += word2[i];
            }
        }

        if(i < length2) {
            for(i; i < length2; i++) {
                result += word2[i];
            }
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::string word1 = "abc";
    std::string word2 = "pqr";
    std::cout << solution.mergeAlternately(word1, word2) << std::endl;
    return 0;
}