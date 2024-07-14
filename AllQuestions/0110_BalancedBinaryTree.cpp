#include <iostream>

/**
 * @brief Given a binary tree, determine if it is 
height-balanced (A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.)


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }

        return balance(root, 0);
    }

private:
    // Loop through each node and find its maxDepth of left and right subtree
    bool balance(TreeNode* root, int currDepth) {
        if(!root) {
            return true;
        }
        
        std::pair<int, int> val = maxDepth(root, currDepth);

        // If the difference between the depth of subtrees is more than 1, then it is not balanced
        if(abs(val.first - val.second) > 1) {
            return false;
        }

        // Check for each of the left and right subtree again
        return balance(root->left, currDepth + 1) && balance(root->right, currDepth + 1);
    }

    // Returns maxDepth of left and right subtree
    std::pair<int, int> maxDepth(TreeNode* root, int currDepth) {
        int maxLeft = currDepth;
        int maxRight = currDepth;

        depth(root->left, currDepth + 1, maxLeft);
        depth(root->right, currDepth + 1, maxRight);

        return std::make_pair(maxLeft, maxRight);
    }

    // Returns the maxDepth of the tree
    void depth(TreeNode* root, int currDepth, int &maxDepth) {

        if(!root) {
            return;
        }

        // Check for possible new maxDepth
        if(currDepth > maxDepth) {
            maxDepth = currDepth;
        }

        // If there exists right subtree, check for its depth
        if(root->right) {
            depth(root->right, currDepth + 1, maxDepth);
        }

        // If there exists left subtree, check for its depth
        if(root->left) {
            depth(root->left,  currDepth + 1, maxDepth);
        }
    }
};

int main(void) {
    Solution s;
    // Constructing the tree for the array: [1,null,2,null,3]

    //                      1
    //         null                   2
    //                             null  3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    std::cout << std::boolalpha << s.isBalanced(root) << std::endl; // Expected output: true or false based on the balance check

    // Cleanup
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}