#include <vector>
#include <string>
#include <map>
#include <iostream>

/**
 * @brief You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
 * 
 */

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        std::map<int, std::string> heightToName;

        int n = names.size();   // Same size as heights

        for(int i = 0; i < n; i++) {
            heightToName[heights[i]] = names[i];
        }

        std::vector<std::string> result;
        for(auto it = heightToName.rbegin(); it != heightToName.rend(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    std::vector<std::string> names = {"Mary","John","Emma"};
    std::vector<int> heights = {180,165,170};
    std::vector<std::string> result = sol.sortPeople(names, heights);
    for (auto name : result) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    return 0;
}