#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
 * 
 */

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current, int left, int right, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (left < n) {
            backtrack(result, current + '(', left + 1, right, n);
        }
        if (right < left) {
            backtrack(result, current + ')', left, right + 1, n);
        }
    }
};

int main(void) {
    Solution sol;
    std::vector<std::string> result = sol.generateParenthesis(3);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    return 0;
}