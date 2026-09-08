class Solution {
public:

    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
        
        vis[i] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int g = 0;
        int n = isConnected.size();

        vector<int> vis(n, false);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                g++;

                dfs(i, isConnected, vis);
            }
        }

        return g;
    }
};