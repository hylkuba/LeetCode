#include <vector>
#include <iostream>

/**
 * @brief You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

 

Example 1:

Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation: 
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
Example 2:

Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]
 

Constraints:

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rowSum) == sum(colSum)
 * 
 */

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        std::vector<std::vector<int>> result;

        // Iterate over each row.
        for (int i = 0; i < rowSum.size(); i++) {
            std::vector<int> row;
            // Iterate over each column within the current row.
            for (int j = 0; j < colSum.size(); j++) {
                // Determine the minimum value between the current row's sum and column's sum.
                // This ensures the matrix element is as large as possible without exceeding the sums.
                row.push_back(std::min(rowSum[i], colSum[j]));
                // Subtract the chosen value from both the row's and column's sum to maintain the constraints.
                rowSum[i] -= row.back();
                colSum[j] -= row.back();
            }
            result.push_back(row);
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> rowSum = {3, 8};
    std::vector<int> colSum = {4, 7};
    std::vector<std::vector<int>> result = solution.restoreMatrix(rowSum, colSum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}