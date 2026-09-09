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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if( root == nullptr ){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        queue<TreeNode*> next;

        while( !q.empty() ){
          
            TreeNode*curr = q.front();
            ans.push_back(curr->val);

            while( !q.empty() ){
                curr = q.front();
                q.pop();

            if( curr -> right != nullptr ){
                next.push(curr -> right );
            }

            if( curr -> left != nullptr ){
                next.push(curr -> left );
            }

            }

            while( !next.empty() ){
                q.push(next.front());
                next.pop();
            }
            
        }

        return ans;
    }
};