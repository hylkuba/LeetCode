#include <vector>
#include <iostream>

/**
 * @brief Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
 * 
 */

class Solution {
public:
    std::vector<int> luckyNumbers (std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> result;

        for(int row = 0; row < m; row++) {

            // For each row, find the smallest number
            int minVal = INT_MAX;
            int colIndex = 0;
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] < minVal) {
                    minVal = matrix[row][col];
                    colIndex = col;
                }
            }

            // Check if that number is the max in its column
            int max = minVal;
            for(int i = 0; i < m; i++) {
                if(matrix[i][colIndex] > max) {
                    max = 0;
                    break;
                }
            }

            // If max value != 0, the value is max in its column, therefore lucky number
            if(max == minVal) {
                result.push_back(max);
            }
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    std::vector<int> result = sol.luckyNumbers(matrix);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}