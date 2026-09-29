/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        deque<TreeNode*>prevNode;
        prevNode.push_back(root);
        while(!prevNode.empty()){
            TreeNode* node = prevNode.back();
            prevNode.pop_back();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left != nullptr) prevNode.push_back(node->left);
            if(node->right != nullptr) prevNode.push_back(node->right);
        }
        return root;
    }
};