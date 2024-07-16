#include <stack>
#include <string>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::string result = "";

        for (char c : s) {
            if (c == '*') {
                // Pop the last character for each '*'
                if (result != "") {
                    result.pop_back();
                }
            } else {
                // Push regular characters
                result += c;
            }
        }

        return result;
    }
};