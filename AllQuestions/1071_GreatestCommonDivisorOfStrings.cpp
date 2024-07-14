#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

/**
 * @brief For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
 * 
 */

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        int gcdLength = std::gcd(static_cast<int>(str1.size()), static_cast<int>(str2.size()));
        
        return str1.substr(0, gcdLength);
    }
};

int main(void) {
    Solution sol;
    std::string str1 = "ABCABC";
    std::string str2 = "ABC";
    std::cout << sol.gcdOfStrings(str1, str2) << std::endl;
    return 0;
}