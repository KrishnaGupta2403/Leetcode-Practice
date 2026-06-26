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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> curr;
        int lvl=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(lvl%2){
                    curr.push_back(node);
                }
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            if(lvl%2){
                int l=0,r=curr.size()-1;
                while(l<r){
                    swap(curr[l]->val,curr[r]->val);
                    l++;r--;
                }
            }
            curr.clear();
            lvl++;
        }
        return root;
    }
};