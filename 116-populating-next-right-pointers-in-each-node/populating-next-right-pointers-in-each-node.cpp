class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            Node* prev = nullptr;

            while (s > 0) {
                Node* curr = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = curr;
                }

                prev = curr;

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }

                s--;
            }

            prev->next = nullptr;
        }

        return root;
    }
};