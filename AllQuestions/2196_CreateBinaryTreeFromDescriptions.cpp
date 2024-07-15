#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

/**
 * @brief You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
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
    struct Node {
        int leftVal = 0;
        int rightVal = 0;
    };

    // Store the subsequent element and its orientation (left/right) for each key-value pair.
    std::map<int, Node> m;

public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        // The last and only element will be the root node
        std::set<int> roots;
        std::set<int> children;

        // Loop through vector and store roots and childrens into sets and initalize map with key being the value of current element
        for(size_t i = 0; i < descriptions.size(); i++) {
            roots.insert(descriptions[i][0]);
            children.insert(descriptions[i][1]);

            // Right child
            if(descriptions[i][2] == 0) {
                m[descriptions[i][0]].rightVal = descriptions[i][1];
            } else {    // Left child
                m[descriptions[i][0]].leftVal = descriptions[i][1];
            }
        }

        // Find the root node by subtracting children from roots
        std::set<int> rootsMinusChildren;
        std::set_difference(roots.begin(), roots.end(), children.begin(), children.end(),
                            std::inserter(rootsMinusChildren, rootsMinusChildren.begin()));

        // Create root and its value is the remaining element in the substracted set
        TreeNode* root = new TreeNode(*rootsMinusChildren.begin());
        TreeNode* tmp = root;

        // Create Tree
        initialize(tmp);

        return root;
    }

private:
    void initialize(TreeNode* head) {
        // If current val exists in the map, check for children
        auto it = m.find(head->val);
        if(it != m.end()) {
            // If left value is another root, call recursively
            if(it->second.leftVal != 0) {
                head->left = new TreeNode(it->second.leftVal);
                initialize(head->left);
            }

            // If right value is another root, call recursively
            if(it->second.rightVal != 0) {
                head->right = new TreeNode(it->second.rightVal);
                initialize(head->right);
            }
        }
    }
};

int main(void) {
    Solution solution;
    std::vector<std::vector<int>> descriptions = {
        {85, 82, 1},
        {74, 85, 1},
        {39, 70, 0},
        {82, 38, 1},
        {74, 39, 0},
        {39, 13, 1}
    };

    TreeNode* result = solution.createBinaryTree(descriptions);

    return 0;
}