#include <iostream>
#include <vector>

/**
 * @brief Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
 * 
 */

void printTriangle(std::vector<std::vector<int>> &triangle) {
    int maxWidth = triangle.back().size() * 2 - 1; 

    for(size_t i = 0; i < triangle.size(); i++) {
        int currentWidth = triangle[i].size() * 2 - 1;
        int spacesBefore = (maxWidth - currentWidth) / 2;
        std::cout << std::string(spacesBefore, ' ');

        for(size_t j = 0; j < triangle[i].size(); j++) {
            std::cout << triangle[i][j];
            if (j < triangle[i].size() - 1) std::cout << " ";
        }

        std::cout << std::endl;
    }
}

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for(int row = 1; row <= numRows; row++) {
            if(row == 1) {
                triangle.push_back({1});
            } else if(row == 2) {
                triangle.push_back({1, 1});
            } else {
                std::vector<int> currRow;
                for(int i = 0; i < row; i++) {
                    if((i == 0) || (i == (row - 1))) {
                        currRow.push_back(1);
                    } else {
                        int val = triangle[row - 2][i - 1] + triangle[row - 2][i];
                        currRow.push_back(val);
                    }
                }
                triangle.push_back(currRow);
            }
        }

        return triangle;
    }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int>> result = s.generate(5);
    printTriangle(result);
    return 0;
}