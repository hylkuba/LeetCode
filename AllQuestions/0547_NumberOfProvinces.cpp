#include <vector>
#include <set>
#include <queue>
#include <iostream>

/**
 * @brief There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
 * 
 */

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

int main(void) {
    Solution sol;
    std::vector<std::vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int result = sol.findCircleNum(isConnected);
    std::cout << result << std::endl;
    return 0;
}