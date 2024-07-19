#include <iostream>

/**
 * @brief Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        
        TreeNode* resL = lowestCommonAncestor(root->left, p, q);
        TreeNode* resR = lowestCommonAncestor(root->right, p, q);
        
        if (resL && resR) {
            return root;
        } else if (resL) {
            return resL;
        } else {
            return resR;
        }
    }
};

int main(void) {
    Solution s;
    TreeNode* root = new TreeNode(3, 
                new TreeNode(5, 
                    new TreeNode(6), 
                    new TreeNode(2, 
                        new TreeNode(7), 
                        new TreeNode(4)
                    )
                ), 
                new TreeNode(1, 
                    new TreeNode(0), 
                    new TreeNode(8)
                )
            );
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* res = s.lowestCommonAncestor(root, p, q);
    std::cout << res->val << std::endl;
    return 0;
}