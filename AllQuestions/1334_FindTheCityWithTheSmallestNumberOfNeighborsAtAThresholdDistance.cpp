#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iostream>

/**
 * @brief There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
 * 
 */

class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        // Initialize it to max by default
        int leastCities = n;
        int indexOfLeastCities = 0;

        int edgesSize = edges.size();

        // Create graph
        // For each city, there is vector of pairs of "to" and "weight"
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for(int i = 0; i < edgesSize; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        // Perform BFS starting from each city
        // Continue until all cities are processed to find the city with the smallest number of neighbors within the threshold distance.
        for(int i = 0; i < n; i++) {

            // First = city, Second = totalWeight
            std::queue<std::pair<int, int>> q;

            // Initialize visited with INT_MAX to represent unvisited cities
            std::vector<int> visited(n, INT_MAX);

            q.push({i, 0});
            visited[i] = 0;

            std::set<int> obtainableCities;

            while(!q.empty()) {
                int curr = q.front().first;
                int weight = q.front().second;
                q.pop();

                obtainableCities.insert(curr);

                int possibleEdges = graph[curr].size();

                for(int m = 0; m < possibleEdges; m++) {
                    int nextCity = graph[curr][m].first; 
                    int nextWeight = graph[curr][m].second + weight;

                    // Check if we have visited that city before
                    // If yes, check if the weight was higher than is the current
                    if( (visited[nextCity] > nextWeight) && (nextWeight <= distanceThreshold) ) {
                        visited[nextCity] = nextWeight;

                        q.push({nextCity, nextWeight});
                    }
                }
            }

            if(obtainableCities.size() - 1 <= leastCities) {
                leastCities = obtainableCities.size() - 1;
                indexOfLeastCities = i;
            }
        }

        return indexOfLeastCities;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int n = 4;
    int distanceThreshold = 4;
    int result = sol.findTheCity(n, edges, distanceThreshold);
    return 0;
}