#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int flipped = 0;
        int longest = 0;
        int size = nums.size();

        std::queue<int> q;

        while (right < size) {
            if (nums[right] == 0) {
                q.push(right);
                if (flipped < k) {
                    flipped++;
                } else {
                    longest = std::max(longest, right - left);
                    if (!q.empty()) {
                        left = q.front() + 1; // Move left to just beyond the oldest flipped 0
                        q.pop();
                    }
                }
            }
            // Update longest for every iteration to include sequences of 1s
            longest = std::max(longest, right - left + 1);
            right++;
        }

        return longest;
    }
};