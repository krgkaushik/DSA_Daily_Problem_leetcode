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

    bool helper( TreeNode* root, int target , int path ){
        if( root == nullptr ){
            return false;
        }
        path+=root -> val;
        if( path == target && root->left == nullptr && root -> right == nullptr){
            return true;
        }

        if(helper( root -> left , target , path )){
            return true;
        };
        if(helper( root -> right , target ,  path )){
            return true;
        };
      return false;
        

        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(helper( root , targetSum , 0 )){
        return true;
       };

       return false;
    }
};