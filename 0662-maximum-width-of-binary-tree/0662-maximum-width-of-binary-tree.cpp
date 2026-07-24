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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long width = 0;
        queue<pair<TreeNode* , unsigned long long>>q;
        q.push({root , 0});
        while (!q.empty())
        {
            int N = q.size();
            unsigned long long min_idx = q.front().second;
            unsigned long long st = 0, end = 0;
            for (int i = 0; i < N; i++) {
                auto [node, idx] = q.front();

                q.pop();

                unsigned long long curr_idx = idx - min_idx;

                if (i == 0) st = curr_idx;
                if (i == N - 1) end = curr_idx;

                if(node ->left)q.push({node->left , 2* idx + 1});
                if(node ->right)q.push({node->right , 2* idx + 2});
            }
            width = max(width , end-st+1);
        }
        return (int) width;
    }
};