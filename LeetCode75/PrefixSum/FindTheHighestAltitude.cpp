#include <vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int max = 0;
        int curr = 0;

        for(int i = 0; i < gain.size(); i++) {
            curr += gain[i];
            
            max = std::max(max, curr);
        }

        return max;
    }
};