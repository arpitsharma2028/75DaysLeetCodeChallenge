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
    void levelOrder(TreeNode* root , vector<int>&ans){
        if(!root)return;
        queue<TreeNode*>q;
        q.push(root);
        int lastVal = root->val;
        while(!q.empty())
        {
            int N = q.size();
            while(N--){
            TreeNode* curr = q.front();
                lastVal = curr->val;
                q.pop();
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            ans.push_back(lastVal);
        }
    }
    /*
    perform level order with level tracing
    add last element of each level in ans;
    */
    vector<int> rightSideView(TreeNode* root) {
        vector<int>val;
        levelOrder(root , val);
        return val;
    }
};