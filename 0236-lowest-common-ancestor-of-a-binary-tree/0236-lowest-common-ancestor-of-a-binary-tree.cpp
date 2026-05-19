/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void rootToNodePath(TreeNode* root , TreeNode* target , bool& found , vector<TreeNode* >&path){
        if(!root)return;
        path.push_back(root);
        if(root == target){
            found = true;
            return;
        }
        rootToNodePath(root->left , target , found , path);
        rootToNodePath(root->right, target , found , path);
        if(!found)path.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<TreeNode* >path1;
        vector<TreeNode* >path2;
        bool found = false;
        rootToNodePath(root, p , found , path1);
        found = false;
        rootToNodePath(root, q , found , path2);
        TreeNode* ans = root;
        
        for(int i = 0 ; i < min(path1.size() , path2.size()) ; i++){
            if(path1[i] != path2[i])break;
            ans = path1[i];
        }
        return ans;
    }
};