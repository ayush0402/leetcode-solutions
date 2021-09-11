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
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if (root->left != NULL) {
            struct TreeNode* temp = root->right;
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
            while (root->right != NULL) {
                root = root->right;
            }
            root->right = temp;
        }
        flatten(root->right);
    }
};