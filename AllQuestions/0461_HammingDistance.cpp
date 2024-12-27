#include <iostream>
#include <bitset>

/**
 * @brief The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1
 

Constraints:

0 <= x, y <= 231 - 1
 

Note: This question is the same as 2220: Minimum Bit Flips to Convert Number.
 * 
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        return std::bitset<32>(x^y).count();
    }
};

int main(void) {
    Solution solution;
    int x = 1, y = 4;
    int result = solution.hammingDistance(x, y);
    std::cout << "Result: " << result << std::endl;
    return 0;
}