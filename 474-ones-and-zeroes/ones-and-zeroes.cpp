class Solution {
public:
    vector<vector<vector<int>>>dp;
    void countZeros( int i , vector<string>&strs , int &zeros , int &ones ){
            zeros = 0;
            ones = 0;
             for( char ch : strs[i] ){
                if( ch == '1'){
                  ones++;
                }
                else{
                    zeros++;
                }
             }
             
    }
    int Recur( int i , vector<string>&strs , int m  , int n ){
     
            if( i >= strs.size() ){
                return 0;
            }
            if( dp[i][m][n] != -1 ){
                return dp[i][m][n];
            }
             int zeros = 0;
             int ones = 0;

            countZeros(i , strs , zeros,ones);
             int a = 0;
            if( zeros <= m && ones <= n ){
               a = 1 + Recur( i + 1 , strs , m-zeros , n - ones );
            }
        
               int b = Recur( i+1 , strs , m , n );
            
            return dp[i][m][n] = max(a,b);


     }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        dp.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
       return Recur( 0 , strs , m , n  );
    }
};