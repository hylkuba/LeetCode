#include <iostream>
#include <string>
#include <list>
#include <vector>

/**
 * @brief The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
 * 
 */

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        std::vector<std::string> list(numRows, "");
        int currentLine = 0;
        bool reachedEdge = true;

        for (size_t i = 0; i < s.length(); ++i) {
            if (currentLine == 0 || currentLine == numRows - 1) {
                reachedEdge = !reachedEdge;
            }
            list.at(currentLine) += s.at(i);
            if (!reachedEdge) {
                currentLine++;
            } else {
                currentLine--;
            }
        }

        std::string result;
        for (int i = 0; i < numRows; ++i) {
            result += list.at(i);
        }
        return result;
    }
};

int main(void) {
    Solution sol;
    std::string s = "PAYPALISHIRING";
    int numRows = 3;
    std::string zigzagConversion = sol.convert(s, numRows);
    std::cout << zigzagConversion << std::endl;
    return 0;
}