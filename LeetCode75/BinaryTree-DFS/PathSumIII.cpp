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
    long long target;
public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        target = targetSum;

        std::vector<int> path;

        dfs(root, path, result);

        return result;
    }

private:
    void dfs(TreeNode *root, std::vector<int> path, int &result) {
        if(!root) return;

        path.push_back(root->val);

        int size = path.size();
        long long sum = path[size - 1];

        if(sum == target) result++;

        for(int i = size - 2; i >= 0; i--) {
            sum += path[i];
            if(sum == target) {
                result++;
            }
        }

        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }
};