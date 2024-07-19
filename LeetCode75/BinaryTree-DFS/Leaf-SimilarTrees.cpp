#include <vector>

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> v1, v2;

        dfs(root1, v1);
        dfs(root2, v2);

        return v1 == v2;
    }

private:
    void dfs(TreeNode* root, std::vector<int>& v) {
        if(!root) return;

        if(!root->left && !root->right) {
            v.push_back(root->val);
        }

        dfs(root->left, v);
        dfs(root->right, v);
    }
};