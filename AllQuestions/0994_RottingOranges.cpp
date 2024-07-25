#include <vector>
#include <queue>
#include <set>
#include <iostream>

/**
 * @brief You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
 * 
 */

class Solution {
    struct TPos {
        int x;
        int y;

        friend bool operator<(const TPos& lhs, const TPos& rhs) {
            return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
        }

        friend bool operator!=(const TPos& lhs, const TPos& rhs) {
            return lhs.x != rhs.x || lhs.y != rhs.y;
        }
    };

public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::set<TPos> fresh;
        std::set<TPos> rotten;

        int totalOranges = 0;

        int xBounds = grid.size();
        int yBounds = grid[0].size();

        std::queue<std::pair<TPos, int>> q;

        // Initialize fresh and rotten positions
        for(int x = 0; x < xBounds; x++) {
            for(int y = 0; y < yBounds; y++) {
                TPos curr = {x, y};

                if(grid[x][y] == 1) {
                    fresh.insert(curr);
                    totalOranges++;
                } else if(grid[x][y] == 2) {
                    rotten.insert(curr);
                    totalOranges++;

                    // Push it into queue
                    q.push({curr, 0});
                }
            }
        }

        // If there are no fresh oranges, return time 0
        if(fresh.empty()) {
            return 0;
        }

        // If there are fresh oranges, but no rotten, return -1
        if(!fresh.empty() && rotten.empty()) {
            return -1;
        }

        // Used for neighbours
        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        int lastCnt = 0;

        while(!q.empty()) {
            TPos curr = q.front().first;
            int time = q.front().second;
            q.pop();

            rotten.insert(curr);

            lastCnt = std::max(lastCnt, time);

            // Check for neighbours
            for(const auto &dir : directions) {
                TPos newPos = {curr.x + dir.first, curr.y + dir.second};

                // Check if new position is legal
                if((newPos.x >= 0 && newPos.x < xBounds && newPos.y >= 0 && newPos.y < yBounds) &&
                    rotten.find(newPos) == rotten.end() &&    // Not rotten yet
                    fresh.find(newPos) != fresh.end()) { // Still fresh orange
                    
                    // Add to queue
                    q.push({newPos, time + 1});

                    // Erase from fresh ones
                    fresh.erase(newPos);
                }
            }
        }
        
        return rotten.size() == totalOranges ? lastCnt : -1;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    std::cout << sol.orangesRotting(grid) << std::endl;
    return 0;
}