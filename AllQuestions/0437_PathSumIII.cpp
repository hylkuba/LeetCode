#include <iostream>
#include <vector>

/**
 * @brief Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
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

int main(void) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 8;
    std::cout << "Number of paths: " << solution.pathSum(root, targetSum) << std::endl;

    return 0;
}