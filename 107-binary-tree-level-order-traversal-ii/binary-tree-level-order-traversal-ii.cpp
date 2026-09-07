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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> st;
       if (root == nullptr)
            return st;

queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {

    int size = q.size();
    vector<int> v;

    for (int i = 0; i < size; i++) {

        TreeNode* curr = q.front();
        q.pop();

        v.push_back(curr->val);

        if (curr->left != nullptr)
            q.push(curr->left);

        if (curr->right != nullptr)
            q.push(curr->right);
    }

    st.push_back(v);
}
        vector<vector<int>>ans;
        while( st.size() > 0 ){
           vector<int>k = st.back();
           ans.push_back(k);
           st.pop_back();
        }

        return ans;
        
    }
};