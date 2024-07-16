#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        int size = nums.size();

        for(int i = 1; i < size; i++) {
            rightSum += nums[i];
        }

        if(leftSum == rightSum) return 0;

        for(int i = 1; i < size; i++) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];

            if(leftSum == rightSum) return i;
        }

        return -1;
    }
};