#include <vector>
#include <set>
#include <queue>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        std::set<int> visitedCities;
        std::set<int> remaining;

        // Initialize the set of remaining cities
        for (int i = 0; i < isConnected.size(); i++) remaining.insert(i);

        std::queue<int> q;
        int provinces = 0;

        while (!remaining.empty()) {
            // Start a new province
            provinces++;
            int startCity = *remaining.begin();
            q.push(startCity);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (visitedCities.find(curr) == visitedCities.end()) {
                    visitedCities.insert(curr);
                    remaining.erase(curr);

                    for (int i = 0; i < isConnected[curr].size(); i++) {
                        if (isConnected[curr][i] == 1 && visitedCities.find(i) == visitedCities.end()) {
                            q.push(i);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};