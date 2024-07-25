#include <vector>
#include <queue>
#include <set>

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