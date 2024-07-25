#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

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