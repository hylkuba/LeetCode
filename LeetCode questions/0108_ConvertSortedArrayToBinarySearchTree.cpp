#include <iostream>
#include <vector>

/**
 * @brief Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        TreeNode* root = func(nums, 0, nums.size() - 1);
        return root;
    }

private:
    TreeNode* func(std::vector<int>& nums, int l, int r){
        if (l > r) {
            return nullptr;
        }
        
        int center = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[center]);

        root->left = func(nums, l, center - 1);
        root->right = func(nums, center + 1, r);

        return root;
    }
};

int main(void) {
    Solution s;
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = s.sortedArrayToBST(nums);
    return 0;
}