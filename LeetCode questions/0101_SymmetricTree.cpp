#include <iostream>

/**
 * @brief Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode* l, TreeNode* q) {
        if(l == nullptr && q == nullptr) {
            return true;
        }

        if(l == nullptr || q == nullptr) {
            return false;
        }

        if(l->val != q->val) {
            return false;
        }

        return compare(l->left, q->right) && compare(l->right, q->left);
    }
};

int main(void) {
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    std::cout << s.isSymmetric(root) << std::endl;
    return 0;
}