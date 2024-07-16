#include <vector>
#include <stack>
#include <algorithm>

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