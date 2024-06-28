#include <iostream>
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
    std::vector<int> postorderTraversal(TreeNode* root) {
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

        if(curr->left != nullptr) {
            add(curr->left, result);
        }

        if(curr->right != nullptr) {
            add(curr->right, result);
        }

        result.push_back(curr->val);
    }
};

int main(void) {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::vector<int> result = solution.postorderTraversal(root);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}