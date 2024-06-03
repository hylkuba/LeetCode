#include <iostream>
#include <string>
#include <map>

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
        if(numRows == 1) {
            return s;
        }
        
        std::map<TPos, char> zigzag;

        size_t stringIndex = 0;
        int rowIndex = 0;
        int colIndex = 0;
        bool zagging = false;

        while(stringIndex < s.size()) {

            zigzag[{rowIndex, colIndex}] = s[stringIndex];

            if(zagging) {
                colIndex++;
                rowIndex--;
            } else {
                rowIndex++;
            }

            // Check for zagging
            if(rowIndex == numRows - 1) {
                zagging = true;
            } else if(rowIndex == 0) {
                zagging = false;
            }

            // Increase string index for next iteration
            stringIndex++;
        }

        // Return the string
        std::string result = "";

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j <= colIndex; j++) {
                if(zigzag.find({i, j}) != zigzag.end()) {
                    result += zigzag[{i, j}];
                }
            }
        }

        return result;
    }

private:
    struct TPos {
        int row;
        int col;

        bool operator<(const TPos& other) const {
            if (col == other.col) {
                return row < other.row;
            }
            return col < other.col;
        }
    };
};

int main(void) {
    Solution sol;
    std::string s = "PAYPALISHIRING";
    int numRows = 3;
    std::string zigzagConversion = sol.convert(s, numRows);
    std::cout << zigzagConversion << std::endl;
    return 0;
}