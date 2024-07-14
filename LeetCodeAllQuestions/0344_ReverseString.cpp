#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
 * 
 */

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
};

int main(void) {
    Solution s;
    std::vector<char> v1 = {'h','e','l','l','o'};
    s.reverseString(v1);
    for (auto c : v1) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::vector<char> v2 = {'H','a','n','n','a','h'};
    s.reverseString(v2);
    for (auto c : v2) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}