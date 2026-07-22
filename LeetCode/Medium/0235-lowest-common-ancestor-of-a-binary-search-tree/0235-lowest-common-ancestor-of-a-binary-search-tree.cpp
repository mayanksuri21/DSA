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
public:
    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) return NULL;
        if(root == p || root == q){
            ans = root;
        };

        if(p->val > q->val){
           return lowestCommonAncestor(root , q , p);
        }

        if((root->val < p->val) ) {
            return lowestCommonAncestor(root->right , p , q);
        }
        else if((root->val > q->val) ){
            return lowestCommonAncestor(root->left , p , q);
        }
        else{
            ans = root;
        }

        return ans;

        
    }
};