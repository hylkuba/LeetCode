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
        if(!root) return 0;

        int max = root->val;
        int ans = 0;

        dfs(root, max, ans);

        return ans;
    }

private:
    void dfs(TreeNode* root, int max, int &ans) {
        if(!root) return;

        if(root->val >= max) {
            max = root->val;
            ans++;
        }

        dfs(root->left, max, ans);
        dfs(root->right, max, ans);
    }
};