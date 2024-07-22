#include <queue>
#include <iostream>

/**
 * @brief Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
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
    int maxLevelSum(TreeNode* root) {
        int max = INT_MIN;
        int lowestLvl = INT_MAX;

        std::queue<std::pair<int, TreeNode*>> q;
        q.push({1, root});

        while(!q.empty()) {
            int size = q.size();
            int currLevel = q.front().first;
            int sum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front().second;
                int level = q.front().first;
                q.pop();

                sum += curr->val;

                if(curr->left) q.push({level + 1, curr->left});
                if(curr->right) q.push({level + 1, curr->right});
            }

            if(sum > max) {
                max = sum;
                lowestLvl = currLevel;
            }
        }

        return lowestLvl;
    }
};

int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution sol;
    std::cout << sol.maxLevelSum(root) << std::endl;

    return 0;
}