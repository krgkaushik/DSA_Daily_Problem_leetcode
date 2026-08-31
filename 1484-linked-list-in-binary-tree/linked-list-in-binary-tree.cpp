class Solution {
public:

    bool match(const string &s, TreeNode* root, string &path) {

        if (root == nullptr)
            return false;

        string val = to_string(root->val);
        path += val;

        if (s == path) {
          
            return true;
        }

        if (match(s, root->left, path)) {
          
            return true;
        }

        if (match(s, root->right, path)) {
          
            return true;
        }

        path.resize(path.size() - val.size());

        return false;
    }

    bool solve(const string &s, TreeNode* root, string &path) {

        if (root == nullptr)
            return false;

        if (match(s, root, path))
            return true;

        if (solve(s, root->left, path))
            return true;

        if (solve(s, root->right, path))
            return true;

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {

        string s = "";

        while (head != nullptr) {
            s += to_string(head->val);
            head = head->next;
        }

        string path = "";

        return solve(s, root, path);
    }
};