#include <vector>
#include <algorithm>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;

        std::sort(nums.begin(), nums.end());
        int pairs = 0;

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k) {
                pairs++;
                left++;
                right--;
                continue;
            }

            if(sum > k) {
                right--;
            } else {
                left++;
            }
        }

        return pairs;
    }
};