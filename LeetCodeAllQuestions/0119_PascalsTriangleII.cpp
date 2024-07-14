#include <iostream>
#include <vector>

/**
 * @brief Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 * 
 */

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result;

        for(int row = 0; row <= rowIndex; row++) {
            if(row == 0) {
                result.push_back(1);
            } else if(row == 1) {
                result.push_back(1);
            } else {
                std::vector<int> currRow;
                for(int i = 0; i <= row; i++) {
                    if((i == 0) || (i == row)) {
                        currRow.push_back(1);
                    } else {
                        currRow.push_back(result[i - 1] + result[i]);
                    }
                }
                result = currRow;
            }
        }

        return result;
    }
};

int main(void) {
    Solution s;
    std::vector<int> result = s.getRow(3);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}