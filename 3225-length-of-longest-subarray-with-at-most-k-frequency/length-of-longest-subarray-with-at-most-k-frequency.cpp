class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        

        int left = 0 ;
        int ans  = 0 ;
        unordered_map<int,int>seen;

        for( int right = 0 ; right < nums.size(); right++ ){
                seen[nums[right]]++;

                while( seen[nums[right]] > k ){

                    seen[nums[left]]--;
                    left++;

                }
          ans = max( ans  , right - left + 1 );
        }
        return ans;
    }
};