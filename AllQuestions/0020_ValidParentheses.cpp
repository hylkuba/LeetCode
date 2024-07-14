#include <iostream>
#include <string>
#include <stack>

/**
 * @brief Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
 * 
 */

class Solution {
public:
    bool isValid(std::string s) {

        // Use stack to keep track of the brackets, LIFO
        std::stack<char> stck;

        for (size_t i = 0; i < s.size(); i++) {

            // For open brackets, add to stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stck.push(s[i]);
            } else {
                // For close brackets, check if the top of the stack is the corresponding open bracket

                if(stck.empty()) {
                    return false;
                }

                if(s[i] == ')' && stck.top() != '(') {
                    return false;
                }

                if(s[i] == '}' && stck.top() != '{') {
                    return false;
                }

                if(s[i] == ']' && stck.top() != '[') {
                    return false;
                }

                stck.pop();
            }
        }
        
        // If stack is empty, all brackets are valid
        return stck.empty();
    }
};

int main(void) {
    Solution s;
    std::string str = "(";
    std::cout << s.isValid(str) << std::endl;
    return 0;
}