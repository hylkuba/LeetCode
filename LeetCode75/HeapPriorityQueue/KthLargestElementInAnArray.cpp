#include <map>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::map<int, int> m;

        for(auto num : nums) {
            m[num]++;
        }

        int cnt = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++) {
            cnt += it->second;

            if(cnt >= k) {
                return it->first;
            }
        }

        return 0;
    }
};