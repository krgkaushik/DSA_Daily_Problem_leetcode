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
    int postorder( TreeNode*root , int &ans ){
        if( root == nullptr ){
            return 0;
        }
        int leftH = postorder( root ->left , ans );
        int rightH = postorder( root -> right , ans);

        int lh = max( 0 , leftH );
        int rh = max( 0 , rightH );

        int curr = root -> val + lh + rh;
        ans = max( ans , curr );
        return root->val + max(lh , rh);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        postorder(root , ans );

        return ans;


        
    }
};