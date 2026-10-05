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
    int goodNodes(TreeNode* root) {

         queue<pair<TreeNode*, int>>pq;
         int res = 0;
         
         pq.push({root , root -> val });

         while(!pq.empty()){
            auto [ node , maxVal ] = pq.front();
            pq.pop();
            if( node -> val >= maxVal ){
                res++;
            }
            if(node->left){
                pq.push({node->left , max(node->val , maxVal )});
            }
            if(node->right){
                pq.push({node->right , max(node->val , maxVal )});
            }
         }

         return res;
        
    }
};