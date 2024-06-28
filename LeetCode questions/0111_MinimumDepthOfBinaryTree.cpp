#include <iostream>

/**
 * @brief Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
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
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        } else if(!root->left && !root->right) {
            return 1;
        }

        int minDepthValue = INT_MAX;

        // Check that Root has left and right child
        if(root->left && root->right) {
            dig(root, 0, minDepthValue);
        } else if(!root->left) {
            dig(root->right, 1, minDepthValue);
        } else if(!root->right) {
            dig(root->left, 1, minDepthValue);
        } else {
            return 1;
        }

        return minDepthValue;
    }

private:
    void dig(TreeNode* root, int currentDepth, int &minDepthValue) {
        if(!root) {
            return;
        }

        currentDepth++;

        if(!root->left && !root->right) {
            minDepthValue = std::min(minDepthValue, currentDepth);
            return;
        }

        dig(root->left, currentDepth, minDepthValue);
        dig(root->right, currentDepth, minDepthValue);
    }
};

int main(void) {
    Solution s;
    TreeNode* root = new TreeNode(0);

    std::cout << s.minDepth(root);

    // Cleanup
    delete root;

    return 0;
}