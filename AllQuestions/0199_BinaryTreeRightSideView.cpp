#include <vector>
#include <iostream>
#include <queue>
#include <map>

/**
 * @brief Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    std::vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        // Perform BFS and store each layer into a map and then take the last element of each vector
        std::map<int, std::vector<int>> layers;

        std::queue<std::pair<int, TreeNode*>> q;

        q.push({0, root});
        
        while(!q.empty()) {
            TreeNode* curr = q.front().second;
            int layer = q.front().first;
            q.pop();
            

            layers[layer].push_back(curr->val);

            layer++;

            if(curr->left) q.push({layer, curr->left});
            if(curr->right) q.push({layer, curr->right});
        }

        std::vector<int> result;
        for(auto it = layers.begin(); it != layers.end(); it++) {
            result.push_back(it->second.back());
        }

        return result;
    }
};

int main(void) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    std::vector<int> result = sol.rightSideView(root);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}