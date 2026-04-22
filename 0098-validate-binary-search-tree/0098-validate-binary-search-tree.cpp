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
    bool helper(TreeNode* root , long long min , long long max){
        if(!root)return true;
        if(root->val <= min || root->val >= max)return false;
        int a = helper(root->left , min  , root->val);
        int b = helper(root->right , root->val , max);
        return a&b;
    }
    bool isValidBST(TreeNode* root) {
        // 1. store inorder  -> if inorder sorted then tree is BST;
        // OR tracking max and minimum.
        return helper(root , LONG_LONG_MIN , LONG_LONG_MAX);
    }
};