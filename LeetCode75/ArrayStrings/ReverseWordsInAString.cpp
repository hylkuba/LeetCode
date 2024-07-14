#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::reverse(s.begin(), s.end());
        std::istringstream iss(s);

        std::string word = "";
        std::string reversed = "";

        while(iss >> word) {
            std::reverse(word.begin(), word.end());
            reversed += word;
            reversed += " ";
        }
        reversed.pop_back();

        return reversed;
    }
};