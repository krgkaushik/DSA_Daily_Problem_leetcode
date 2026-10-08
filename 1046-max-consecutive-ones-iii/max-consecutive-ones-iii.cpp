class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int ZeroCount = 0;
        int ans = 0;

        for( int j = 0; j < nums.size(); j++ ){
            if( nums[j] == 0  ){
                ZeroCount++;
            }

            while( ZeroCount > k ){
                if(nums[i] == 0){
                    ZeroCount--;
                }
                i++;
            }

            ans =  max( ans , j - i + 1 );
        }
        return ans;
    } 
};