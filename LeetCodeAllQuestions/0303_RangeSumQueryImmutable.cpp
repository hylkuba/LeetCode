#include <iostream>
#include <vector>

/**
 * @brief Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
 * 
 */

class NumArray {

public:
    // Solution explanation:
    // At each index we keep the sum of all the elements from 0 to that index
    // If we want to calculate the sum between two indexes, we can just subtract the sum of the left index from the sum of the right index

    // Method to print the pre vector
    void printPre() {
        for (size_t i = 0; i < pre.size(); i++) {
            std::cout << pre[i] << (i < pre.size() - 1 ? ", " : "");
        }
        std::cout << std::endl;
    }

    NumArray(std::vector<int>& nums) {
        int n = (int)nums.size();
        pre.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            pre.push_back(pre[i - 1] + nums[i]);
        }

        // printPre();
    }

    int sumRange(int left, int right) {
        return left == 0 ? pre[right] : pre[right] - pre[left - 1];
    }

private:
    std::vector<int> pre;
};

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    std::cout << numArray.sumRange(0, 2) << std::endl;
    std::cout << numArray.sumRange(2, 5) << std::endl;
    std::cout << numArray.sumRange(0, 5) << std::endl;
    return 0;
}