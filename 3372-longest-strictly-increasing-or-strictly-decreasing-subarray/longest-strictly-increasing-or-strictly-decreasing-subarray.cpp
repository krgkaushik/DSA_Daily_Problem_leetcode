class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int a = 1;
        int n = nums.size();
        int b = 1;
        int ans = 1;
        for( int i =1; i<n; i++ ){
            if( nums[i-1] < nums[i] ){
             a++;
             ans = max(ans,a);
            }
            else{
                a = 1;
            }

            if( nums[i-1] > nums[i] ){
                b++;
                ans = max(b,ans);
            }
            else{
                b = 1;
            }
        }

        return ans;
    }
};