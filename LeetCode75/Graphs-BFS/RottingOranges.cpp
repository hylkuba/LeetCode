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