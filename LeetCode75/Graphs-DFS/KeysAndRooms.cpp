#include <vector>
#include <set>
#include <queue>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        std::queue<int> q;  // Hold the amount of keys
        std::set<int> visited;

        // Insert default keys
        visited.insert(0);
        for(auto key : rooms[0]) {
            q.push(key);
        }

        // In the description 2 rooms are guaranteed. Therefore if there are no keys, we can't get everywhere
        if(q.size() == 0) return false;

        while(!q.empty()) {
            int key = q.front();
            visited.insert(key);
            q.pop();

            for(auto val : rooms[key]) {
                if(visited.find(val) == visited.end()) q.push(val);
            }
        }

        return visited.size() == rooms.size();
    }
};