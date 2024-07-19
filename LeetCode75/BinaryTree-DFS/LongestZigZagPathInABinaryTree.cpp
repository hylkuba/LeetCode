#include <iostream>

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