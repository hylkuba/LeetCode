#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};