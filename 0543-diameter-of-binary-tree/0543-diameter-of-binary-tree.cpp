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
    int calHeight(TreeNode* root, int & ans){
        if(!root)return 0;
        int left = calHeight(root->left ,  ans);
        int right = calHeight(root->right , ans);
        ans = max(left+right , ans);
        return max(left , right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        calHeight(root , ans);
        return ans;
    }
};