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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int ans=0;
        q.push({root,-1});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front().first;
                int par=q.front().second;
                q.pop();

                if(curr->left){
                    if(par%2==0) // par is granparent of curr->left asn ti is child of node
                    ans+=curr->left->val;

                    q.push({curr->left,curr->val});
                }
                if(curr->right){
                    if(par%2==0)
                    ans+=curr->right->val;

                    q.push({curr->right,curr->val});
                }
            }
        }
        return ans;
    }
};