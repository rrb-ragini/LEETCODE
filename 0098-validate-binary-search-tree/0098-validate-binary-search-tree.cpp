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
    bool isValid(TreeNode *root, long min, long max){
        if(root == NULL) return true;
        if(root->val <= min or root->val >= max) return false;
        
        return isValid(root->left, min, root->val) and isValid(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        return isValid(root, LONG_MIN, LONG_MAX);
        
//         bool flag = true;
//         if(root->left!=NULL){
//             if(root->val > root->left->val) flag = isValidBST(root->left);
//             else flag = false;
//         }
        
//         if(root->right!=NULL){
//             if(root->val < root->right->val) flag = isValidBST(root->right);
//             else flag = false;
        // }
        // return flag;
    }
};