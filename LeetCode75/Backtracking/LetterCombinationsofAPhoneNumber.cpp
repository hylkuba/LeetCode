#include <string>
#include <vector>
#include <map>

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