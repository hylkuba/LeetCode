#include <iostream>
#include <cmath>

/**
 * @brief Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 23^1 - 1
 * 
 */

class Solution {
public:
    int mySqrt(int x) {
        
        // For special cases when x is 0 or 1, return x.
        if (x == 0 || x == 1) {
            return x;
        }

        int start = 1;
        int end = x;
        int mid = -1;
        
        // Perform binary search to find the square root of x.
        while (start <= end) {
            // Calculate the middle point using "start + (end - start) / 2" to avoid integer overflow.
            mid = start + (end - start) / 2;
            
            // Convert mid to long to handle large values without overflow.
            long long square = static_cast<long long>(mid) * mid;
            
            // Move indexes appropriately
            if (square > x) {
                end = mid - 1;
            } else if (square == x){
                return mid;
            } else {
                start = mid + 1;
            }
        }
        
        return static_cast<int>(std::round(end));
    }
};

int main(void) {
    Solution s;
    int x = 10;
    std::cout << s.mySqrt(x) << std::endl;
    return 0;
}