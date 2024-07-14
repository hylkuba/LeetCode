#include <iostream>

/**
 * @brief Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, then they are same
        if(p == nullptr && q == nullptr) {
            return true;
        }

        // If one of them is null and the other isn't, they are different
        if(p == nullptr || q == nullptr) {
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        // Dive deeper into tree, both to the left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(void) {
    Solution s;
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    std::cout << s.isSameTree(p, q) << std::endl;
    return 0;
}