#include <iostream>
#include <string>
#include <cmath>

/**
 * @brief Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

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

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
 

Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
 * 
 */

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        size_t multiplier = columnTitle.size() - 1;

        int result = 0;
        for(size_t i = 0; i < columnTitle.size(); i++) {
            int val = columnTitle[i] - 'A' + 1;

            result += (val * pow(26, multiplier--));
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::string columnTitle = "A";
    int result = solution.titleToNumber(columnTitle);
    std::cout << "Result: " << result << std::endl;

    columnTitle = "AB";
    result = solution.titleToNumber(columnTitle);
    std::cout << "Result: " << result << std::endl;

    columnTitle = "ZY";
    result = solution.titleToNumber(columnTitle);
    std::cout << "Result: " << result << std::endl;

    return 0;
}