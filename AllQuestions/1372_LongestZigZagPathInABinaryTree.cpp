#include <iostream>

/**
 * @brief You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:


Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
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
    int longest = 0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return longest;
    }

private:
    std::pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) {
            return {-1, -1};
        }
        
        // call for left subtree
        std::pair<int, int> left = dfs(root->left);
        
        // call for right subtree
        std::pair<int, int> right = dfs(root->right);
        
        int temp_max = std::max(1 + left.second, 1 + right.first);
        
        // update longest
        longest = std::max(longest, temp_max);
        
        // return res
        return {left.second + 1, right.first + 1};
    }
};

int main(void) {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->left->left->right = new TreeNode(1);
    root->right->right->right->left = new TreeNode(1);

    Solution obj;
    std::cout << obj.longestZigZag(root) << std::endl;

    return 0;
}