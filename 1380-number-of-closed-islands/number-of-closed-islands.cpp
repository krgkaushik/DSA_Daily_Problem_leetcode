class Solution {
public:
    int dfs( vector<vector<int>>&grid , int i , int j ){
        int n = grid.size();
        int m = grid[0].size();

        if( i < 0 || j < 0 || i >= n || j >= m ){
            return 0;
        }
        if( grid[i][j] == 1 ){
            return 1;
        }
        grid[i][j] = 1;
        int up = dfs(grid , i-1 , j );
        int down = dfs(grid , i+1 , j );
        int left = dfs( grid , i , j-1 );
        int right = dfs(grid , i , j+1 );

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       int cnt = 0 ;

       for( int i = 0 ; i<n; i++ ){
        for( int j = 0 ; j<m; j++ ){
            if( grid[i][j] == 0 ){
                if( dfs( grid , i , j )){
                    cnt++;
                }
            }
        }
       } 
       return cnt;
    }
};