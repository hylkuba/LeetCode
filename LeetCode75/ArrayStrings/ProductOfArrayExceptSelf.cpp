#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        long long totalVal = 1;
        size_t size = nums.size();

        for(size_t i = 0; i < size; i++) {
            totalVal *= nums[i];
        }

        std::vector<int> result;
        if(totalVal != 0) {
            for(size_t i = 0; i < size; i++) {
                result.push_back(totalVal / nums[i]);
            }
        } else {
            int index = 0;
            totalVal = 1;
            int zeroCnt = 0;
            for(size_t i = 0; i < size; i++) {
                if(nums[i] == 0) {
                    zeroCnt++;
                    index = i;
                } else {
                    totalVal *= nums[i];
                }
            }

            // If there are two zeroes, whole vector contains zeroes
            if(zeroCnt > 1) {
                for(size_t i = 0; i < size; i++) {
                    result.push_back(0);
                }
            } // Otherwise there are zeroes everywhere except "index"
            else {
                for(size_t i = 0; i < size; i++) {
                    if(i == index) {
                        result.push_back(totalVal);
                    } else {
                        result.push_back(0);
                    }
                }
            }
        }
        return result;
    }
};