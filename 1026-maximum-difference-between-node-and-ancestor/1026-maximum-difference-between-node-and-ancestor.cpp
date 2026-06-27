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
int ans;
void findmaxutil(TreeNode* root, TreeNode* child){
    if(root==NULL || child==NULL)
    return; 

    ans=max(ans,abs(root->val-child->val));
    findmaxutil(root,child->left);
    findmaxutil(root,child->right);
}
void findmax(TreeNode* root){
    if(root==NULL)
    return;

    findmaxutil(root,root->left);
    findmaxutil(root,root->right);

    findmax(root->left);
    findmax(root->right);
}
    int maxAncestorDiff(TreeNode* root) {
        ans=-1;
        findmax(root);
        return ans;
    }
};