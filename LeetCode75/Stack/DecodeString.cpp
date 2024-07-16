#include <string>
#include <stack>

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