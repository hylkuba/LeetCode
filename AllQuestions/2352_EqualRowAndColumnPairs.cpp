#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

/**
 * @brief Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
 * 
 */

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int count = 0;
        std::set<std::vector<int>> res;
        std::vector<std::vector<int>> dupe;

        for(int row = 0; row < grid.size(); row++) {
            // if the row already exists, then in case of a duplicate, it has to be counted multiple times
            if(res.find(grid[row]) != res.end()) {
                dupe.push_back(grid[row]);
            } 
            res.insert(grid[row]);
        }

        for(int row = 0; row < grid.size(); row++) {
            std::vector<int> temp;
            for(int col = 0; col < grid.size(); col++) {
                temp.push_back(grid[col][row]);
            }

            if(res.find(temp) != res.end()) {
                // Iterate through dupe to add duplicate rows
                for(auto& it : dupe){
                    if(it == temp){
                        count++;
                    }
                }
                count++;
            } 
        }

        return count;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    std::cout << sol.equalPairs(grid) << std::endl;
    return 0;
}