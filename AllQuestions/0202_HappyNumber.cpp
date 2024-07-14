#include <iostream>
#include <set>
#include <vector>

/**
 * @brief Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
 * 
 */

class Solution {
public:
    bool isHappy(int n) {
        std::set<std::vector<int>> used;
        while(true) {
            std::vector<int> digits;
            
            while(n > 0) {
                int d = n % 10;
                digits.push_back(d);
                n /= 10;
            }

            // Check if the digits were already used
            if(used.find(digits) != used.end()) {
                return false;
            }

            used.insert(digits);

            // set new n
            n = 0;
            for(const auto& it : digits) {
                n += it * it;
            }

            if(n == 1) {
                break;
            }
        }

        return true;
    }
};

int main(void) {
    Solution s;
    std::cout << s.isHappy(19) << std::endl;
    return 0;
}