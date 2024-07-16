#include <iostream>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int size = nums.size();

        if(size <= 1) return 0;

        int longest = 0;
        int currLongest = 0;
        bool removed = false;
        int prevRemoved = -1;

        for(int i = 0; i < size; i++) {
            if(nums[i] == 1) {
                currLongest++;
            } else {

                // If we have already removed one zero, set the distance starting from previosly removed index
                if(removed) {
                    longest = std::max(longest, currLongest);
                    currLongest = i - prevRemoved - 1;
                }

                prevRemoved = i;
                removed = true;
            }
        }

        longest = std::max(longest, currLongest);

        return removed ? longest : longest - 1;
    }
};