#include <string>
#include <iostream>
#include <stack>

/**
 * @brief Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
 * 
 */

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<std::pair<int, std::string>> stack;

        int size = s.size();
        std::string curr = "";
        int amount = 0;

        for (int i = 0; i < size; i++) {
            if (std::isdigit(s[i])) {
                amount = amount * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                // Push the current amount and string onto the stack
                stack.push({amount, curr});
                curr = "";
                amount = 0;
            } else if (s[i] == ']') {
                std::pair<int, std::string> tmp = stack.top();
                stack.pop();
                std::string repeated_str;
                for (int j = 0; j < tmp.first; ++j) {
                    repeated_str += curr;
                }
                curr = tmp.second + repeated_str;
            } else {
                curr += s[i];
            }
        }

        return curr;
    }
};

int main(void) {
    Solution solution;
    std::string s = "3[a]2[bc]";
    std::cout << solution.decodeString(s) << std::endl;
    return 0;
}