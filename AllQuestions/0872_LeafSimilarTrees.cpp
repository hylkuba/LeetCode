#include <iostream>
#include <vector>

/**
 * @brief Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
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

int main(void) {
    Solution s;
    TreeNode* root1 = new TreeNode(3, 
                new TreeNode(5, 
                    new TreeNode(6), 
                    new TreeNode(2, 
                        new TreeNode(7), 
                        new TreeNode(4, 
                            nullptr, 
                            new TreeNode(9, 
                                nullptr, 
                                new TreeNode(11, 
                                    new TreeNode(8), 
                                    new TreeNode(10)
                                )
                            )
                        )
                    )
                ), 
                new TreeNode(1)
            );
    
    TreeNode* root2 = new TreeNode(3, 
                new TreeNode(5, 
                    new TreeNode(6), 
                    new TreeNode(2, 
                        nullptr, 
                        new TreeNode(7, 
                            new TreeNode(9), 
                            new TreeNode(4)
                        )
                    )
                ), 
                new TreeNode(1, 
                    new TreeNode(9), 
                    new TreeNode(8)
                )
            );
    std::cout << s.leafSimilar(root1, root2) << std::endl;
    return 0;
}