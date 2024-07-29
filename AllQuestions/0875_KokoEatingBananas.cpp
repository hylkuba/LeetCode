#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to find the minimum eating speed to finish all bananas in h hours
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // Sort the piles in ascending order
        std::sort(piles.begin(), piles.end());

        int n = piles.size();
        // Initialize the left and right boundaries for binary search
        int left = 1;
        int right = piles[n - 1];

        // Perform binary search to find the minimum eating speed
        while(left < right) {
            int mid = left + (right - left) / 2;

            // Check if it is possible to eat all bananas at speed mid within h hours
            if(possible(piles, h, mid)) {
                right = mid; // Try a smaller speed
            } else {
                left = mid + 1; // Try a larger speed
            }
        }
        return left; // The minimum eating speed
    }

private:
    // Helper function to check if it is possible to eat all bananas at speed mid within h hours
    int possible(std::vector<int>& piles, int h, int mid) {
        int ans = 0;

        // Calculate the total hours needed to eat all bananas at speed mid
        for(int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            if(piles[i] % mid != 0) {
                ans++;
            }
        }

        // Return true if the total hours needed is less than or equal to h
        return ans <= h;
    }
};