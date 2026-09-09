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


        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        if( root == nullptr ){
            return ans;
        }

        int flag = 0;

        while(!q.empty()){
            vector<int>v;
            int n = q.size();

            for( int i = 0; i<n; i++ ){
                TreeNode* curr = q.front();
                q.pop();

                v.push_back(curr -> val);

                if( curr -> left != nullptr ){
                    q.push(curr->left);
                }
                if( curr -> right != nullptr ){
                    q.push( curr -> right );
                }
            }

            if( flag == 1 ){
                reverse(v.begin() , v.end() );

            }

            ans.push_back(v);

            flag = 1 - flag;
        }

        return ans;
        
    }
};