#include <string>
#include <numeric>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        int gcdLength = std::gcd(static_cast<int>(str1.size()), static_cast<int>(str2.size()));
        
        return str1.substr(0, gcdLength);
    }
};