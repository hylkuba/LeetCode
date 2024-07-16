#include <vector>
#include <unordered_map>
#include <set>

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