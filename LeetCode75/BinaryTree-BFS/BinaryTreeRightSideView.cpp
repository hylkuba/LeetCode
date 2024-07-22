#include <vector>
#include <queue>
#include <map>

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