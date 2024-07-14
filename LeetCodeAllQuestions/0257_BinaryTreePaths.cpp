#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
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
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;

        if(!root) return paths;

        std::string curr = "";

        add(paths, curr, root);

        return paths;
    }

private:
    void add(std::vector<std::string> &path, std::string curr, TreeNode* head) {
        if(!head->left && !head->right) {
            curr += std::to_string(head->val);
            path.push_back(curr);
            return;
        }

        if(head->left) {
            std::string tmp = curr;
            tmp += std::to_string(head->val);
            tmp += "->";
            add(path, tmp, head->left);
        }

        if(head->right) {
            std::string tmp = curr;
            tmp += std::to_string(head->val);
            tmp += "->";
            add(path, tmp, head->right);
        }
    }
};

int main(void) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    std::vector<std::string> paths = sol.binaryTreePaths(root);
    for(auto path : paths) {
        std::cout << path << std::endl;
    }
    return 0;
}