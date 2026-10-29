#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
    int timer;
    int LOGN;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, tin, tout, bit;

    void dfs(int u, int p, int d) {
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOGN; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOGN - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    void bit_update(int idx, int val, int n) {
        for (; idx <= n + 1; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void range_update(int l, int r, int val, int n) {
        bit_update(l, val, n);
        bit_update(r + 1, val, n);
    }

    int point_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        timer = 0;
        LOGN = 17;
        
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        up.assign(n, vector<int>(LOGN, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);
        
        dfs(0, 0, 0);
        
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            range_update(tin[i], tout[i], mask, n);
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                
                int old_mask = 1 << (s[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int delta = old_mask ^ new_mask;
                
                s[u] = c;
                range_update(tin[u], tout[u], delta, n);
            } else {
                int u, v;
                ss >> u >> v;
                
                int lca = get_lca(u, v);
                int x_u = point_query(tin[u]);
                int x_v = point_query(tin[v]);
                int lca_mask = 1 << (s[lca] - 'a');
                
                int path_mask = x_u ^ x_v ^ lca_mask;
                
                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }
        
        return ans;
    }
};