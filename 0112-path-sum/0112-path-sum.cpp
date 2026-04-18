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
    bool ans = false;
    void helper(TreeNode* root , int target , int  &sum){
        if(!root)return;
        sum+= root->val;
        if(root->left == NULL && root->right == NULL && sum == target){
            ans = true;
            return;
        }
         helper(root->left , target , sum);
         helper(root->right , target , sum);
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        int sum = 0;
        helper(root , targetSum , sum);
        return ans;
    }
};