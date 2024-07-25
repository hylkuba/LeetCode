#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::set<int>> undirGraph(n);
        std::vector<std::set<int>> dirGraph(n);

        for(auto v : connections) {
            int from = v[0];
            int to = v[1];

            undirGraph[from].insert(to);
            undirGraph[to].insert(from);
            dirGraph[from].insert(to);
        }

        std::queue<int> q;
        q.push(0);

        std::set<int> visited;
        int cnt = 0;

        visited.insert(0);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int nextCity : undirGraph[curr]) {
                // If the city has not been visited yet
                if(visited.find(nextCity) == visited.end()) {
                    visited.insert(nextCity);
                    q.push(nextCity);

                    // If the city is not reachable from the current city, we have to increment the count
                    if(dirGraph[curr].find(nextCity) != dirGraph[curr].end()) cnt++;
                }
            }
        }
        return cnt;
    }
};