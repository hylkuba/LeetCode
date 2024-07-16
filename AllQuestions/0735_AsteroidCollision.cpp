#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

/**
 * @brief We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
 * 
 */

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> stack;

        for (int i = 0; i < asteroids.size(); ++i) {
            bool destroyed = false;

            // Process collisions: Only when the stack is not empty, the top of the stack is moving right (>0),
            // and the current asteroid is moving left (<0).
            while (!stack.empty() && stack.top() > 0 && asteroids[i] < 0) {
                // If the asteroid on the top of the stack is smaller in size (absolute value) than the current one,
                // it gets destroyed (popped from the stack), and we continue to check the next one.
                if (abs(stack.top()) < abs(asteroids[i])) {
                    stack.pop();
                    continue;
                } else if (abs(stack.top()) == abs(asteroids[i])) {
                    // If they are of equal size, both get destroyed. Pop the top asteroid and mark the current one as destroyed.
                    stack.pop();
                }
                destroyed = true; // Mark the current asteroid as destroyed.
                break; // Exit the loop as the current asteroid is either destroyed or has destroyed another.
            }

            // If the current asteroid has not been destroyed, push it onto the stack.
            if (!destroyed) {
                stack.push(asteroids[i]);
            }
        }

        std::vector<int> result;

        while(!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> asteroids = {5, 10, -5};
    std::vector<int> result = solution.asteroidCollision(asteroids);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}