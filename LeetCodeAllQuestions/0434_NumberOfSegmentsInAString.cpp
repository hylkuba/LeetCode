#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

 

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1
 

Constraints:

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
 * 
 */

class Solution {
public:
    int countSegments(std::string s) {
        std::istringstream iss(s);
        std::string segment;
        int count = 0;
        
        while (iss >> segment) {
            count++;
        }
        
        return count;
    }
};

int main(void) {
    Solution s;
    std::cout << s.countSegments("Hello, my name is John") << std::endl;
    std::cout << s.countSegments("Hello") << std::endl;
    return 0;
}