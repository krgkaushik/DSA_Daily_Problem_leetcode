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
    vector<vector<int>> levelOrder(TreeNode* root) {   

        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;
        if( root == NULL ){
            return v;
        }

        while( q.size() > 0 ){
            vector<int>c;
            int n = q.size();
            for( int i = 0; i<n;i++ ){

            TreeNode*curr = q.front();

            q.pop();
            c.push_back(curr->val);
            if( curr -> left != NULL ){

            q.push(curr->left);
            }
            if( curr -> right != NULL ){
                q.push( curr -> right );
            }
            }
            v.push_back(c);
        }
        return v;
      
        
    }
};