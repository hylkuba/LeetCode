#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        // Sort the potions
        std::sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();

        std::vector<int> pairs(n);

        for (int i = 0; i < n; i++) {
            long long temp = spells[i];

            // If the largest product is less than success, no pairs are successful
            if (temp * potions[m - 1] < success) {
                pairs[i] = 0;
                continue;
            }

            int lower = 0, higher = m - 1;

            // Binary search to find the first index where the product is >= success
            while (lower < higher) {
                int mid = lower + (higher - lower) / 2;

                if (temp * potions[mid] < success) {
                    lower = mid + 1;
                } else {
                    higher = mid;
                }
            }

            pairs[i] = m - lower;
        }

        return pairs;
    }
};