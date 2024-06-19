#include <iostream>
#include <string>
#include <vector>
#include <map> 

/**
 * @brief Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
 * 
 */

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;

        if(digits.size() < 1) {
            return result;
        }

        // For each letter, recursevily call all combinations
        size_t depth = 0;
        std::string str;
        appendCombination(digits, str, result, depth);

        return result;
    }

private:
    std::map<int, std::vector<char>> digitToLetters = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

    void appendCombination(std::string &digits, std::string &curr, std::vector<std::string > &result, size_t depth) {
        if(depth >= digits.length()) {
            result.push_back(curr);
            return;
        }

        int num = digits[depth] - '0';
        for(const auto& letter : digitToLetters[num]) {
            curr += letter;
            appendCombination(digits, curr, result, depth + 1);
            curr.pop_back();
        }
    }
};

int main(void) {
    Solution solution;
    std::string digits = "";
    std::vector<std::string> result = solution.letterCombinations(digits);
    for (const auto& str : result) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}