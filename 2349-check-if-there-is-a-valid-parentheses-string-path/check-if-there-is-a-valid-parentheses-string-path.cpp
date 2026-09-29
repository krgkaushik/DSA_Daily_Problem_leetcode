class Solution {
public:

    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {

        if(i >= m || j >= n)
            return false;

        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        if(balance < 0)
            return false;

        int remaining = (m - i - 1) + (n - j - 1);

        if(balance > remaining)
            return false;

        if((remaining - balance) % 2 != 0)
            return false;

        if(i == m - 1 && j == n - 1)
            return balance == 0;

        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = solve(i + 1, j, balance, grid);

        if(down)
            return dp[i][j][balance] = true;

        bool right = solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int length = m + n - 1;

        if(length % 2 != 0)
            return false;

        if(grid[0][0] == ')')
            return false;

        if(grid[m - 1][n - 1] == '(')
            return false;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return solve(0, 0, 0, grid);
    }
};