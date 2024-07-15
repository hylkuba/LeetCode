#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double max = 0.0;

        // Initialize prevSum and average max
        for(int i = 0; i < k; i++) {
            max += nums[i];
        }
        int prevSum = max;
        max /= k;

        // Add to previous sum new element and subtract the first element
        int size = nums.size();
        for(int i = k; i < size; i++) {
            double average = 0;

            prevSum += nums[i];
            prevSum -= nums[i - k];

            average = prevSum;
            average /= k;

            if(average > max) {
                max = average;
            }
        }

        return max;
    }
};