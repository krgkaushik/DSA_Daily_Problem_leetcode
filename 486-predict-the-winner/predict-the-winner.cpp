class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        if( n % 2 == 0 ){
            return true;
        }

        vector<vector<int>>dp( n , vector<int>(n , 0 ));

        for( int i = 0 ; i<n ; i++ ){
            dp[i][i] = nums[i];
        }

        for( int length = 2 ; length <= n; length++ ){

            for( int i = 0 ; i<= n - length; i++ ){
                int j = i + length - 1;

                int pickleft = nums[i] - dp[i+1][j];
                int pickright = nums[j] - dp[i][j-1];

                dp[i][j] = max(pickleft , pickright);
            }

        }

        return dp[0][n-1] >= 0;
        
    }
};