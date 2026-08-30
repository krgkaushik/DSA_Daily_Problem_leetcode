class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int maxiVal = INT_MIN;
        int minVal = INT_MAX;
        int left = 0 ;
        int right = 0;

        for( int i = 0; i<nums.size(); i++ ){
            if( maxiVal < nums[i] ){
                maxiVal = nums[i];
                left = i;
            }
            if( minVal > nums[i] ){
                minVal = nums[i];
                right = i;
            }
        }
        if (left > right) {
             swap(left, right);
            }
        int n = nums.size();
        int ans = min(
            right+1,
            min(
                n - left , 
                (n  - right )+ (left + 1)
            )
        );

        return ans;
    }
};