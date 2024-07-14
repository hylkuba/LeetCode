#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/**
 * @brief Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
 * 
 */

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            for(int j = i + 1; j < n; j++) {

                if((j > (i + 1)) && (nums[j] == nums[j - 1])) {
                    continue;
                }
                
                int low = j + 1;
                int high = n - 1;

                while(low < high) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[low];
                    sum += nums[high];

                    if(sum == target) {
                        ans.push_back({nums[i] , nums[j] , nums[low] , nums[high]});

                        int low = nums[low];
                        int high = nums[high];
                        
                        low++;
                        high--;

                        while(low < high and nums[low] == low) {
                            low++;
                        }

                        while(low < high and nums[high] == high) {
                            high--;
                        }
                    } else if(sum > target) {
                        high--;
                    } else {
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {2,2,2,2,2};
    int target = 8;
    std::vector<std::vector<int>> result = s.fourSum(nums, target);

    for(auto& v : result) {
        for(auto& i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}