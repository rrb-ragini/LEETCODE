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
    
    pair<TreeNode*,unsigned int>p;
    queue<pair<TreeNode*,unsigned int>>q;
    unsigned int maxi;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        q.push({root, 1});
        
        while(!q.empty()){
            int sz = q.size();
            
            unsigned int a = q.front().second;
            unsigned int b = q.back().second;
            maxi = max(maxi, b - a + 1);
            while(sz--){
                p = q.front();
                q.pop();
                if(p.first->left) q.push({p.first->left, p.second*2});
                if(p.first->right) q.push({p.first->right, p.second*2 + 1});
            }
        }
        return maxi;
    }
};