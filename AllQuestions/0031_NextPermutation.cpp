#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
 * 
 */

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i = nums.size() - 1;

        // Find the first decreasing element from the end
        while(i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        // If such an element is found (i > 0), find the largest element to the right of i - 1 that is greater than nums[i - 1]
        // Once found, swap them
        if(i > 0) {
            int j = nums.size() - 1;
            
            while(j >= i && nums[j] <= nums[i - 1]) {
                j--;
            }
            swap(nums, i - 1, j);
        }

        // Reverse the elements from index i to the end of the vector to get the next permutation
        reverse(nums, i, nums.size() - 1);
    }

private:
    void swap(std::vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverse(std::vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
