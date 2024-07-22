#include <queue>
#include <iostream>

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