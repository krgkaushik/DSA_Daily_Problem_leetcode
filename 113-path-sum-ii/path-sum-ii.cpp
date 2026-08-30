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
    void Helper( TreeNode* root ,  int target , vector<int>&v, vector<vector<int>>&ans , int path ){

        if( root == nullptr ){
            return ;
        }
        v.push_back( root -> val );
        path += root -> val;

        if( path == target && root -> left == nullptr && root -> right == nullptr ){
            ans.push_back(v);
        }

        Helper( root->left , target , v , ans , path );
        Helper( root -> right , target , v, ans , path);

        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>v;
        vector<vector<int>>ans;
        int path = 0;
        Helper( root , targetSum , v , ans , path);

        return ans;        
    }
};