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
    int maxi = 0;
    void longest(TreeNode* root, int left, int step){
        if(root==NULL) return;
        
        maxi = max(maxi, step);
        
        if(left == 1){
            longest(root->left, 0, 1 + step);
            longest(root->right, 1, 1);
        }
        else if(left == 0){
            longest(root->left, 0, 1);
            longest(root->right, 1, 1 + step);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        
        longest(root, 1, 0),longest(root, 0, 0);
        return maxi;
    }
};