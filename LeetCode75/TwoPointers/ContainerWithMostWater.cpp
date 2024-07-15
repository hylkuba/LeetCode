#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;

        while(left < right) {
            int area = (right - left) * std::min(height[left], height[right]);
            if(area > max) {
                max = area;
            }

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};