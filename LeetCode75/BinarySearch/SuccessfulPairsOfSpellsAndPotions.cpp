#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        // Sort the potions
        std::sort(potions.begin(), potions.end());

        int n = potions.size();
        std::vector<int> pairs;

        for (int i = 0; i < spells.size(); i++) {
            long long temp = spells[i];

            // If the largest product is less than success, no pairs are successful
            if (temp * potions[n - 1] < success) {
                pairs.push_back(0);
                continue;
            }

            int lower = 0, higher = n - 1;

            // Binary search to find the first index where the product is >= success
            while (lower < higher) {
                int mid = lower + (higher - lower) / 2;

                if (temp * potions[mid] < success) {
                    lower = mid + 1;
                } else {
                    higher = mid;
                }
            }

            pairs.push_back(n - lower);
        }

        return pairs;
    }
};