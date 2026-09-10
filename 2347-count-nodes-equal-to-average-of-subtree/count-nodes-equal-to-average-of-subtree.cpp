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
    void Count( TreeNode*root , int &sum , int &Cnt ){
        if( root == nullptr ){
            return ;
        }

        sum += root -> val;
        Cnt++;

        Count( root -> left , sum ,Cnt );
        Count( root -> right , sum , Cnt  );

    }
    int averageOfSubtree(TreeNode* root) {

        if( root == nullptr ){
            return 0;
        }
        int sum = 0 ;
        int Cnt = 0; 

        Count( root , sum , Cnt );
        
        int ans = sum/Cnt;
        int result = 0;
        if( root -> val == ans ){
            result++;
        }

        if( root -> left != nullptr ){
            result +=  averageOfSubtree( root -> left );
        }
        if( root -> right != nullptr ){
            result += averageOfSubtree( root -> right );
        }
        
        return result;

        
    }
};