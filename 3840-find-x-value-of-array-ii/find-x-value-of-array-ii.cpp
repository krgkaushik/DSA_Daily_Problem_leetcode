class Solution {
public:
    struct Node {
        int prod = 1;
        array<int, 5> cnt{0, 0, 0, 0, 0};
    };

    int k;
    int n;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int value) {
        Node res;

        int rem = value % k;

        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    void update(int pos, int value) {
        pos += n;

        tree[pos] = makeNode(value);

        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }

    Node query(int l, int r) {
        l += n;
        r += n;

        Node leftResult;
        Node rightResult;

        bool hasLeft = false;
        bool hasRight = false;

        while (l <= r) {
            if (l % 2 == 1) {
                if (!hasLeft) {
                    leftResult = tree[l];
                    hasLeft = true;
                } else {
                    leftResult = merge(leftResult, tree[l]);
                }
                l++;
            }

            if (r % 2 == 0) {
                if (!hasRight) {
                    rightResult = tree[r];
                    hasRight = true;
                } else {
                    rightResult = merge(tree[r], rightResult);
                }
                r--;
            }

            l /= 2;
            r /= 2;
        }

        if (!hasLeft) return rightResult;
        if (!hasRight) return leftResult;

        return merge(leftResult, rightResult);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        k = K;
        n = nums.size();

        tree.resize(2 * n);

        for (int i = 0; i < n; i++) {
            tree[n + i] = makeNode(nums[i]);
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node res = query(start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};