#include <iostream>
#include <vector>

/**
 * @brief Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?


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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(root == nullptr) {
            return result;
        }

        add(root, result);

        return result;
    }

private:
    void add(TreeNode* curr, std::vector<int> &result) {
        
        if(curr == nullptr) {
            return;
        }

        result.push_back(curr->val);

        if(curr->left != nullptr) {
            add(curr->left, result);
        }

        if(curr->right != nullptr) {
            add(curr->right, result);
        }
    }
};

int main(void) {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::vector<int> result = solution.preorderTraversal(root);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}