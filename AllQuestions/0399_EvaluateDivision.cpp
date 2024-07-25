#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>

/**
 * @brief You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 * 
 */

class Solution {
    // ! If the division is reversed:
    // a / b = 2.0
    // So b / a = 0.5 as it is inverse of 2 / 1 ==> 1 / 2
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        // For each key, store all pairs of values and their corresponding weights
        std::map<std::string, std::map<std::string, double>> unDirGraph;

        // Create the graph
        for(int i = 0; i < equations.size(); i++) {
            unDirGraph[equations[i][0]][equations[i][1]] = values[i];
            unDirGraph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        // For each query, find the path from the source to the destination
        std::vector<double> result;
        for(int i = 0; i < queries.size(); i++) {
            std::string from = queries[i][0];
            std::string to = queries[i][1];

            // If one of the keys is not found, push_back -1
            if(unDirGraph.find(from) == unDirGraph.end() || unDirGraph.find(to) == unDirGraph.end()) {
                result.push_back(-1.0);
                continue;
            }

            // If the number is division of itself, push_back 1
            if(from == to) {
                result.push_back(1.0);
                continue;
            }

            // Find the path using BFS
            std::queue<std::pair<std::string, double>> q;
            std::set<std::string> visited;
            q.push({from, 1.0});

            bool found = false;

            while(!q.empty()) {
                std::string curr = q.front().first;
                double val = q.front().second;
                q.pop();
                visited.insert(curr);

                // Check for end
                if(curr == to) {
                    result.push_back(val);
                    found = true;
                    break;
                }

                // Add to queue neighbours
                for(auto &it : unDirGraph[curr]) {
                    std::string nextNode = it.first;

                    if(visited.find(nextNode) == visited.end()) {
                        q.push({nextNode, val * it.second});
                    }
                }
            }

            // If there wasn't a path found between the two nodes, push_back -1
            if(!found) {
                result.push_back(-1.0);
            }
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<std::vector<std::string>> equations = {{"a","b"},{"b","c"}};
    std::vector<double> values = {2.0, 3.0};
    std::vector<std::vector<std::string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    std::vector<double> result = solution.calcEquation(equations, values, queries);
    for (double res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;
    return 0;
}