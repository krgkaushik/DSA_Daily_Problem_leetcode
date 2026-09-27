/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode*create(vector<int>v , int left , int right ){
        if( left > right ){
            return NULL;
        }

        int mid = left + ( right - left )/2;

        TreeNode*root = new TreeNode(v[mid]);

        root -> left = create( v , left , mid-1 );
        root -> right = create( v , mid+1 , right );

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>v;
        ListNode*temp = head;
        while( temp != nullptr ){
           v.push_back(temp->val);
           temp = temp ->next;
        }
        int i = 0;
        int n = v.size()-1;
        return create( v , 0 , n );
        
    }
};