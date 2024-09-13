#include <iostream>
#include <vector>

/**
 * @brief You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 

Constraints:

1 <= arr.length, queries.length <= 3 * 104
1 <= arr[i] <= 109
queries[i].length == 2
0 <= lefti <= righti < arr.length
 * 
 */

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::vector<int> result;
        for(auto &it : queries) {
            unsigned int xored = 0;
            for(unsigned int i = it[0]; i <= it[1]; i++) {
                xored ^= arr[i];
            }
            result.push_back(xored);
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    std::vector<int> arr = {1,3,4,8};
    std::vector<std::vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    std::vector<int> result = sol.xorQueries(arr, queries);
    for(auto &it : result) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}