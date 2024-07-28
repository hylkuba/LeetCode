#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

        int n = nums1.size();

        long long ans = 0;
        long long sum = 0;

        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        std::vector<std::pair<int, int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        std::sort(v.begin(),v.end(), std::greater<>());

        int i = 0;
        int j = 0;

        while(j < n) {
            sum += v[j].second;
            pq.push(v[j].second);

            if(j - i + 1 < k) {
                j++;
            } else{
                ans = std::max(ans, sum * v[j].first);
                sum -= pq.top();
                pq.pop();
                i++;
                j++;
            }
        }

        return ans;
    }
};