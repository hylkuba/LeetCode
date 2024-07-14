#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int max = 0;

        for(size_t i = 0; i < candies.size(); i++) {
            if(max < candies[i]) max = candies[i];
        }

        std::vector<bool> result;
        for(size_t i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies < max) result.push_back(false);
            else result.push_back(true);
        }

        return result;
    }
};