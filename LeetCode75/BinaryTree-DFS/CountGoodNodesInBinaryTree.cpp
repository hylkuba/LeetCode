#include <set>

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
    int goodNodes(TreeNode* root) {
        std::set<int> path;

        return dfs(root, path);
    }

private:
    int dfs(TreeNode* root, std::set<int> path) {
        if(!root) return 0;

        int luckyNumber = 0;

        auto it = path.upper_bound(root->val);
        if(it == path.end()) {
            path.insert(root->val);
            luckyNumber = 1;
        }

        return luckyNumber + dfs(root->left, path) + dfs(root->right, path);
    }
};