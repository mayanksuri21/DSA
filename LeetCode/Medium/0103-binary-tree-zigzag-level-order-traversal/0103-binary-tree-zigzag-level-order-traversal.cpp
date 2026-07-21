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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == NULL) return {};
        bool leftToRight = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>res;


        while(!q.empty()){
            int lvlsize = q.size();
            int first = 0;
            int last = lvlsize -1;
            vector<int>tmp(lvlsize);
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();

                if(leftToRight == 1){
                    tmp[first] = t->val;
                    first++;
                }
                else{
                    tmp[last] = t->val;
                    last--;
                }
                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
                
            }
            leftToRight =  1-leftToRight; // swap 
            res.push_back(tmp);
        }

        return res;

        
    }
};