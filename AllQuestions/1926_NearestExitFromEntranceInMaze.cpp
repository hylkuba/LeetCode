#include <vector>
#include <queue>
#include <set>
#include <iostream>

/**
 * @brief You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

Example 1:


Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:


Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:


Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
 

Constraints:

maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
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
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        TPos startPos = {entrance[0], entrance[1]};

        int boundX = maze.size() - 1;
        int boundY = maze[0].size() - 1;

        // First is position, second step count 
        std::queue<std::pair<TPos, int>> q;
        q.push({startPos, 0});

        std::set<TPos> visited;
        
        // Used for neighbours
        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while(!q.empty()) {
            TPos currPos = q.front().first;
            int cnt = q.front().second;
            q.pop();

            // If we reached the end that is on the borderds of maze, but is not the start position, return
            if( (currPos != startPos) &&
                ((currPos.x == 0 || currPos.x == boundX) ||
                (currPos.y == 0 || currPos.y == boundY))) {

                    return cnt;
            }

            // Loop through each possible direction
            for (const auto& dir : directions) {
                TPos newPos = {currPos.x + dir.first, currPos.y + dir.second};

                // Check if newPos is within bounds and not visited
                if  ((newPos.x >= 0 && newPos.x <= boundX) && 
                    (newPos.y >= 0 && newPos.y <= boundY) &&
                    maze[newPos.x][newPos.y] == '.' &&
                    visited.find(newPos) == visited.end()) {
                    
                        q.push({newPos, cnt + 1});
                        visited.insert(newPos);
                }
            }
        }

        return -1;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::vector<char>> maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    std::vector<int> entrance = {1, 2};
    std::cout << sol.nearestExit(maze, entrance) << std::endl;
    return 0;
}