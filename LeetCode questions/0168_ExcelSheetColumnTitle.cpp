#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1
 * 
 */

class Solution {
public:
    std::string convertToTitle(int columnNumber) {

        std::string result = "";

        while(columnNumber > 0) {
            int digit = columnNumber % 26;

            char curr;

            if(digit == 0) {
                curr = 'Z';
                columnNumber -= 1;
            } else {
                curr = 'A' + digit - 1;
            }

            result += curr;

            columnNumber /= 26;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main(void) {
    Solution solution;
    std::cout << solution.convertToTitle(1) << std::endl;
    std::cout << solution.convertToTitle(28) << std::endl;
    std::cout << solution.convertToTitle(701) << std::endl;
    return 0;
}