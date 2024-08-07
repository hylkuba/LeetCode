#include <iostream>
#include <vector>

/**
 * @brief Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 * 
 */

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> result;

        for(int i = 0; i <= n; i++) {
            int cnt = 0;

            int num = i;
            while(num > 0) {
                if(num & 1) cnt++;
                num >>= 1;
            }

            result.push_back(cnt);
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    std::vector<int> result = sol.countBits(5);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}