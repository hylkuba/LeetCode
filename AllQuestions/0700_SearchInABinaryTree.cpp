#include <queue>
#include <iostream>

/**
 * @brief You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        
        bool found = false;

        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* result = nullptr;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val == val) {
                result = curr;
                break;
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* result = sol.searchBST(root, 2);

    if(result) {
        std::cout << result->val << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}